/*Name: Andrew Creevey ID: 12236284 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void lowercase(char *x);
void display(char *x, int y, char *z);
void error(char *x);
int main (){
	printf("\t\t\t\t - Assignment 9 -\n");
	printf("\t       This program reads in two words and searches for all\n");
	printf("\t\t   occurrences of these words in the given file\n\n"); 
	char line[100], filename[40];
	char word[20], word1[20], first[20], word2[20], second[20];
	int i, j, wordcount1, wordcount2, linecount;	
	FILE *file;
	
	printf("Enter the first word: ");
   gets(word1);
	strcpy(first, word1); //Need both, 1 original, 1 to compare
   lowercase(first);
	
   printf("Enter the second word: ");
   gets(word2);
	strcpy(second, word2);
	lowercase(second);
	
	printf("Enter the name of the text file: ");
	gets(filename);
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("ERROR: File could not be opened.\n");
		return 0;
	}
	
	wordcount1 = 0;
	wordcount2 = 0;
	linecount = 0;
	while(fgets(line, 100, file)){
		linecount++;				
	   i = 0;
		j = 0;
      while(line[i] != '\0'){
			if (line[i] != ' ' && line[i] != '.' && line[i] != '\n'){
				word[j] = line[i];
				j++;
			} else { //if there is a ' ' or '.' or '\0' at line[i]
				word[j] = '\0';
				j = 0;
				lowercase(word); //Takes all capitals out of test
				if((strcmp(word, first)) == 0){ 
					wordcount1++;
					if (wordcount1 == 1) {
						display(word1, linecount, line);
					}
				} else {
					if ((strcmp(word, second)) == 0){
						wordcount2++;
						if (wordcount2 == 1) {
							display(word2, linecount, line);
						}
					}
				}
			}
			i++;
		}      
   }
	fclose(file);
	if(wordcount1 > 0){
		printf("The word \'%s\' appears %d time(s) in the file.", word1, wordcount1);
	} else {
		error(word1);
	}
	if(wordcount2 > 0) {
		printf("\nThe word \'%s\' appears %d time(s) in the file.", word2, wordcount2);
	} else { 
		error(word2); 
	}
}

void lowercase(char *x){ 
   int i, len;
	len = strlen(x);
	for (i = 0; i < len; i++) {
		if ((x[i] >= 'A') && (x[i] <= 'Z')) {
			x[i] = x[i] + 32;
		} else {
			x[i] = x[i];
		}
	}
}
void display(char *x, int y, char *z) {
	printf("The word \'%s\' first appears in line %d which is:\n%s\n",
		x, y, z); 
}
void error(char *x) {
	printf("The word \'%s\' does not appear in the file.", x);
}
