#include <stdio.h>
#include <stdlib.h>
#define LEN 20

/*___Function's print___*/

void print_border()  //Вывод разделительной полосы
{
    for (int i = 0; i < 30; ++i)
    {
        printf("_");
    }
    printf("\n");
}

void print_result(float res) //Вывод результата
{
    printf("\nВаш результат: %f\n", res);
}

/*___Arithmetic's operation___*/

float addition(float num_1, float num_2) //Операция сложения
{
    return num_1 += num_2;
}

float subtraction(float num_1, float num_2) //Операция вычитания
{
    return num_1 -= num_2;
}

float multiplication(float num_1, float num_2) //Операция умножения
{
    return num_1 *= num_2;
}

float division(float num_1, float num_2) //Операция деления
{
    return num_1 /= num_2;
}

float convert_float(char num[LEN]) //Конвертирование массива char в float 
{
    float res;
    return res = atof(num);
}

int convert_int(char num[LEN]) //Конвертирование массива char в int
{
    int res;
    return res = atoi(num);
}

int Menu(void) {
    char choise[LEN]; //Выбор действия
    char num1[LEN], num2[LEN]; //Переменные для ввода

    for (;;)
    {
        printf("\n1. Сумма\n2. Вычитание\n3. Умножение\n4. Деление\n");
        print_border();

        printf("Выбирите действие: ");
        fgets(choise, LEN, stdin);

        print_border();

        printf("Введите первое значение: ");
        fgets(num1, LEN, stdin);

        printf("Введите второе значение: ");
        fgets(num2, LEN, stdin);


        switch (convert_int(choise)) {
        case 1:
            print_result(addition(convert_float(num1), convert_float(num2)));
            break;
        case 2:
            print_result(subtraction(convert_float(num1), convert_float(num2)));
            break;
        case 3:
            print_result(multiplication(convert_float(num1), convert_float(num2)));
            break;
        case 4:
            print_result(division(convert_float(num1), convert_float(num2)));
            break;
        }

        print_border();
    }
}