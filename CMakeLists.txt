cmake_minimum_required(VERSION 3.10)

project(Decaf_Compiler)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ldl -lfl")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_FLEX_BISON_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/flex_bison_output)

# Create the directory for flex and bison outputs
file(MAKE_DIRECTORY ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

# Setup the required Libraries
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
find_package(BISON)
find_package(FLEX)

# Link the directories which contain required libraries
link_directories(/usr/lib/llvm-*/build/lib)

# Add directories which has the header files that are used in the project
include_directories(/usr/lib/llvm-*/build/include)
include_directories(src)
include_directories(src/class_definitions)

# Make Lexical analyser and parser using flex and bison
BISON_TARGET(Parser src/decaf_parser.ypp ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/decaf.tab.cpp)
FLEX_TARGET(Lexer src/decaf_lexer.l ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/lex.yy.cc)

# Build the core functionality shared library
add_library(coreLibrary SHARED
        src/utilities.cpp
        src/variable.cpp
        src/variables.cpp
        src/fieldDeclaration.cpp
        src/fieldDeclarations.cpp
        src/enclosedExpression.cpp
        src/unaryExpression.cpp
        src/binaryExpression.cpp
        src/location.cpp
        src/integerLiteral.cpp
        src/boolLiteral.cpp
        src/charLiteral.cpp
        src/stringLiteral.cpp
        src/statements.cpp
        src/calloutCall.cpp
        src/calloutArgument.cpp
        src/calloutArguments.cpp
        src/methodCall.cpp
        src/parameters.cpp
        src/assignment.cpp
        src/block.cpp
        src/variableDeclaration.cpp
        src/stringList.cpp
        src/variableDeclarations.cpp
        src/forStatement.cpp
        src/ifElseStatements.cpp
        src/returnStatement.cpp
        src/breakStatement.cpp
        src/continueStatement.cpp
        src/methodArgument.cpp
        src/methodArguments.cpp
        src/methodDeclaration.cpp
        src/methodDeclarations.cpp
        src/program.cpp
        src/constructs.cpp)

# Add the main executable
add_executable(decafCompiler
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS})
target_include_directories(decafCompiler PRIVATE
        ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})
target_link_libraries(decafCompiler coreLibrary)

llvm_map_components_to_libnames(llvm_libs support core irreader mcjit native)
target_link_libraries(decafCompiler ${llvm_libs})