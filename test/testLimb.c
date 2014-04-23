#include <stdio.h>
#include <Limb.h>
#include "test.h"

#define MODULE "Limb.c"

int main(void)
{
	int testCount = 0, error = 0;
	
	report(MODULE, error, testCount);
	
	return 0;
}
