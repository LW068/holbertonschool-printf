#include "main.h"
#include <stdio.h>	

int main(void)
{
int retVal, retVal2;
retVal = _printf("%s", NULL);
retVal2 = printf("%s", NULL);
printf("\n%d%d\n", retVal, retVal2);

return (0);
}
