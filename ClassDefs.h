#include <bits/stdc++.h>

using namespace std;

enum exprType { binary = 1, location = 2, literal = 3, enclExpr = 4 , Unexpr = 5};
enum literalType { Int = 1, Bool = 2, Char = 3, String = 4 };
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

class Var{
private:
	string declType; /* rray or Normal */
	string name; /* Name of the variable */
	string dataType; /* type of variable */
	unsigned int length; /* if it is an Array then length */
public:
	/* Constructors */
	Var(string,string,unsigned int);
	Var(string,string);
	/* Methods */
	void setDataType(string); /* Set the data Type */
	void traverse();
};

class Vars{
private:
	vector<class Var*> vars_list;
	int cnt;
public:
	Vars(){}
	void push_back(class Var*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecl{
private:
	string dataType; /* Field declaration can have datatype and vaariables */
	vector<class Var*> var_list;
public:
	fieldDecl(string,class Vars*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecls{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	void traverse();
};

class Expr{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype();
	virtual string toString(){}
	virtual void traverse(){}
};

class EnclExpr:public Expr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
	void traverse();
};

class unExpr:public Expr{
private:
	class Expr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class Expr*);
	void traverse();
};

class binExpr:public Expr{
private:
	class Expr* lhs; /* left hand side */
	class Expr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class Expr*, string, class Expr*);
	void traverse();
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
};

class Literal:public Expr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
};

class intLiteral:public Literal{
private:
	int value;
public:
	intLiteral(int);
	void traverse();
	int getValue();
	string toString();
};

class boolLiteral:public Literal{
private:
	string value;
public:
	boolLiteral(string);
	void traverse();
	string toString();
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
};

class Stmt{
public:
	virtual void traverse(){}
};

class Stmts{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	void traverse();
};
class methodCall:public Stmt,public Expr{
protected:
	string method_name;
public:
	virtual void traverse(){}
};

class calloutCall:public methodCall{
private:
	class calloutArgs* args; /* Args passed to callout call */
public:
	calloutCall(string, class calloutArgs*);
	void traverse();
};

class Method:public methodCall{
private:
	class Params* params;/* Parameters passed to method call */
public:
	Method(string, class Params*);
	void traverse();
};

class Params{
private:
	vector<class Expr*> expr_list;
	int cnt;
public:
	Params();
	void push_back(class Expr*);
	void traverse();
};

class calloutArg{
private:
	class Expr* expr;
public:
	calloutArg(class Expr*);
	calloutArg(string literal);
	void traverse();
};

class calloutArgs{
private:
	vector<class calloutArg*> args_list;
	int cnt;
public:
	calloutArgs();
	void traverse();
	void push_back(class calloutArg*);
};


class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class Expr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class Expr*);
	void traverse();
};

class Block:public Stmt{
private:
	class varDecls* decls_list; /* list of variable declarations */
	class Stmts* stmts_list; /* list of statement declarations */
public:
	Block(class varDecls*,class Stmts*);
	void traverse();
};

class varDecl{
private:
	string type; /* type of variable declaraion */
	vector<string> var_list; /* list of variables */
	int cnt;
public:
	varDecl(string,class stringList*);
	void push_back(string);
	void traverse();
};

class stringList{
private:
	vector<string> list; /* class to store vector of strings */
public:
	stringList(){}
	void push_back(string);
	vector<string> getList();
};
class varDecls{
private:
	vector<class varDecl*> decl_list;
	int cnt;
public:
	varDecls();
	void push_back(class varDecl*);
	void traverse();
};

class forStmt:public Stmt{
private:
	string var;/* variable to be initialised */
	class Expr* init; /* Value for initialisation */
	class Expr* condition; /* condition for loop */
	class Block* body; /* body of the loop */
public:
	forStmt(string, class Expr*, class Expr*, class Block*);
	void traverse();
};

class ifElseStmt:public Stmt{
private:
	class Expr* condition; /* condition for if statement */
	class Block* if_block; /* if block */
	class Block* else_block;/* else block */
public:
	ifElseStmt(class Expr*, class Block*, class Block*);
	void traverse();
};

class returnStmt:public Stmt{
private:
	class Expr* ret;/* Expression to be returned */
public:
	returnStmt(class Expr*);
	void traverse();
};

class breakStmt:public Stmt{
public:
	breakStmt(){}
	void traverse();
};

class continueStmt:public Stmt{
public:
	continueStmt(){}
	void traverse();
};

class methodDecl{
private:
	string type; /* return type of the function */
	string name; /* name of the function */
	class methodArgs* arg_list; /* List of arguments for the functions */
	class Block* body; /* Body of the function */
public:
	methodDecl(string type, string name, class methodArgs*, class Block*);
	void traverse();
};

class methodDecls{
private:
	vector< class methodDecl* > decl_list;
	int cnt;
public:
	methodDecls();
	void push_back(class methodDecl*);
	void traverse();
};

class methodArgs{
private:
	vector<class methodArg*> arg_list;
	int cnt;
public:
	methodArgs();
	void push_back(class methodArg*);
	void traverse();
};

class methodArg{
private:
	string type; /* type of the argument int/boolean */
	string name; /* name of argument */
public:
	methodArg(string,string);
	void traverse();
};

class Prog{
private:
	string name; /* name of the class */
	class methodDecls* methods; /* list of methods */
	class fieldDecls* fields; /* list of fields */
public:
	Prog(string name,class fieldDecls*,class methodDecls*);
	void traverse();
};
