/* Name: Andrew Creevey 	ID: 12236284 */
//forgot to put name on previous assignment 
#include <stdio.h>
#include <string.h>
char sentence[100], temp [100];
int width, len, spaces, leftover, excess, share, i, j,;
int main () {
	spaces = 0;
	while (true) {
		printf("Enter the width of the column: ");
		gets (temp);
		sscanf(temp, "%d", &width);
		
		printf("Enter a line of text: ");
		gets (sentence);
		
		len = strlen(sentence);
		
		sentence[len+1] = '\0';
		
		if (len > width) {
			printf("Error: Width must be greater than or equal to the length.\n\n");
		} else {
			break;
		}
	}
	
	for (i = 0; i < len; i++) {
		if (sentence[i] == ' '){
			spaces++;
		}
	}
	
	leftover = width - len;
	share = leftover / spaces;
	excess = leftover % spaces;
	
	printf("\n");
	for (i = 0; i < width / 10; i++) {
		printf("1234567890");
	}
	printf("\n");
	
	for (i = 0; i < len; i++) {
		printf("%c", sentence[i]);
		if (sentence[i] == ' ') {
			for (j = 0; j < share; j++) {
				printf(" ");
			}
			if (excess > 0) {
				printf(" ");
				excess --;
			}
		}
	}
}
