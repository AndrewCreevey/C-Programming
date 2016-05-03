/*Name: Andrew Creevey	ID: 12236284*/
#include <stdio.h>
int judges, count;
float score, min, max, total;
int main(){
	
	count = 1, score = 0.0, max = -1.0, min = 11.0, total = 0.0;
	printf("\t Please enter the number of judges (Between 4 and 8): ");
	scanf("%d", &judges);
	
	while ((judges < 4) || (judges > 8)) {
		printf("\n\t Sorry the number you have entered is invalid, please try again: ");
		scanf("%d", &judges);
	}
	
	printf("\n");
	
	while (count <= judges) {
		printf("\t Please enter the score for judge %d (Between 0.0 and 10.0): ", count);
		scanf("%f", &score);
		while ((score < 0.0) || (score > 10.0)){
			printf("\n\t Sorry that score is invalid, please try again: ");
			scanf("%f", &score);
		}
		if (score < min){
			min = score;
		}
		if (score > max) {
			max = score;
		}
		total = total + score;
		count ++;
	}
	total = total - max - min;
	total /= (judges - 2);
	printf("\n\t The highest mark was %1.1f\n", max);
	printf("\t The average mark was %1.1f\n", total);
	printf("\t The lowest mark was %1.1f\n", min);
}
