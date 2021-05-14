CC=gcc
YC=yacc
FL=flex

FILE=test

TARGET=run_compiler

compile:
	@$(YC) -d ./src/mongcc.y
	@$(FL) ./src/mongcc.l
	@$(CC) -w -g lex.yy.c y.tab.c ./src/structure/structure.c ./src/dot/dot_builder.c -lfl -o $(TARGET)
	@make -s clean

clean:
	@rm y.tab.c y.tab.h lex.yy.c

run_all:
	@chmod +x ./src/bash/run_all.sh
	@./src/bash/run_all.sh

run:
	@echo 
	@echo "\e[0;35mCompiling $(FILE) ...\e[0;37m"
	@./$(TARGET) < Tests/$(FILE)
	@mkdir -p generation/dot generation/pdf
	@echo "\e[0;32mDot file successfully generated at ./generation/dot/$(FILE).dot\e[0;37m"
	@dot -Tpdf ./_tmp_file.dot -o ./generation/pdf/$(FILE).pdf
	@echo "\e[0;32mPdf file successfully generated at ./generation/pdf/$(FILE).pdf\e[0;37m"
	@mv ./_tmp_file.dot ./generation/dot/$(FILE).dot

install:
	sudo apt install -y graphviz flex bison --upgrade