//This program reads in a date and prints out the date of the next day

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int d, m, y, year, error;
bool leapyear;

int main() {
	
	error = 0;
	d = 1, m = 1, y = 1;
	
	while ((d != 0) && (m != 0) && (y != 0)) {
		printf("Enter a date in the form dd mm yyyy, for example: 27 03 1995\n");
		printf("Use 00 00 0000 to stop:\n");
		scanf("%d %d %d", &d, &m, &y);
		
		if ((d == 0) && (m == 0) && (y == 0)) {
			exit(1);
		}
		
		d = d + 1;
		
		//Checks to see if date is valid
		if (d > 32){
			printf("Sorry the date you have entered is incorrect.\n");
			printf("Please try again.\n\n");
			error = 1;
		}
		if (m > 13){
			printf("Sorry the date you have entered is incorrect\n");
			printf("Please try again.\n\n");
			error = 1;
		}
		
		//Checks to see if the entered year is a leap year
		leapyear = true;
		if (y % 4 == 0){
			leapyear = false;
		}
		if (y % 100 == 0){
			leapyear = false;
		}
		if (y % 400 == 0){
			leapyear = true;
		}
		
		//If the month is february
		if (m == 2){
			if (leapyear){
				if (d == 30){
					d = 1;
					m = m + 1;
				}
			} else {
				if (d == 29){
					d = 1;
					m = m + 1;
				}
				//if you enter a 29/02 in a non-leap year, error message will show
				if (d == 30){
					printf("Sorry the date you have entered is incorrect\n");
					printf("Please try again.\n\n");
					error = 1;
				}
			}
		}
		
		//If the month has 30 days in
		if ((d == 31) && ((m == 4) || (m == 6) || ( m == 9) || (m == 11))){
			d = 1;
			m = m + 1;
		} 
		
		//If the month has 31 days in (excl. december)
		if ((d == 32) && ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10))){
			d = 1;
			m = m + 1;
		}
		
		//If the month is december
		if (m == 12){
			if (d == 32){
				d = 1;
				m = 1;
				y = y + 1;
			}
		}
		
		if (error == 0) {
			printf("The date of next day is %d/%d/%d\n\n", d, m, y);
		}
	}	
}
