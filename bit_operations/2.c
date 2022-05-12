#include "stdio.h"
#include "locale.h"

void Change_byte(char* ptr);
void Print(char* ptr);

int main(void)
{
    setlocale(0, "rus");

    int number_default = 0xDDCCBBAA;

    char* ptr;

    ptr = &number_default;

    Print(ptr);

    Change_byte(ptr);

    Print(ptr);
}

void Change_byte(char* ptr)
{
    int byte, number_substitution;

    for (;;) {
        printf("Введите значение байта: ");
        scanf("%d", &number_substitution);

        if (number_substitution <= 99 || number_substitution >= 99) {
            break; break;
        }
        else {
            printf("Значение байта не может превышать двух символов\n");
        }
    }

    for (;;) {
        printf("Введите номер байта для его замены: ");
        scanf("%d", &byte);

        if (byte < 4) {
            ptr += byte;
            *ptr = number_substitution;
            ptr -= byte;
            break;  break;
        }
        else {
            printf("Ошибка! Количество не превышает четырёх.\n");
        }
    }
}

void Print(char* ptr)
{
    for (int i = 0; i < 4; ++i, ++ptr) {
        printf("%d ", *ptr);
    }

    printf("\n");
}