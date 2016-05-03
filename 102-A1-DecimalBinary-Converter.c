/* Name: Andrew Creevey ID: 12236284*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int todec (int bin);
int tobin (int dec);

int outputlength (int value);

int main () {
	int i = 0, output = 0, numtoobig = 0, numtoolong = 0,
		correct = 0, input = 0;
	char temp[50], binordec[1], type = 0;
	
	printf("Type in a number: ");
	gets (temp);
	
	sscanf (temp, "%d", &input);

	//error checking
	numtoolong = strlen (temp);
	sscanf(temp, "%d", &numtoobig);
	
	for (i = 0; temp[i] != '\0'; i++) {
		if (temp[0] == '0') {
			if ((temp[i] > 49) && (temp[i] < 58)) {
				printf("That is an invalid number!\n");
				exit(0);
			}
		}
	}
	
	for (i = 0; temp[i] != '\0'; i++) {
		if ((temp[i] < 48) || (temp[i] > 57)) {
			printf("That is an invalid number!\n");
			exit(0);
		}
	}
	
	while (0) {
		if ((numtoobig > 255) && (temp[0] != '1')) {
		printf("That is an invalid number!\n");
		exit(0);
		}
	}
	if (numtoolong > 8) {
		printf("That is an invalid number!\n");
		exit(0);
	}
	
	//checks for type of number
	for (i = 0; temp[i] != '\0'; i++) {
		if (temp[0] == '0'){
			type = 'b';	//input is binary
			if (temp[1] == '\0') {
				type = 'd';	//input is decimal
			}
		}
		if ((temp[i] > 49) && (temp[i] < 58)) {
			type = 'd';	//input is decimal
		}
	}
	
	if ((temp[0] == '1') && (type != 'd')) {
		while (correct != 1) {
			printf("Is this number decimal (d) or binary (b)?\n");
			gets(binordec);
			if ((binordec[0] == 'b') || (binordec[0] == 'B')) {
				type = 'b';
				correct = 1;
			}
			if ((binordec[0] == 'd') || (binordec[0] == 'D')) {
				type = 'd';
				correct = 1;
			}
			if ((binordec[0] != 'b') && (binordec[0] != 'B') && 
				(binordec[0] != 'd') && (binordec[0] != 'D')) {
					printf("Sorry that was not an option, try again.\n");
					correct = 0;
			}
		}
	}
	
	if (type == 'b') {
		output = todec (input);
		printf("Converting binary to decimal. Answer is: %d\n", output);
	}
	if (type == 'd') {
		output = tobin (input);
		numtoolong = outputlength (output);
		if (numtoolong > 8) {
			printf("That is an invalid number!\n");
			exit(0);
		}
		printf("Converting decimal to binary. Answer is: %08d\n", output);
	}
}

int todec (int bin) {
	int leftover = 0, dec = 0, i = 1;
	while (bin != 0) {  
		leftover = bin % 10; 
      dec = dec + leftover * i;  
      i = i * 2;  
      bin = bin / 10;  
   }  
   return dec;  
}
	
int tobin (int dec) {
	int leftover, i = 1, bin = 0;  
	while (dec != 0) {  
		leftover = dec % 2;  
		dec = dec / 2;  
		bin = bin + leftover * i;  
		i = i * 10;  
	}
	return bin; 
 }

 //this function tests for the length of number
 //is not great that 8bits
int outputlength (int value){
	int len = 1;
	while (value > 9){ 
		len++; 
		value /= 10;
	}
	return len;
}
