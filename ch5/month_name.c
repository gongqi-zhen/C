/*
	5-8
*/

#include <stdio.h>
#include <stdlib.h>

char * month_name ( int );

int main(int ac, char *av[])
{
	int i = 1;
	
	if ( ac == 1 )
		printf("%-2d is %15s\n", atoi(av[1]), month_name(atoi(av[1])));
	while ( --ac ) {
		printf("%-2d is %15s\n", atoi(av[i]), month_name(atoi(av[i])));
		i++;
	}

	return 0;
}

char * month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};
	return ( n < 1 || n > 12 ) ? name[0] : name[n];
}
