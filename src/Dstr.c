#include <Dstr.h>
#include <Limb.h>

struct Dstr
{
	Limb * first;
	Limb * last;
	int limbs;
	int length;
};


Dstr * dstr_init(void)
{
	Dstr * self = (Dstr *) malloc(sizeof(Dstr));
	self->first = limb_init();
	self->last = self->first;
	self->limbs = 1;
	self->length = 0;
	
	return self;
}


int dstr_destroy(Dstr * self)
{
	if (!self)
	{
		return 1;
	}
	
	Limb * limb = self->first;
	while (self->first)
	{
		limb = self->first->next;
		limb_destroy(self->first);
		self->first = limb;
	}
	
	free(self);
	
	return 0;
	
}


int dstr_set(Dstr * dest, char * string) { return 1; }

char dstr_getc(Dstr * source, int index) { return '\0'; }
int  dstr_length(Dstr * self) { return self->length; }

char * dstr_toString(Dstr * source)
{
	char * string = (char *) malloc(sizeof(char));
	string[0] = '\0';
	return string;
}

char * dstr_subString(Dstr * source, int start, int end)
{
	char * string = (char *) malloc(sizeof(char));
	string[0] = '\0';
	return string;
}


int dstr_cat(Dstr * dest, Dstr * source) { return 1; }
int dstr_token(Dstr * dest, Dstr * source, char token) { return 1; }
int dstr_insert(Dstr * dest, Dstr * source, int index) { return 1; }




