/* Name: Andrew Creevey ID: 12236284*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct contact {
	char name[180];
	char phone[20];
};
void openfile();
void searchnames ();
void displaynames ();
contact getdetails (char *s);

struct contact phonelist[200];
char line[200];
int linecount;

int main () {
	char option;
	openfile();
	while (true) {
		printf("A. Search for a name\n");
		printf("B. Display all names\n");
		printf("Q. Quit\n");
		printf("Your choice: ");
		scanf("%c", &option);
		getchar();
		//checks for input errors
		if ((option != 'A') && (option != 'B') && (option != 'Q')) {
			option = option - 32;
			if ((option != 'A') && (option != 'B') && (option != 'Q')) {
				printf("ERROR: Incorrect input.\n");
			}
		}
		if (option == 'A') {
			searchnames ();
		}
		if (option == 'B') {
			displaynames ();
		}
		if (option == 'Q') {
			break;
		}
		printf("\n");
	}
}
struct contact getdetails (char *s) { 
	struct contact temp;
	int i, j, k;
	i = 0, j = 0, k = 0;
	while (s[i] != ';') {
		temp.name[i] = s[i];
		i++;
	}
	temp.name[i] = '\0';
	i++;
	while(s[i] != '\0') {
		temp.phone[j] = line[i];
		i++;
		j++;
	}
	temp.phone[j] = '\0';
	return temp;
}
void searchnames () {
	char searchname[50];
	int i, found = 0, result, len, space = 0;
	printf("\nEnter a name to search for: ");
	gets (searchname); 
	len = strlen (searchname);
	for (i = 0; i < len; i++) {
		if (searchname[i] == ' ') {
			space++;
		}
	}
	if (space == 0) {
		printf("ERROR: Input needs 2 names with a space in between.\n");
	}
	for(i = 0; i < linecount; i++) {
		result = strcmp(phonelist[i].name, searchname);
		if (result == 0) {
			printf("The phone number of %s is %s", phonelist[i].name, phonelist[i].phone);
			found = 1;
			break;
		}
	}
	if (found == 0) { 
		printf("ERROR: The name '%s' is not in the list.\n", searchname);
	}
}
void displaynames () {
	int i, j;
	struct contact temp;
	for (i = 0; i < linecount; i++) {
		for (j = 0; j < linecount - 1; j++) {
			if (strcmp (phonelist[j].name, phonelist[j+1].name) > 0) {
				temp = phonelist[j];
				phonelist[j] = phonelist[j+1];
				phonelist[j+1] = temp;
			}
		}
	}
	printf("\nThe phonelist consists of:\n");
	for (i = 0; i < linecount; i++) {
		printf("%s\n", phonelist[i].name);
	}
}
void openfile() {
	FILE *f;
	char filename[50];
	int i;
	f = fopen("phonebook.txt", "r");
	/*printf("Enter the file name: ");
	gets (filename); 			//have removed for purpose of testing
	f = fopen (filename, "r");*/
	if (f == NULL) {
		printf("\nERROR: Can not open %s.\n", filename);
		exit (1);
	}
	i = 0;
	while (fgets (line, 200, f) != NULL) {
		phonelist[i] = getdetails (line);
		i++;
	}
	linecount = i;
	fclose (f);
}
