%{
    // just let you know you have macros!
    // C macro tutorial in Chinese: http://c.biancheng.net/view/446.html
    #define EXIT_OK 0
    #define EXIT_FAIL 1

    // global variables
    int chars = 0;
    int words = 0;
    int lines = 0;
%}
letter [a-zA-Z]
delimeter [^a-zA-Z\n]
vowel a|e|i|o|u|A|E|I|O|U
consonant [b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]
case1 ^{vowel}{letter}*
case2 {delimeter}+{vowel}{letter}*
case3 ^{consonant}{letter}*
case4 {delimeter}+{consonant}{letter}*

%%
{case1} { words++; chars+=strlen(yytext); /* only count words starting with a vowel*/ }
{case2} { words++; chars+=strlen(yytext); /* only count words starting with a vowel*/ }
{case3} { chars+=strlen(yytext); }
{case4} { chars += strlen(yytext); }
\n { chars++; lines++; }
. {chars++;}

%%
int main(int argc, char **argv){
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        yylex();
	printf("%-8s%-8s%-8s%s\n", "#lines", "#words", "#chars", "file path");
        printf("%-8d%-8d%-8d%s\n", lines, words, chars, file_path);
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
