CC=gcc
FLEX=flex
wc:
	$(FLEX) lex.l
	$(CC) lex.yy.c -lfl -o wc.out
wc1:
	$(FLEX) lex1.l
	$(CC) lex.yy.c -lfl -o wc.out
wc2:
	$(FLEX) lex2.l
	$(CC) lex.yy.c -lfl -o wc.out
clean:
	@rm -f lex.yy.c *.out
.PHONY: wc
