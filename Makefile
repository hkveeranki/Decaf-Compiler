TARGET=mycomp
all=$(TARGET)
CC=gcc
CFLAGS=-lfl
$(TARGET): lex.yy.c decaf.tab.c
	$(CC) lex.yy.c decaf.tab.c $(CFLAGS) -o $(TARGET)
lex.yy.c: decaf.l
	flex decaf.l
decaf.tab.c: decaf.y
	bison -d decaf.y
clean:
	rm -f *.c decaf.tab.h $(TARGET) *_output.txt
