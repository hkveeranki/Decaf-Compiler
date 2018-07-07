# Decaf-Compiler

## Description

Compiler for [Decaf](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-035-computer-language-engineering-spring-2010/projects/MIT6_035S10_decaf.pdf) Programming Language. Developed as a course project for Compilers course.
Decaf is a strongly-typed, object-oriented language with support for inheritance and encapsulation. By design, it has many similarities with C/C++/Java, so you should find it fairly easy
to pick up. But it is not an exact match to any of those languages. The feature set has been trimmed down and simplified to keep the programming projects manageable 

## Approach

- Firstly, we perform lexical analysis on the given code 
and break down the input code into tokens.
- Next we do semantic analysis and transform this set of tokens into an
AST (Abstract Syntax tree) using _Vistor design pattern_ approach 
- Once AST is prepared, we generate the _Intermediate Representation_
 
## Frameworks used
- [Flex](ftp://ftp.gnu.org/old-gnu/Manuals/flex-2.5.4/html_mono/flex.html) for lexical analysis 
- [YACC](http://dinosaur.compilertools.net/yacc/) for semantic analysis
- [LLVM](http://llvm.org/) for generating the IR

## Reference
- Code Documentation can be found [here](/html/index.html)
- Instructions for running the code can be found [here](https://github.com/harry-7/Decaf-Compiler/blob/master/README.md)