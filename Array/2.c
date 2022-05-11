#include "stdio.h"

int main(void) {
   int input[5]; 
   int temp;

   for (int i = 0; i < 5; ++i) {
	printf("%d: ", i);
	scanf("%d: ", input[i]);
   }

   for (int i = 0; i < 5; ++i) {
     for (int j = i + 1; j < 5; ++j) {
        tmp = input[i];
	input[i] = input[j];
	input[j] = tmp;
     } 
   }

   for (int i = 0; i < 5; ++i) {
	printf("%d ", input[i]);
   }
}