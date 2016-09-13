// Olivia Lau
// September 1, 2016
// Compilers
// emitter.c

#include "global.h"

emit(t, tval)
    int t, tval;
{
    switch (t) {
        case '+':
        case '-':
        case '*':
        case '/': printf("%c\n", t);
                  break;
        case DIV: printf("DIV\n");
                  break;
        case MOD: printf("MOD\n");
                  break;
        case NUM: printf("NUM %d\n", tval);
                  break;
        case ID:  printf("%s\n", symtable[tval].lexptr);
                  break;
        default:  printf("token %d, tokenval %d\n", t, tval);
    }
}
