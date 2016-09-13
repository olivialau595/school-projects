// Olivia Lau
// September 1, 2016
// Compilers
// error.c

#include "global.h"

error(m)
    char *m;
{
    fprintf(stderr, "line %d: %s\n", lineno, m);
    exit(1);
}
