/* Name: Andrew Creevey ID: 12236284 */
#include <stdio.h>
char option, yesno;
char continues();
char *stringcopy (char *output, char *input);
int stringlength (char *str1);
char *stringcat (char *input, char *output);
int stringcompare (char *str1, char *str2);

int main () {
	int result;
	char opt;
	char str1[80];
	char str2[80];
	yesno = 'Y';
	
	while(yesno == 'Y') {
		printf("Please select an option:\n");
		printf("A. Test the stringcopy function\n");
		printf("B. Test the stringlength function\n");
		printf("C. Test the stringcat function\n");
		printf("D. Test the stringcompare function\n");
		printf("Q. Quit\n");
		
		printf("\nYour choice: ");
		scanf("%c", &opt);
		getchar();
		//checks if uppercase
		if (opt == 'A' || 'B' || 'C' || 'D' || 'Q') {
			opt = opt - 32;
			//checks incorrect input
			if ((opt != 'A') && (opt != 'B') && (opt != 'C') && 
					(opt != 'D') && (opt != 'Q')) {
				printf("Sorry the information you entered was incorrect.\n\n");
			}
		}
		while(opt) {
			if (opt == 'A') {
				printf("Enter the string you wish to copy:\n");
				gets(str1);
				printf("The copied string is %s.\n\n", stringcopy (str2, str1));
				continues();
			}
			if (opt == 'B') {
				printf("Enter a string:\n");
				gets(str1);
				printf("The length of %s is %d.\n\n", str1, stringlength (str1));
				continues(); 
			}
			if (opt == 'C') {
				printf("Enter a string: ");
				gets(str1);
				printf("Enter the next string to add to it: ");
				gets(str2);
				printf("The concatenated string is %s.\n\n", stringcat(str1, str2));
				continues();
			}
			if (opt == 'D') {
				printf("Enter a string: ");
				gets(str1);
				printf("Enter the string to compare to it: ");
				gets(str2);
				result = stringcompare(str1, str2);
				
				if (result == 0) {
					printf("The strings are the same.\n\n");
				} 
				if (result == 1) {
					printf("The strings are not the same.\n\n");
				}
				continues();
			}
			if (opt == 'Q') {
				yesno = 'N';
				break;
			}
			printf("\n");
			break;
		}
	}
}
char continues() {
	printf("Do you wish to continue? Y or N: ");
	scanf("%c", &yesno);
	getchar();
	if ((yesno == 'y') || (yesno == 'n')) {
		yesno = yesno - 32; 
	}
	return yesno;
}
char *stringcopy (char *output, char *input) {
	int i;
	i = 0;
	while (input[i] != '\0') {
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return output;
}

int stringlength (char *str1) {
	int i, size;
	i = 0;
	size = 0;
	while (str1[i] != '\0') {
		i++;
		size++;
	}
	return size;
}
char *stringcat (char *input, char *output) {
	int i, j;
	i = 0;
	j = 0;
	while (input[i] != '\0') {
		i++;
	}
	while (input[i] == '\0') {
		input[i] = ' ';
		i++;
	}
	//marker: I have included the space to make it easier for
	//			 the user to read the concatenated string.
	while (output[j] != '\0') {
		input[i] = output[j];
		i++;
		j++;
	}
	input[i] = '\0';
	return input;
}
int stringcompare (char *str1, char *str2) {
	while (*str1 == *str2) {
		str1++;
		str2++;
		if (*str1 == '\0') {
			return 0;
		}
	}
	return 1;
}
