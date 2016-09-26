TARGET=mycomp
all=$(TARGET)
CC=gcc
CFLAGS=-lfl
$(TARGET): lex.yy.c parser.tab.c
	$(CC) lex.yy.c bison_parser.tab.c $(CFLAGS) -o $(TARGET)
lex.yy.c: specifications_lex.l
	flex lex_specifications.l
parser.tab.c: parser.y
	bison -d bison_parser.y
clean:
	rm -f *.c *.h $(TARGET) *_output.txt
