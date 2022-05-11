#include "stdio.h"
#include "math.h"

void Matrix(int max, int input[max][max]);
int Up_left(int max, int input[max][max]);

void Print(int max, int input[max][max]);

int main(void) {
    int max = 4;
    int input[max][max];

    Up_left(max, input);
    Print(max, input);
}

/*______________________________________________________________*/

int Up_left(int max, int array[max][max])
{
    int s = 1;
    int x = 0, y = 0;
    int i = 1, j = 0;

    while (s < (max * max)) {

        x = i - 1; y = i - 1;
        while (y < max - i) {
            array[x][y] = s;
            s++; y++;
        }

        while (x < max - i) {
            array[x][y] = s;
            s++; x++;
        }

        x = max - i; y = max - i;
        //printf("x = %d y = %d\n", x,y);
        while (y >= i) {
            array[max - i][y] = s;
            s++; y--;
        }

        while (x >= i) {
            array[x][j] = s;
            s++; x--;
            //printf("x = %d\n", x);
        }
        //printf("__\n");

        ++i; j++;
    }

    if (max % 2 != 0) {
        array[max / 2][max / 2] = s;
    }
}

void Print(int max, int input[max][max])
{
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
}