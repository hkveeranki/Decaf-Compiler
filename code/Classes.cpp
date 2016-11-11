#include <bits/stdc++.h>

#include "ClassDefs.h"

using namespace std;
using namespace llvm;

#define TBS printTabs()
#define outs(x)cout<<#x<<" is "<<x<<endl
ofstream out("XML_Vistor.txt");
int tabs_needed = 0;
const int tab_width = 4;
extern int errors;
/* Usefull Variables */
static Module *TheModule = new Module("Decaf compiler jit",llvm::getGlobalContext());
static LLVMContext &Context = getGlobalContext();
static IRBuilder<> Builder(Context);
static std::map<std::string, llvm::AllocaInst *> NamedValues;
static FunctionPassManager *TheFPM;

/* Usefull Functions */

static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const std::string &VarName, string type) {
  /* Allocates memory for local variables  on the stack of the function */

  /* Get the builder for current context */
  IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  AllocaInst* Alloca;
  if(type == "int"){
    Alloca = TmpB.CreateAlloca(Type::getInt32Ty(getGlobalContext()), 0, VarName.c_str());
  }
  else if (type == "boolean"){
    Alloca = TmpB.CreateAlloca(Type::getInt1Ty(getGlobalContext()), 0, VarName.c_str());
  }
  return Alloca;
}

string getOperation(string opr){
  if(opr.compare("+") == 0){
    return string("Addition");
  }
  else if (opr.compare("-") == 0){
    return string("Subtraction");
  }
  else if(opr.compare("*")  == 0){
    return string("Multiplication");
  }
  else if (opr.compare("/")  == 0){
    return string("Division");
  }
  else if (opr.compare("%") == 0){
    return string("Modulus");
  }
  else if (opr.compare("<") == 0){
    return string("Less_than");
  }
  else if (opr.compare(">") == 0){
    return string("Greater_than");
  }
  else if (opr.compare("<=") == 0){
    return string("Less_than_Equal_to");
  }
  else if (opr.compare(">=") == 0){
    return string("Greater_than_Equal_to");
  }
  else if (opr.compare("==") == 0){
    return string("Compare_equal");
  }
  else if (opr.compare("&&") == 0){
    return string("Conditional_and");
  }
  else if (opr.compare("||") == 0){
    return string("Conditional_or");
  }
  else if (opr.compare("=") == 0){
    return string("Equal_assign");
  }
  else if (opr.compare("-=") == 0){
    return string("Subequal_assign");
  }
  else if (opr.compare("=") == 0){
    return string("Addequal_assign");
  }
}

void printTabs(){
  for(int i = 0; i < tabs_needed; i++){
    for(int j = 0; j < tab_width; j++)
    out << " ";
  }
}

/* --------------------- Constructors ---------------------*/
Var::Var(string declType, string name, unsigned int length){
  this->declType = declType;
  this->name = name;
  this->length = length;
}

Var::Var(string declType, string name){
  this->declType = declType;
  this->name = name;
}

fieldDecl::fieldDecl(string dataType, class Vars* vars){
  this->dataType = dataType;
  this->var_list = vars->getVarsList();
  for(int i = 0; i < var_list.size(); i++){
    var_list[i]->setDataType(dataType);
  }
}

fieldDecls::fieldDecls(){
  this->cnt = 0;
}

EnclExpr::EnclExpr(class Expr* expr){
  this->expr = expr;
  this->etype = exprType::enclExpr;
}

calloutCall::calloutCall(string method_name, class calloutArgs* args){
  this->method_name = method_name.substr(1,method_name.length()-2);
  this->args = args;
}

Method::Method(string method_name, class Params* params){
  this->method_name = method_name;
  this->params = params;
}

Params::Params(){
  this->cnt = 0;
}

calloutArgs::calloutArgs(){
  this->cnt = 0;
}

calloutArg::calloutArg(class Expr* arg){
  this->expr = arg;
}

calloutArg::calloutArg(string literal){
  class stringLiteral* tmp = new stringLiteral(literal);
  this->expr = tmp;
}

unExpr::unExpr(string opr, class Expr* expr){
  this->opr = opr;
  this->body = expr;
  this->etype = exprType::Unexpr;
}

binExpr::binExpr(class Expr* lhs, string opr, class Expr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
  this->etype = exprType::binary;
}

Location::Location(string var, string location_type, class Expr* expr){
  this->var = var;
  this->location_type = location_type;
  this->expr = expr;
  this->etype = exprType::location;
}

Location::Location(string var, string location_type){
  this->var = var;
  this->location_type = location_type;
  this->etype = exprType::location;
}

intLiteral::intLiteral(int value){
  this->value = value;
  this->ltype = literalType::Int;
}

boolLiteral::boolLiteral(string value){
  this->value = value;
  this->ltype = literalType::Bool;
}

charLiteral::charLiteral(string val){
  this->value = val[0];
  this->ltype = literalType::Char;
}

stringLiteral::stringLiteral(string val){
  this->value = val;
  this->ltype = literalType::String;
}

Stmts::Stmts(){
  this->cnt = 0;
}

Assignment::Assignment(class Location* loc, string oper, class Expr* expr){
  this->loc = loc;
  this->opr = oper;
  this->expr = expr;
}

Block::Block(class varDecls* vars, class Stmts* stmts){
  this->decls_list = vars;
  this->stmts_list = stmts;
}

varDecl::varDecl(string data_type,class stringList* list){
  vector<string> tmp = list->getList();
  this->type = data_type;
  this->cnt = 0;
  for(int i = 0; i < tmp.size(); i++){
    this->push_back(tmp[i]);
  }
}

varDecls::varDecls(){
  this->cnt = 0;
}

forStmt::forStmt(string loc, class Expr* init, class Expr* cond, class Block* block){
  this->var = loc;
  this->init = init;
  this->condition = cond;
  this->body = block;
}

ifElseStmt::ifElseStmt(class Expr* cond, class Block* block1, class Block* block2){
  this->condition = cond;
  this->if_block = block1;
  this->else_block = block1;
}

returnStmt::returnStmt(class Expr* expr){
  this->ret = expr;
}

methodDecl::methodDecl(string ret_type, string name, class methodArgs* args, class Block* block){
  this->type = ret_type;
  this->name = name;
  this->arg_list = args;
  this->body = block;
}

methodDecls::methodDecls(){
  this->cnt = 0;
}

methodArgs::methodArgs(){
  this->cnt = 0;
}

methodArg::methodArg(string type, string name){
  this->type = type;
  this->name = name;
}

Prog::Prog(string name, class fieldDecls* decls, class methodDecls* methods){
  this->methods = methods;
  this->name = name;
  this->fields = decls;
}

/* --------------------- Methods --------------------- */

bool Var::isArray(){
  return (declType.compare("Array") == 0);
}

void Var::setDataType(string datatype){
  /* Sets the data type for the variable */
  this->dataType = datatype;
}

string Var::getName(){
  return name;
}

vector<class Var*> Vars::getVarsList(){
  return vars_list;
}

void Vars::push_back(class Var* var){
  vars_list.push_back(var);
  cnt++;
}

vector<class Var*> fieldDecl::getVarsList(){
  return var_list;
}

void fieldDecls::push_back(class fieldDecl* var){
  decl_list.push_back(var);
  cnt++;
}

void calloutArgs::push_back(class calloutArg* arg){
  args_list.push_back(arg);
  cnt++;
}

vector<class calloutArg*> calloutArgs::getArgsList(){
  return args_list;
}

vector<class Expr*> Params::getExprList(){
  return expr_list;
}

string methodArg::getName(){
  return name;
}

string methodArg::getType(){
  return type;
}

int intLiteral::getValue(){
  return value;
}

string intLiteral::toString(){
  return to_string(value);
}

string boolLiteral::toString(){
  return value;
}

string Location::getVar(){
  return var;
}

bool Location::is_array(){
  return location_type.compare("Array") == 0;
}

class Expr* Location::getExpr(){
  return expr;
}

void Stmts::push_back(class Stmt* stmt){
  stmts.push_back(stmt);
  cnt++;
}

void varDecl::push_back(string var){
  var_list.push_back(var);
  cnt++;
}

void varDecls::push_back(class varDecl* decl){
  decl_list.push_back(decl);
  cnt++;
}

void methodDecls::push_back(class methodDecl* decl){
  decl_list.push_back(decl);
  cnt++;
}

vector<class methodArg*> methodArgs::getArgList(){
  return arg_list;
}


void stringList::push_back(string var){
  list.push_back(var);
}

void Params::push_back(class Expr* expr){
  expr_list.push_back(expr);
  cnt++;
}

void methodArgs::push_back(class methodArg* arg){
  arg_list.push_back(arg);
  this->cnt++;
}

vector<string> stringList::getList(){
  return this->list;
}

/* --------------------- Code Generators ---------------------*/

Value* fieldDecl::codegen(){
  llvm::Type *ty;
  if(dataType == "int"){
    ty = Type::getInt32Ty(Context);
  }
  else if(dataType == "boolean"){
    ty = Type::getInt1Ty(Context);
  }
  else{
    /* Not a valid Type so Raise an error */
    errors++;
    return reportError::ErrorV("Invalid Data Type for the field declaration");
  }
  for(int i = 0; i < var_list.size(); i++){
    /* Allocate one location of global variable for all */
    class Var* var = var_list[i];
    if(var->isArray()){
      PointerType* PointerTy_1 = PointerType::getUnqual(llvm::ArrayType::get(ty,var->getLength()));
      GlobalVariable* gv = new GlobalVariable(*TheModule,PointerTy_1,false,GlobalValue::CommonLinkage,0,var->getName());
    }
    else{
      GlobalVariable* gv = new GlobalVariable(*TheModule, ty, false,GlobalValue::CommonLinkage, 0, var->getName());
    }
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return v;
}

Value* fieldDecls::codegen(){
  for(int i = 0; i < decl_list.size(); i++){
    decl_list[i]->codegen();
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return v;
}

Value* EnclExpr::codegen(){
  return expr->codegen();
}

Value* unExpr::codegen(){
  Value* v = body->codegen();
  if(opr == "-"){
    return Builder.CreateNeg(v,"negtmp");
  }
  else if (opr == "!"){
    return Builder.CreateNot(v,"nottmp");
  }
}

Value* binExpr::codegen(){
  Value* left = lhs->codegen();
  Value* right = rhs->codegen();
  if(left == 0){
    errors++;
    return reportError::ErrorV("Error in left operand of " + opr);
  }
  else if(right == 0){
    errors++;
    return reportError::ErrorV("Error in right operand of " + opr);
  }
  Value* v;
  if(opr == "+"){
    v = Builder.CreateAdd(left,right,"addtmp");
  }
  else if (opr == "-"){
    v = Builder.CreateSub(left,right,"subtmp");
  }
  else if (opr == "*"){
    v = Builder.CreateMul(left,right,"multmp");
  }
  else if (opr == "/"){
    v = Builder.CreateUDiv(left,right,"divtmp");
  }
  else if(opr == "%"){
    v = Builder.CreateURem(left,right,"modtmp");
  }
  else if (opr == "<"){
    v = Builder.CreateICmpULT(left,right,"ltcomparetmp");
  }
  else if (opr == ">"){
    v = Builder.CreateICmpUGT(left,right,"gtcomparetmp");
  }
  else if (opr == "<="){
    v = Builder.CreateICmpULE(left,right,"lecomparetmp");
  }
  else if (opr == ">="){
    v = Builder.CreateICmpUGE(left,right,"gecomparetmp");
  }
  else if (opr == "=="){
    v = Builder.CreateICmpEQ(left,right,"equalcomparetmp");
  }
  else if (opr == "!="){
    v = Builder.CreateICmpNE(left,right,"notequalcomparetmp");
  }
  return v;
}

Value* Location::codegen(){
  Value* index = ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32,1));
  if(this->expr != NULL){
    index = expr->codegen();
    if(index == 0){
      errors++;
      return reportError::ErrorV("Invalid array index");
    }
  }
  Value* V = NamedValues[var];
  if(V == 0){
    errors++;
    return reportError::ErrorV("Unknown Variable name " + var);
  }
  return Builder.CreateLoad(V,var);
}

Value* intLiteral::codegen(){
  Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(32,value));
  return v;
}

Value* boolLiteral::codegen(){
  bool val;
  if(value == "true") val = true;
  else if (value == "false") val = false;
  else{
    errors++;
    return reportError::ErrorV("Invalid Boolean Literal " + value);
  }
  Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(1,val));
  return v;
}

Value* Stmts::codegen(){
  Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
  for(int i = 0; i < stmts.size(); i++){
    v = stmts[i]->codegen();
  }
  return v;
}

Value* calloutCall::codegen(){
  Function* calle = TheModule->getFunction(method_name);
  if(calle == 0){
    errors++;
    return reportError::ErrorV("Unknown Function name" + method_name);
  }
  // Check if sufficient number of parameters are passed
  vector<class calloutArg*> args_list = args->getArgsList();
  if(calle->arg_size() != args_list.size()){
    errors++;
    return reportError::ErrorV("Incorrect Number of Parameters Passed");
  }
  // Add all the arguments to the function stack
  vector<Value* > Args;
  for(int i = 0; i < args_list.size(); i++){
    Args.push_back(args_list[i]->codegen());
    if(Args.back() == 0){
      // Some thing is wrong with the args passed
      return 0;
    }
  }
  Value* v = Builder.CreateCall(calle,Args,"callouttmp");
  return v;
}

Value* calloutArg::codegen(){
  if(expr == NULL){
    errors++;
    return reportError::ErrorV("Invalid Callout Arg");
  }
  return expr->codegen();
}

Value* Method::codegen(){
  Function* calle = TheModule->getFunction(method_name);
  if(calle == 0){
    errors++;
    return reportError::ErrorV("Unknown Function name" + method_name);
  }
  vector<class Expr*> args_list = params->getExprList();
  if(calle->arg_size() != args_list.size()){
    errors++;
    return reportError::ErrorV("Incorrect Number of Parameters Passed");
  }
  vector<Value* > Args;
  for(int i = 0; i < args_list.size(); i++){
    Args.push_back(args_list[i]->codegen());
    if(Args.back() == 0){
      // Some thing is wrong with the args passed
      return 0;
    }
  }
  Value* v = Builder.CreateCall(calle,Args,"methodcalltmp");
  return v;
}

Value* Assignment::codegen(){

  Value* cur = NamedValues[loc->getVar()];
  if(cur == 0){
    errors++;
    return reportError::ErrorV("Unknown Variable Name");
  }

  Value* val = expr->codegen();

  if(val == 0){
    errors++;
    return reportError::ErrorV("Error in right hand side of the Assignment");
  }


  if(opr == "+="){
    val = Builder.CreateAdd(Builder.CreateLoad(cur,loc->getVar()), val,"addEqualToTmp");
  }
  else if (opr == "-="){
    val = Builder.CreateSub(Builder.CreateLoad(cur,loc->getVar()), val,"subEqualToTmp");
  }
  if(loc->is_array()){
    /* If it is an array get the pointer */
    Value* index = loc->getExpr()->codegen();
    std::vector<llvm::Value *> tmp_args;
    tmp_args.push_back(Builder.getInt32(0));
    tmp_args.push_back(index);
    Value *cur = Builder.CreateGEP(cur, tmp_args, loc->getVar()+"_IDX");
  }
  return Builder.CreateStore(val, cur);
}

Value* Block::codegen(){
  Value* V = ConstantInt::get(getGlobalContext(),APInt(32,1));
  std::map<std::string,llvm::AllocaInst *> Old_vals;
  V = decls_list->codegen(Old_vals);
  V = stmts_list->codegen();
  /* Adjust the values back to old values */
  for(std::map<std::string,llvm::AllocaInst *>::iterator it = Old_vals.begin(); it != Old_vals.end();it++){
    NamedValues[it->first] = Old_vals[it->first];
  }
  return V;
}

Value* varDecls::codegen(map<string,llvm::AllocaInst *>& Old_vals){
  Value* v = ConstantInt::get(getGlobalContext(),APInt(32,1));
  for(int i = 0; i < decl_list.size(); i++){
    v = decl_list[i]->codegen(Old_vals);
  }
  return v;
}

Value* varDecl::codegen(map<string,llvm::AllocaInst *>& Old_vals){
  Function *TheFunction = Builder.GetInsertBlock()->getParent(); /* Get the function in which this belongs */
  for(int i = 0; i < var_list.size(); i++){
    string var = var_list[i];
    llvm::Value *initval;
    llvm::AllocaInst *Alloca;
    if(type == "int"){
      initval = ConstantInt::get(getGlobalContext(),APInt(32,0));
      Alloca = CreateEntryBlockAlloca(TheFunction,var,"int");
    }
    else if (type == "boolean"){
      initval = ConstantInt::get(getGlobalContext(),APInt(32,0));
      Alloca = CreateEntryBlockAlloca(TheFunction,var,"int");
    }
    Builder.CreateStore(initval,Alloca);
    /* Store the old value to old_vals and new value to named values */
    Old_vals[var] = NamedValues[var];
    NamedValues[var] = Alloca;
  }
  Value* v = ConstantInt::get(getGlobalContext(),APInt(32,1));
  return v;
}

Value* forStmt::codegen(){
  Value* start = init->codegen();
  if(start == 0){
    return 0;
  }
  Function *TheFunction = Builder.GetInsertBlock()->getParent();
  llvm::AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var, "int");
  Builder.CreateStore(start, Alloca);
  BasicBlock *preheaderBB = Builder.GetInsertBlock();
  BasicBlock* loop_body = BasicBlock::Create(getGlobalContext(), "loop", TheFunction);
  Builder.CreateBr(loop_body);
  Builder.SetInsertPoint(loop_body);

  PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(llvm::getGlobalContext()), 2, var);
  Variable->addIncoming(start, preheaderBB);
  /* Store the old value */
  llvm::AllocaInst *OldVal = NamedValues[var];
  NamedValues[var] = Alloca;

  if(body->codegen() == 0) {
    return 0;
  }
  Value* step_val = ConstantInt::get(getGlobalContext(),APInt(32,1));

  Value* cur = Builder.CreateLoad(Alloca, var);
  Value* nextval = Builder.CreateAdd(cur,step_val,"NextVal");
  Builder.CreateStore(nextval, Alloca);

  Value* cond = condition->codegen();
  if(cond == 0){
    errors++;
    return reportError::ErrorV("Invalid Condition");
  }

  Builder.CreateICmpULE(Variable, cond, "loopcondition");

  BasicBlock *loopEndBlock = Builder.GetInsertBlock();
  BasicBlock *afterBB = BasicBlock::Create(getGlobalContext(), "afterloop", TheFunction);
  Builder.CreateCondBr(cond, loop_body, afterBB);

  Builder.SetInsertPoint(afterBB);
  Variable->addIncoming(nextval, loopEndBlock);

  if(OldVal){
    NamedValues[var] = OldVal;
  }
  else{
    NamedValues.erase(var);
  }
  llvm::Value *V = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return V;
}

Value* ifElseStmt::codegen(){
  Value *cond = condition->codegen();
  if(cond == 0){
    errors++;
    return reportError::ErrorV("Invalid Expression in the IF");
  }
  Function* TheFunction = Builder.GetInsertBlock()->getParent();
  BasicBlock *ifBlock = BasicBlock::Create(Context, "then", TheFunction);
  BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
  BasicBlock *nextBlock = BasicBlock::Create(Context, "ifcont");
  Builder.CreateCondBr(cond, ifBlock, elseBlock);
  Builder.SetInsertPoint(ifBlock);
  Value* ifval  = if_block->codegen();
  if(ifval == 0){
    return 0;
  }

  Builder.CreateBr(nextBlock);
  ifBlock = Builder.GetInsertBlock();

  TheFunction->getBasicBlockList().push_back(elseBlock);
  Builder.SetInsertPoint(elseBlock);
  Value* elseval = else_block->codegen();
  if(elseval == 0){
    return 0;
  }
  Builder.CreateBr(nextBlock);
  elseBlock = Builder.GetInsertBlock();
  TheFunction->getBasicBlockList().push_back(nextBlock);
  Builder.SetInsertPoint(nextBlock);
  PHINode *PN = Builder.CreatePHI(Type::getInt32Ty(getGlobalContext()), 2,"iftmp");
  PN->addIncoming(ifval, ifBlock);
  PN->addIncoming(elseval, elseBlock);
  return PN;
}

Value* returnStmt::codegen(){
  llvm::Value *V;
  if(ret != NULL){
    V = ret->codegen();
    return V;
  }
  return V;
}

Value* breakStmt::codegen(){
  llvm::Value *V = llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32,1));
  return V;
}

Value* continueStmt::codegen(){
  llvm::Value *V = llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32,1));
  return V;
}

Function* methodDecl::codegen(){
  vector<string> argNames;
  vector<string> argTypes;
  vector<class methodArg*> args = arg_list->getArgList();
  vector<Type*> arguments;
  int arg_size = args.size();

  for(int i = 0; i < args.size(); i++){
    /* Iterate over the arguments and get the types of them in llvm */
    string arg_type = args[i]->getType();
    string arg_name = args[i]->getName();
    if(arg_type == "int"){
      arguments.push_back(Type::getInt32Ty(getGlobalContext()));
    }
    else if (arg_type == "boolean"){
      arguments.push_back(Type::getInt1Ty(getGlobalContext()));
    }
    else{
      errors++;
      reportError::ErrorV("Arguments can only be int or boolean");
      return 0;
    }
    argTypes.push_back(string(arg_type));
    argNames.push_back(string(arg_name));
  }

  Type *returnType;
  /* Get the return Type */
  if(type == "int"){
    returnType = Type::getInt32Ty(getGlobalContext());
  }
  else if(type == "boolean"){
    returnType = Type::getInt1Ty(getGlobalContext());
  }
  else if (type == "void"){
    returnType = Type::getVoidTy(getGlobalContext());
  }
  else{
    errors++;
    reportError::ErrorV("Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool");
    return 0;
  }

  /* Get the function type and create a Function */
  FunctionType *FT = llvm::FunctionType::get(returnType, arguments, false);
  Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, name, TheModule);

  /* Iterate through arguments and set the Names for them */

  unsigned Idx = 0;
  for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
    AI->setName(argNames[Idx]);
  }

  /* Create a New block for this Function */
  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
  Builder.SetInsertPoint(BB);
  Idx = 0;

  /* Allocate memory for the arguments passed */
  for (auto &Arg : F->args()) {
    if(Idx == arg_size){break;}
    AllocaInst *Alloca = CreateEntryBlockAlloca(F, argNames[Idx],argTypes[Idx]);
    Builder.CreateStore(&Arg, Alloca);

    NamedValues[argNames[Idx]] = Alloca;
    Idx++;
  }

  Value *RetVal = body->codegen();
  if(RetVal){
    /* make this the return value */
    Builder.CreateRet(RetVal);
    /* Verify the function */
    verifyFunction(*F);
    return F;
  }
  /* Error Condition */
  F->eraseFromParent();
  return 0;
}

Value* methodDecls::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  for(int i = 0; i < decl_list.size(); i++){
    V = decl_list[i]->codegen();
  }
  return V;
}

Value* Prog::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  V = fields->codegen();
  V = methods->codegen();
  return V;
}
void Prog::generateCode(){
  cout << "Generating LLVM IR Code\n";
  TheModule->dump();
}

/* Unused Codegens */

Value* Var::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* Vars::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* methodArg::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* methodArgs::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* Params::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* calloutArgs::codegen(){
  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}



/* --------------------- Traversals ---------------------*/

void fieldDecls::traverse(){
  TBS;
  out << "<field_declarations count=\"" << cnt << "\">\n";
  tabs_needed++;
  for (int i = 0; i < decl_list.size(); i++){
    decl_list[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</field_declarations>\n";

}

void fieldDecl::traverse(){
  for(int i = 0;  i < var_list.size(); i++){
    var_list[i]->traverse();
  }
}

void Var::traverse(){
  TBS;
  out << declType << endl;
  TBS;
  out << "<declaration name=\"" << name << "\" type=\"" << dataType << "\" ";
  if(declType.compare("Array") == 0){
    out << "size=\"" << length << "\" ";
  }
  out << "/>\n";
}

void Stmts::traverse(){
  TBS;
  out << "<statements count=\"" << cnt << "\">\n";
  tabs_needed++;
  for(int i = 0; i < stmts.size(); i++){
    stmts[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</statements>\n";
}

void Assignment::traverse(){
  TBS;
  out << "<assignment>\n";
  tabs_needed++;
  TBS;
  out << "<LHS name =\"" << loc->getVar() << "\">\n";
  if(loc->is_array()){
    tabs_needed++;
    loc->getExpr()->traverse();
    tabs_needed--;
  }
  TBS;
  out << "</LHS>\n";
  TBS;
  out << "<operation =\"" << getOperation(opr) <<"\">\n";
  TBS;
  out << "<RHS>\n";
  tabs_needed++;
  expr->traverse();
  tabs_needed--;
  TBS;
  out << "</RHS>\n";
  tabs_needed--;
  TBS;
  out << "</assignment>\n";
}

void Location::traverse(){
  TBS;
  out << "<identifier name=\"" << var << "\"";
  if(is_array()){
    out << ">\n";
    tabs_needed++;
    expr->traverse();
    tabs_needed--;
    TBS;
    out << "</identifier>\n";
  }
  else{
    out << " />\n";
  }
}

void intLiteral::traverse(){
  TBS;
  out << "<integer value=\"" << value << "\" />\n";
}

void boolLiteral::traverse(){
  TBS;
  out << "<boolean value=\"" << value << "\" />\n";
}

void charLiteral::traverse(){
  TBS;
  out << "<char value=\"" << value << "\" />\n";
}

void stringLiteral::traverse(){
  TBS;
  out << "<string value=\"" << value << "\" />\n";
}

void EnclExpr::traverse(){
  expr->traverse();
}

void binExpr::traverse(){
  TBS;
  out << "<binary_expression type=\"" << getOperation(opr) <<"\">\n";
  tabs_needed++;
  lhs->traverse();
  rhs->traverse();
  tabs_needed--;
  TBS;
  out << "</binary_expression>\n";
}

void unExpr::traverse(){
  TBS;
  string operation  = "Unary Negitive";
  if(opr == "!"){
    operation = "Unary NOT";
  }
  out << "<unary_expression type=\"" << operation <<"\">\n";
  tabs_needed++;
  body->traverse();
  tabs_needed--;
  TBS;
  out << "</unary_expression>\n";
}

void Block::traverse(){
  TBS;
  out << "<block>\n";
  tabs_needed++;
  decls_list->traverse();
  stmts_list->traverse();
  tabs_needed--;
  TBS;
  out << "</block>\n";
}

void varDecls::traverse(){
  TBS;
  out << "<variable_declarations count=\"" << cnt << "\">\n";
  tabs_needed++;
  for(int i = 0; i < decl_list.size(); i++){
    decl_list[i]->traverse();
  }
  tabs_needed--;
}

void varDecl::traverse(){
  TBS;
  out << "<declaration type=\"" << type << "\">\n";
  tabs_needed++;
  for(int i = 0; i < var_list.size(); i++){
    TBS;
    out << "<variable name=\"" << var_list[i] << "\">\n";
  }
  tabs_needed--;
}

void forStmt::traverse(){
  TBS;
  out << "<for_statement>\n";
  tabs_needed++;
  TBS;
  out << "<initialisation>\n";
  tabs_needed++;
  TBS;
  out << "<variable name=\"" << var << "\" />\n";
  init->traverse();
  tabs_needed--;
  TBS;
  out << "</initialisation>\n";
  TBS;
  out << "<condition>\n";
  tabs_needed++;
  condition->traverse();
  tabs_needed--;
  TBS;
  out << "</condition>\n";
  tabs_needed++;
  body->traverse();
  tabs_needed--;
  tabs_needed--;
  TBS;
  out << "</for_statement>\n";
}

void ifElseStmt::traverse(){
  TBS;
  out << "<if_else_statement>\n";
  tabs_needed++;
  TBS;
  out << "<condition>\n";
  tabs_needed++;
  condition->traverse();
  tabs_needed--;
  TBS;
  out << "</condition>\n";
  TBS;
  out << "<ifblock>\n";
  tabs_needed++;
  if_block->traverse();
  tabs_needed--;
  TBS;
  out << "</ifblock>\n";
  if(else_block!=NULL){
    TBS;
    out << "<else_block>\n";
    tabs_needed++;
    else_block->traverse();
    tabs_needed--;
    TBS;
    out << "</elseblock>\n";
  }
  tabs_needed--;
  TBS;
  out << "</if_else_statement>\n";
}

void breakStmt::traverse(){
  TBS;
  out << "<break_statement />\n";
}


void continueStmt::traverse(){
  TBS;
  out << "<continue_statement />\n";
}

void returnStmt::traverse(){
  TBS;
  if(ret == NULL){
    out << "<return_statement />\n";
    return ;
  }
  out << "<return_statement>\n";
  tabs_needed++;
  ret->traverse();
  tabs_needed--;
  TBS;
  out << "</return_statement>\n";

}

void calloutCall::traverse(){
  TBS;
  out << "<callout function=\"" << method_name << "\">\n";
  args->traverse();
  TBS;
  out << "</callout>\n";

}

void calloutArgs::traverse(){
  for(int i = 0; i < args_list.size(); i++){
    args_list[i]->traverse();
  }
}

void calloutArg::traverse(){
  tabs_needed++;
  expr->traverse();
  tabs_needed--;
}

void Method::traverse(){
  TBS;
  out << "<method_call function=\"" << method_name << "\">\n";
  tabs_needed++;
  params->traverse();
  tabs_needed--;
  TBS;
  out << "</method_call>\n";
}

void Params::traverse(){
  for(int i = 0; i < expr_list.size(); i++){
    tabs_needed++;
    expr_list[i]->traverse();
    tabs_needed--;
  }
}

void methodArgs::traverse(){
  TBS;
  out << "<method_args count=\"" << cnt << "\">\n";
  tabs_needed++;
  for(int i = 0; i < arg_list.size(); i++){
    arg_list[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</method_args>\n";
}

void methodArg::traverse(){
  TBS;
  out << "<method_arg name=\"" << name << "\" type=\"" << type << "\" />\n";
}

void methodDecl::traverse(){
  TBS;
  out << "<method_declaration return_type=\"" << type << " name=\""<< name << "\">\n";
  tabs_needed++;
  arg_list->traverse();
  body->traverse();
  tabs_needed--;
  TBS;
  out << "</method_declaration>\n";
}

void methodDecls::traverse(){
  TBS;
  out << "<method_declarations count=\"" << cnt << "\">\n";
  tabs_needed++;
  for (int i = 0; i < decl_list.size(); i++){
    decl_list[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</method_declarations>\n";

}

void Prog::traverse(){
  TBS;
  out << "<program>\n";
  tabs_needed++;
  fields->traverse();
  methods->traverse();
  tabs_needed--;
  TBS;
  out << "</program>\n";
}
