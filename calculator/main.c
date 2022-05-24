#include <stdio.h>
#define LEN 20

extern int addition(float num_1, float num_2);
extern int subtraction(float num_1, float num_2);
extern int multiplication(float num_1, float num_2);
extern int division(float num_1, float num_2);
extern int convert(char num[LEN]);
extern int Menu(void);

int main(void)
{
    return Menu();
}