#include <stdlib.h>
#include <Limb.h>



Limb * limb_init(void) 
{
	Limb * self = (Limb *) malloc(sizeof(Limb));
	
	if (!self)
	{
		return NULL;
	}
	
	self->prev = NULL;
	self->next = NULL;
	self->length = 0;
	self->string[0] = '\0';
	
	return self;
}

int limb_destroy(Limb * self)
{
	if (self)
	{
		free(self);
		return 0;
	}
	
	return 1;
}
