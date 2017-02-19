#include "LexInterface.h"
#include "Lex.h"

LexInterface* CreateLex() {
    return new Lex();
}
