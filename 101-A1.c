/*Name: Andrew Creevey	ID: 1223624*/

#include <stdio.h>

/*This program calculates the year in which people will retire*/
/*For this program I have used my own age*/

int age, year, retireyear;
int main () {
	age = 20;
	printf ("The person is %d years old\n", age);
	year = 2016;
	printf ("The year is %d\n", year);
	retireyear = 65 - age + year;
	printf ("The person will retire in %d.\n", retireyear);
}
