/* Name: Andrew Creevey ID: 12236284 */

#include <stdio.h>

int main() {

	unsigned char pcounter, memory[255], pregister[16] = {0};
	unsigned int temp;
	int i, one, two, three, four, threeandfour, mask1, mask2;
	FILE *f;

	temp = 0;
	i = 0;
	pcounter = 0;	 
	mask1 = 0xFF00;
	mask2 = 0X00FF;

	f = fopen("102-A2.txt", "r");

	while (fscanf (f, "%x", &temp) != EOF){   
		memory[i] = (temp & mask1) >> 8;
		memory[i + 1] = (temp & mask2);
		i = i + 2;
	}

	while (memory[pcounter] != 0xC0){
		printf ("%02X %X%02X - [", pcounter, memory[pcounter], memory[pcounter+1]);
		for (i = 0; i < 15; i++){
			printf ("%02X ", pregister[i]);
		}
		printf ("%02X]\n", pregister[15]);
		
		//Assigning variables and giving them values.
		one = (memory[pcounter] & 0xF0) >> 4;
		two = (memory[pcounter] & 0xF);
		three = (memory[pcounter + 1] & 0xF0) >> 4;
		four = (memory[pcounter + 1] & 0xF);
		threeandfour = (memory[pcounter + 1]);
		pcounter = pcounter + 2;
		
		//Instructions.
		if (one == 0x01){
			pregister[two] = memory[threeandfour]; 
		}
		else if (one == 0x02){
			pregister[two] = threeandfour;
		}
		else if (one == 0x03){
			pregister[threeandfour] = memory[two];
		}
		else if (one == 0x04){
			pregister[four] = pregister[three];
		}
		else if (one == 0x05){
			pregister[four] = pregister[two] + pregister[three];
		}
		else if (one == 0x07){
			pregister[four] = pregister[two] | pregister[three];
		}
		else if (one == 0x08){
			pregister[four] = pregister[two] & pregister[three];
		}
		else if (one == 0x09){
			pregister[four] = pregister[two] ^ pregister[three];
		}
		else if (one == 0x0A){                
			pregister[two] = (pregister[two] >> four) | (pregister[two] << 8 - four);
		}
		else if (one == 0x0B){
			if (pregister[two] == pregister[0]) {
				pcounter = threeandfour;
			}
		}
	}
	printf ("%02X C000 - [", pcounter);
		for (i = 0; i < 15; i++){
			printf ("%02X ", pregister[i]);
		}
	printf ("%02X]\n", pregister[15]);
}

