TARGET=mycomp
all=$(TARGET)
CC = clang++
CFLAGS = -lfl -ldl `llvm-config --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread
FLAGS=-w -Wno-deprecated -g -std=c++11
all: $(TARGET)
$(TARGET): lex.yy.c decaf.tab.c Classes.cpp ClassDefs.h
	$(CC) $(FLAGS) lex.yy.c decaf.tab.c Classes.cpp $(CFLAGS)
lex.yy.c: decaf.l
	flex decaf.l
decaf.tab.c: decaf.y
	bison -vd decaf.y
clean:
	rm *.c
veryclean:
	rm -f *.c decaf.tab.h a.out XML_* *.output
