#ifndef LIMB_H
#define LIMB_H

#define LIMBSIZE 10




// ############### types ###############

typedef struct Limb Limb;

struct Limb
{
	Limb * prev;
	Limb * next;
	int length;
	char string[LIMBSIZE];
};




// ############### methods ###############
Limb * limb_init();
int limb_destroy(Limb * self);




#endif
