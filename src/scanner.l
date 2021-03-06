%{

#include <cstdio>
#include <cstring>
#include "State.h"
#include "parser.hpp"

#define SAVE_TOKEN yylval.str = maketoken(yytext, yyleng)
#define SAVE_STRING yylval.str = makestring(yytext, yyleng)
#define SAVE_SCRIPT yylval.str = makescript(yytext, yyleng)
extern "C" int yywrap() { return 1; }
char* maketoken(const char* data, int len);
char* makestring(const char* data, int len);
char* makescript(const char* data, int len);

#ifdef _WIN32

/*windows compatibility case*/  
#define YY_NO_UNISTD_H
#include <io.h>  
#define isatty _isatty  
#define fileno _fileno  

#endif

%}

/* show the line number */
%option yylineno

%%

"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" ; 

#[^\n]*\n				; /* ignore line comment */ 

[ \t\v\n\f]             ; /* ignore blank token */

\"(\\.|[^\\"])*\"		SAVE_STRING; return STRING;

"{{"([^}]|\}[^}])*"}}"	SAVE_SCRIPT; return SCRIPT;

"e"						return 'e';

":"						return ':'; 

"<"						return '<'; 

">"						return '>'; 

"["						return '[';

"]"						return ']';

"="						return '='; 

"|"                     return '|';

";"                     return ';';

"%left"					return LEFT;

"%right"				return RIGHT;

[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return ID;

%%


char* maketoken(const char* data, int len) {
	char* str = new char[len+1];
	strncpy(str, data, len);
	str[len] = 0;
	return str;
}

char* makestring(const char* data, int len) {
	char* str = new char[len-1];
	strncpy(str, data+1, len-2);
	str[len-2] = 0;
	return str;
}

char* makescript(const char* data, int len) {
	char* str = new char[len-3];
	strncpy(str, data+2, len-4);
	str[len-4] = 0;
	return str;
}
