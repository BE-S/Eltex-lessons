#include "stdio.h"

int main(void) {
   int input[3][3]; 

   for (int i = 0; i < 3; ++i) {
     for (int i = 0; i < 3; ++i) {
        printf("[%d][%d]: ", i + 1, j + 1);
        scanf("%d", &input[i][j]);
     } 
   }

   for (int i = 0; i < 3; ++i) {
     for (int i = 0; i < 3; ++i) {
        printf("%d", &input[i][j]);
     } 
     printf("\n");
   }
}