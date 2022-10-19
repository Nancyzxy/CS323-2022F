%{
    #include"lex.yy.c"
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    | Value COMMA error { puts("comma after closing, recovered");}
    | Value error { puts("sth is redundant, recovered"); }
    ;
Value:
      Object
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    | NUMBER NUMBER error { puts("TWO number ,recovered");}
    ;
Object:
      LC RC
    | LC Members RC
    | LC Members error { puts("sth instead of RC, recovered");}
    ;
Members:
      Member
    | Member COMMA Members
    | Member COMMA error { puts("not or no members, recovered");}
    ;
Member:
      STRING COLON Value
    | STRING error Value  { puts("not colon, recovered"); }
    | STRING COLON error Value  { puts("double colon, recovered"); }
    ;
Array:
      LB RB
    | LB Values RB
    | LB Values RB RB error { puts("extra close, recovered"); }
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | LB Values error { puts("no right bracket ], recovered"); }
    ;
Values:
      Value
    | Value COMMA Values
    | Value COMMA error { puts("extra comma, recovered"); }
    | Value COLON error Values { puts("colon instead of comma, recovered"); }
    | COMMA Value error { puts("missing value, recovered"); }
    ;
%%

void yyerror(const char *s){
    printf("syntax error: ");
}

int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
