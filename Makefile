TARGET=mycomp
all=$(TARGET)
$(TARGET): lex.yy.c bison_parser.tab.c
	gcc lex.yy.c bison_parser.tab.c -lfl -o $(TARGET)
lex.yy.c: lex_specifications.l
	flex lex_specifications.l
bison_parser.tab.c: bison_parser.y
	bison -d bison_parser.y
clean:
	rm -f *.c *.h $(TARGET)
