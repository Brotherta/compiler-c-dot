CC=gcc
YC=yacc
FL=flex

TARGET=run_compiler

all:
	$(YC) -d mongcc.y
	$(FL) mongcc.l
	$(CC) -w -g lex.yy.c y.tab.c structure.c ./dot/dot_builder.c -lfl -o $(TARGET)

clean:
	rm $(TARGET) y.tab.c y.tab.h lex.yy.c