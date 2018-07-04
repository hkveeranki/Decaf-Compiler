TARGET=mycomp
all=$(TARGET)
CC = g++
CFLAGS = -lfl `llvm-config-6.0 --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl
FLAGS=-w -Wno-deprecated -g -std=c++11
all: $(TARGET)
$(TARGET): lex.yy.c decaf.tab.c Classes.cpp ClassDefs.h
	$(CC) $(FLAGS) lex.yy.c decaf.tab.c Classes.cpp $(CFLAGS)
lex.yy.c: decaf.l
	flex decaf.l
decaf.tab.c: decaf.y
	bison -vd decaf.y
clean:
	rm -f *.c decaf.tab.h *.output llout
veryclean:
	rm -f *.c decaf.tab.h a.ofstream1 XML_* *.output
