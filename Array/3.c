#include "stdio.h"

void Matrix(int max, int input[max][max])
{
   for (int i = 0; i < max; ++i) {
      for (int j = 0; j < max; ++j) {
         if (i + j > 1) {
	   input[i][j] = 1;
	 } else {
	   input[i][j] = 0;
	 }
      }
   }
}

void Print(int max, int input[max][max]) 
{
   for (int i = 0; i < max; ++i) {
      for (int j = 0; j < max; ++j) {
         printf("%d ", input[i][j]);
      }
     printf("%d ");
   }
}

int main(void) {
   int max = 3;
   int input[max][max];
   
   Matrix(max, input);
   Print(max, input);
}