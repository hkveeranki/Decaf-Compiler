cmake_minimum_required(VERSION 3.10)

project(Decaf_Compiler)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ldl -lfl")

find_package(LLVM REQUIRED CONFIG)
find_package(BISON)
find_package(FLEX)

link_directories(/usr/lib/llvm-6.0/build/lib)
include_directories(/usr/lib/llvm-6.0/build/include)
include_directories(src)

BISON_TARGET(Parser src/decaf.ypp ${CMAKE_CURRENT_BINARY_DIR}/decaf.tab.cpp)
FLEX_TARGET(Lexer src/decaf.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc)

add_library(decaf_core SHARED
        src/utilities.cpp
        src/utilities.h
        src/var.cpp
        src/var.h
        src/astNode.h
        src/vars.cpp src/vars.h
        src/fieldDecl.cpp
        src/fieldDecl.h
        src/common.h
        src/fieldDecls.cpp
        src/fieldDecls.h
        src/expr.h
        src/enclExpr.cpp
        src/enclExpr.h
        src/unExpr.cpp
        src/unExpr.h
        src/binExpr.cpp
        src/binExpr.h
        src/location.cpp
        src/location.h
        src/literal.h
        src/intLiteral.cpp
        src/intLiteral.h
        src/boolLiteral.cpp
        src/boolLiteral.h
        src/charLiteral.cpp
        src/charLiteral.h
        src/stringLiteral.cpp
        src/stringLiteral.h
        src/stmt.h
        src/stmts.cpp
        src/stmts.h
        src/methodCall.h
        src/calloutCall.cpp
        src/calloutCall.h
        src/calloutArg.cpp
        src/calloutArg.h
        src/calloutArgs.cpp
        src/calloutArgs.h
        src/method.cpp
        src/method.h
        src/params.cpp
        src/params.h
        src/assignment.cpp
        src/assignment.h
        src/block.cpp
        src/block.h
        src/varDecl.cpp
        src/varDecl.h
        src/stringList.cpp
        src/stringList.h
        src/varDecls.cpp
        src/varDecls.h
        src/forStmt.cpp
        src/forStmt.h
        src/ifElseStmt.cpp
        src/ifElseStmt.h
        src/returnStmt.cpp
        src/returnStmt.h
        src/breakStmt.cpp
        src/breakStmt.h
        src/continueStmt.cpp
        src/continueStmt.h
        src/methodArg.cpp
        src/methodArg.h
        src/methodArgs.cpp
        src/methodArgs.h
        src/methodDecl.cpp
        src/methodDecl.h
        src/methodDecls.cpp
        src/methodDecls.h
        src/prog.cpp
        src/prog.h
        src/globals.cpp
        src/globals.h)

add_executable(decaf_compiler ${FLEX_Lexer_OUTPUTS} ${BISON_Parser_OUTPUTS})
llvm_map_components_to_libnames(llvm_libs support core irreader mcjit)

# Link against LLVM libraries
target_link_libraries(decaf_compiler ${llvm_libs})
target_link_libraries(decaf_compiler decaf_core)