# Decaf-Compiler
## Description

Compiler for [Decaf](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-035-computer-language-engineering-spring-2010/projects/MIT6_035S10_decaf.pdf) 
Programming Language. Developed as a course project for Compilers course.
Decaf  is  a  strongly-typed,  object-oriented  language  with  support  for  inh
eritance  and  encapsulation. By design, it has many similarities with C/C++/Java, so you should find it fairly easy
to pick up. But it is not an exact match to any of those languages.  The feature set has be
en trimmed down and simplified to keep the programming projects manageable 

## Repo structure
- [src](./src) contains all the code
    + [class_definitions](./src/class_definitions) contains definitions for all the classes
- [docs](./docs) contain code documentation
- [sample_inputs](./sample_inputs) contain some sample Decaf programs

## Building
``` 
mkdir build
cd build/
cmake ..
make 
``` 
This will create an executable named `decafCompiler` in `build/bin` directory

## Running the executable
```
decafCompiler <input_file> > <output_file>
lli <output_file>
```
