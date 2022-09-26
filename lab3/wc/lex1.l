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

%%

{letter}+ { 
  if(strlen(yytext) > 0) {
    char s = yytext[0];
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
      printf("%s\n", yytext); 
      words++;
    }
  } 
  chars+=strlen(yytext); 
}
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