#include <bits/stdc++.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
//#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/IRBuilder.h>
//#include <llvm/ModuleProvider.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>

using namespace std;
using namespace llvm;

enum exprType { binary = 1, location = 2, literal = 3, enclExpr = 4 , Unexpr = 5};
enum literalType { Int = 1, Bool = 2, Char = 3, String = 4 };
enum stmtType { Return = 1, NonReturn = 2};
union Node{
	int number;
	char* value;
	class Prog* prog;
	class fieldDecls* fields;
	class fieldDecl* field;
	class Vars* vars;
	class Var* var;
	class methodDecls* methods;
	class methodDecl* method;
	class Block* block;
	class varDecls* var_decls;
	class varDecl* var_decl;
	class Stmts* stmts;
	class Stmt* stmt;
	class Expr* expr;
	class calloutArg* callout_arg;
	class calloutArgs* callout_args;
	class Params* parameters;
	class methodArgs* method_args;
	class methodArg* method_arg;
	class methodCall* method_call;
	class Location* location;
	class Assignment* assignment;
	class Literal* literal;
	class stringList* mylist;

	Node(){
		number = 0;
		value = NULL;
		fields = NULL;
		field = NULL;
		methods = NULL;
		method = NULL;
		var_decls = NULL;
		stmts = NULL;
		callout_args = NULL;
		method_args = NULL;
	}
	~Node(){};
};

typedef union Node YYSTYPE;

#define YYSTYPE_IS_DECLARED 1
/* Classes
class Prog;
class fieldDecls;
class fieldDecl;
class Vars;
class Var;
class methodDecls;
class methodDecl;
class Args;
class Arg;
class Block;
class varDecls;
class Stmts;
class Stmt;
class Assignment;
class Block;
class Params;
class forStmt;
class ifElseStmt;
class returnStmt;
class breakStmt;
class continueStmt;
class Expr;
class methodCall;
class Method;
class methodArgs;
class calloutCall;
class calloutArgs;
class calloutArg;
class EnclExpr;
class binExpr;
class unExpr;
class Location;
class Literal;
class intLiteral;
class boolLiteral;
class charLiteral;
class stringLiteral;
*/
class reportError{
	/* Class for error handling */
    public:
        static llvm::Value* ErrorV(string str) {
            cout<<str<<endl;
            return 0;
        }
};

class astNode{
	virtual Value* codegen(){}
};

class Var:public astNode{
private:
	string declType; /* Array or Normal */
	string name; /* Name of the variable */
	string dataType; /* type of variable */
	unsigned int length; /* if it is an Array then length */
public:
	/* Constructors */
	Var(string,string,unsigned int);
	Var(string,string);
	bool isArray();
	/* Methods */
	void setDataType(string); /* Set the data Type */
	void traverse();
	string getName();
	Value* codegen();
	int getLength(){return length;}
};

class Vars:public astNode{
private:
	vector<class Var*> vars_list;
	int cnt;
public:
	Vars(){}
	void push_back(class Var*);
	vector<class Var*> getVarsList();
	void traverse();
	Value* codegen();
};

class fieldDecl:public astNode{
private:
	string dataType; /* Field declaration can have datatype and vaariables */
	vector<class Var*> var_list;
public:
	fieldDecl(string,class Vars*);
	vector<class Var*> getVarsList();
	void traverse();
	Value* codegen();
};

class fieldDecls:public astNode{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	void traverse();
	Value* codegen();
};

class Expr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
	virtual string toString(){}
	virtual void traverse(){}
	virtual Value* codegen(){}
};

class EnclExpr:public Expr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
	void traverse();
	Value* codegen();
};

class unExpr:public Expr{
private:
	class Expr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class Expr*);
	void traverse();
	Value* codegen();
};

class binExpr:public Expr{
private:
	class Expr* lhs; /* left hand side */
	class Expr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class Expr*, string, class Expr*);
	void traverse();
	Value* codegen();
};

class Location:public Expr{
private:
	string var; /* name used in location */
	string location_type; /* Array or normal */
	class Expr* expr; /* if it is array then we have the address */
public:
	Location(string,string,class Expr*);
	Location(string,string);
	void traverse();
	string getVar();/* returns the var name */
	bool is_array(); /* tells if its array or not */
	class Expr* getExpr();
	Value* codegen();
};

class Literal:public Expr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
	virtual Value* codegen(){}
};

class intLiteral:public Literal{
private:
	int value;
public:
	intLiteral(int);
	void traverse();
	int getValue();
	string toString();
	Value* codegen();
};

class boolLiteral:public Literal{
private:
	string value;
public:
	boolLiteral(string);
	void traverse();
	string toString();
	Value* codegen();
};

class charLiteral:public Literal{
private:
	char value;
public:
	charLiteral(string);
	void traverse();
};

class stringLiteral:public Literal{
private:
	string value;
public:
	stringLiteral(string);
	void traverse();
	Value* codegen();
};

class Stmt:public astNode{
protected:
		stmtType stype;
public:
	virtual void traverse(){}
	virtual Value* codegen(){}
	virtual bool has_return(){return false;}
	void setStype(stmtType x){this->stype = x;}
	stmtType getStype(){return this->stype;}
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	void traverse();
	bool has_return();
	Value* codegen();
};
class methodCall:public Stmt,public Expr{
protected:
	string method_name;
public:
	virtual void traverse(){}
	virtual Value* codegen(){}
};

class calloutCall:public methodCall{
private:
	class calloutArgs* args; /* Args passed to callout call */
public:
	calloutCall(string, class calloutArgs*);
	void traverse();
	Value* codegen();
};

class Method:public methodCall{
private:
	class Params* params;/* Parameters passed to method call */
public:
	Method(string, class Params*);
	void traverse();
	Value* codegen();
};

class Params:public astNode{
private:
	vector<class Expr*> expr_list;
	int cnt;
public:
	Params();
	void push_back(class Expr*);
	void traverse();
	vector<class Expr*> getExprList();
	Value* codegen();
};

class calloutArg:public astNode{
private:
	class Expr* expr;
public:
	calloutArg(class Expr*);
	calloutArg(string literal);
	void traverse();
	Value* codegen();
};

class calloutArgs:public astNode{
private:
	vector<class calloutArg*> args_list;
	int cnt;
public:
	calloutArgs();
	void traverse();
	void push_back(class calloutArg*);
	vector<class calloutArg*> getArgsList();
	Value* codegen();
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class Expr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class Expr*);
	void traverse();
	Value* codegen();
};

class Block:public Stmt{
private:
	class varDecls* decls_list; /* list of variable declarations */
	class Stmts* stmts_list; /* list of statement declarations */
public:
	Block(class varDecls*,class Stmts*);
	void traverse();
	bool has_return();
	Value* codegen();
};

class varDecl:public astNode{
private:
	string type; /* type of variable declaraion */
	vector<string> var_list; /* list of variables */
	int cnt;
public:
	varDecl(string,class stringList*);
	void push_back(string);
	void traverse();
	Value* codegen(map<string,llvm::AllocaInst *>&);
};

class stringList{
private:
	vector<string> list; /* class to store vector of strings */
public:
	stringList(){}
	void push_back(string);
	vector<string> getList();
};
class varDecls:public astNode{
private:
	vector<class varDecl*> decl_list;
	int cnt;
public:
	varDecls();
	void push_back(class varDecl*);
	void traverse();
	Value* codegen(map<string,llvm::AllocaInst *>&);
};

class forStmt:public Stmt{
private:
	string var;/* variable to be initialised */
	class Expr* init; /* Value for initialisation */
	class Expr* condition; /* condition for loop */
	class Block* body; /* body of the loop */
public:
	forStmt(string, class Expr*, class Expr*, class Block*);
	bool has_return(){this->body->has_return();}
	void traverse();
	Value* codegen();
};

class ifElseStmt:public Stmt{
private:
	class Expr* condition; /* condition for if statement */
	class Block* if_block; /* if block */
	class Block* else_block;/* else block */
public:
	ifElseStmt(class Expr*, class Block*, class Block*);
	void traverse();
	Value* codegen();
	bool has_return(){
		bool status = false;
		if(if_block != NULL){
			status = status | if_block->has_return();
		}
		if(else_block != NULL){
			status = status | if_block->has_return();
		}
		return status;
	}
};

class returnStmt:public Stmt{
private:
	class Expr* ret;/* Expression to be returned */
public:
	returnStmt(class Expr*);
	void traverse();
	Value* codegen();
	bool has_return(){return true;}
};

class breakStmt:public Stmt{
public:
	breakStmt(){this->stype = stmtType::NonReturn;}
	void traverse();
	Value* codegen();
};

class continueStmt:public Stmt{
public:
	continueStmt(){this->stype = stmtType::NonReturn;}
	void traverse();
	Value* codegen();
};

class methodDecl:public astNode{
private:
	string type; /* return type of the function */
	string name; /* name of the function */
	class methodArgs* arg_list; /* List of arguments for the functions */
	class Block* body; /* Body of the function */
public:
	methodDecl(string type, string name, class methodArgs*, class Block*);
	void traverse();
	Function* codegen();
};

class methodDecls:public astNode{
private:
	vector< class methodDecl* > decl_list;
	int cnt;
public:
	methodDecls();
	void push_back(class methodDecl*);
	void traverse();
	Value* codegen();
};

class methodArgs:public astNode{
private:
	vector<class methodArg*> arg_list;
	int cnt;
public:
	methodArgs();
	void push_back(class methodArg*);
	vector<class methodArg*> getArgList();
	void traverse();
	Value* codegen();
};

class methodArg:public astNode{
private:
	string type; /* type of the argument int/boolean */
	string name; /* name of argument */
public:
	methodArg(string,string);
	string getName();
	string getType();
	void traverse();
	Value* codegen();
};

class Prog:public astNode{
private:
	string name; /* name of the class */
	class methodDecls* methods; /* list of methods */
	class fieldDecls* fields; /* list of fields */
public:
	Prog(string name,class fieldDecls*,class methodDecls*);
	void traverse();
	Value* codegen();
	void generateCode();
};
