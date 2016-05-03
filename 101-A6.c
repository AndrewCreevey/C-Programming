#include <stdio.h>
#include <math.h>
int i, error;
float avg, avg10, avg15, diff, sum;
float hour[6];
void checkwithin10pc();
void checkwithin15pc();
int main() {
	for (i = 0; i < 6; i++) {
		printf("Enter the readings for hour %d to 1dp: ", i+1);
		scanf("%f", &hour[i]);
		sum += hour[i];
	}
	
	avg = sum/6.0;
	avg10 = avg * 0.10;
	avg15 = avg * 0.15;
	
	printf("\nThe average is %.1f volts.\n", avg);
	printf("10%% = %.1f volts.\n", avg10);
	printf("15%% = %.1f volts.\n", avg15);
	
	checkwithin10pc();
	checkwithin15pc();
	
	printf("\n");
	
	if (!error) {
		printf("\nNo problems were encountered.\n");
	}
	return 0;
}

void checkwithin10pc(){
	for (i = 0; i < 6; i++) {
		diff = hour[i] - avg;
		if (diff > avg10) {
			error ++;
			if (error == 1) {
				printf("\nThe following problems occured:\n");
			}
			printf("%d. Voltage at hour %d was %.1f volts (difference of %1.1f volts).\n",
				error, i + 1, hour[i], diff);
		}
	}
}

void checkwithin15pc(){
	for (i = 1; i < 6; i++) {
		diff = hour[i] - hour[i-1];
		if (diff > avg15) {
			error++;
			if (error == 1) {
				printf("\nThe following problems occured:\n");
			}
			printf("%d. Voltage change from hour %d to hour %d was %.1f volts.",
				error, i, i + 1, diff);
		}
	}
}
