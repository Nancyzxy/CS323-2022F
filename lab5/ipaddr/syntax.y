%{
    #define YYSTYPE char *
    #include "lex.yy.c"
    #include <ctype.h>
    int yyerror(char* s);
    void valid4 (char* s);
    void valid6 (char* s);
%}

%token X
%token DOT
%token COLON

%%
success: ipv4 | ipv6;
ipv4: term DOT term DOT term DOT term
    {
        valid4($1);
        valid4($3);
        valid4($5);
        valid4($7);
        printf("%s\n", "IPv4");
    };
ipv6: term COLON term COLON term COLON term COLON term COLON term COLON term COLON term 
    {
        valid6($1);
        valid6($3);
        valid6($5);
        valid6($7);
        valid6($9);
        valid6($11);
        valid6($13);
        valid6($15);
        printf("%s\n", "IPv6");
    };
term: X;

%%
void valid4 (char* s){
    int number = atoi (s);
    if(number=0 || number >255){
        yyerror(s);
        return;
    }
    for(int i=0;i<strlen(s);i++){
        char c = *(s+i);
        int a = atoi(&c);
        if(a==0){
            if(strlen(s)!=1){
                yyerror(s);
                }
        }else{
            return;
        }
    }
}

void valid6 (char* s){
    if(strlen(s)<1 || strlen(s)>4){
        yyerror(s);
    }
}

int yyerror(char* s) {
    fprintf(stderr, "%s\n", "Invalid");
    exit(1);
}
int main() {
    yyparse();
}
