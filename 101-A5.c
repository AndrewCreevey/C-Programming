/*Name: Andrew Creevey	ID: 12236284*/
#include <stdio.h>
#include <stdlib.h>
int factorial (int x);
int n, r, ncombr;
int main() {
	printf("Please enter a number for the values n and r\n");
	printf("n must be less than 12 & n must be greater than r\n");
	printf("Press enter when done.\n\n");
	printf("n = "), scanf("%d", &n);
	printf("r = "), scanf("%d", &r);
	
	//error checking loop
	while ((n <= 0) || (r <= 0) || (n <= r) || (n > 12)) {
		printf("Sorry the data you entered is incorrect, please try again:\n");
		printf("n = "), scanf("%d", &n);
		printf("r = "), scanf("%d", &r);
	}
	
	ncombr = factorial(n) / (factorial (n - r) * factorial (r));
	printf("%d combination %d = %d", n, r, ncombr);
}

int factorial (int x) {
	int fact, result;
	result = 1;
	for (fact = 1; fact <= x; fact ++){
		result = result * fact;
	}
	return result;
}
