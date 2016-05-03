/*Andrew Creevey, ID: 12236284*/

/*This program calculates the day and month of Easter Sunday in the given year*/

#include <stdio.h>
int day, month, year, result, a, b, c, d, e;
int main(){
	year = 0;
	while (year >= 0) {
		printf ("Enter the year: ");
		scanf ("%d", &year);
		
		c = year % 19;
		d = year % 4;
		e = year % 7;
		a = (19 * c + 24) % 30;
		b = (2 * d + 4 * e + 6 * a + 5) % 7;
		result = 22 + a + b;
		
		day = result % 32;
		day = day + (result / 32);
		
		month = (result / 32) + 3;
		
		printf("In the year %d, Easter Sunday will be on the %d/%d.\n\n",
			year, day, month);
	}
}
