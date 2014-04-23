#ifndef DSTR_H
#define DSTR_H

#include <stdlib.h>
#include <stdio.h>

// ############### types ###############

typedef struct Dstr Dstr;



// ############### methods ###############

Dstr * dstr_init();
int dstr_destroy(Dstr * self);
int dstr_set(Dstr * dest, char * string);

char dstr_getc(Dstr * source, int index);
int  dstr_length(Dstr * self);

char * dstr_toString(Dstr * source); //remember to free this when you're done
char * dstr_subString(Dstr * source, int start, int end);

int dstr_cat(Dstr * dest, Dstr * source);
int dstr_token(Dstr * dest, Dstr * source, char token);
int dstr_insert(Dstr * dest, Dstr * source, int index);



#endif
