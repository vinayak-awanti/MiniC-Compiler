COMPILER = gcc
HEADER_FILES = st.h y.tab.h
FILESYSTEM_FILES = st.c y.tab.c lex.yy.c
all : lex yacc build
lex : lexer.l
	lex lexer.l
yacc : parser.y
	yacc -d parser.y
build: $(FILESYSTEM_FILES) $(HEADER_FILES)
	$(COMPILER) $(FILESYSTEM_FILES) -ly -ll -o comp
parsertest: yacc lex test
test: lex.yy.c y.tab.c
	$(COMPILER) lex.yy.c y.tab.c -ly -ll -o comp
clean:
	rm comp