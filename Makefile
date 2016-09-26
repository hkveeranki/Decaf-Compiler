TARGET=mycomp
all=$(TARGET)
CC=gcc
CFLAGS=-lfl
$(TARGET): lex.yy.c parser.tab.c
	$(CC) lex.yy.c parser.tab.c $(CFLAGS) -o $(TARGET)
lex.yy.c: specifications_lex.l
	flex specifications_lex.l
parser.tab.c: parser.y
	bison -d parser.y
clean:
	rm -f *.c *.h $(TARGET) *_output.txt
