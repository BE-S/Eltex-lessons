#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 40


void Print_border();
void Print_without_N(char str[LEN]);
void Find_subcriber(int number, char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr);
void Add_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr);
void Print_all_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr);

int main(void)
{
    FILE* subscriber_ptr;
    subscriber_ptr = fopen("Subscriber", "a+");

    FILE* phone_ptr;
    phone_ptr = fopen("Phone", "a+");

    if (subscriber_ptr != NULL && phone_ptr != NULL) {
        char name[LEN];
        char phone[LEN];

        for (int number;;) {
            Print_border();
            printf("Выбирите действие.\n1. Посмотреть всех абонентов\n2. Добавить абонента\n3. Найти абонента в базе\n4. Выход\n");
            Print_border();

            printf("Ввод: ");
            scanf("%d", &number);

            Print_border();

            switch (number) {
            case 1: Print_all_subcriber(name, phone, subscriber_ptr, phone_ptr); break;
            case 2: Add_subcriber(name, phone, subscriber_ptr, phone_ptr); break;
            case 3: Find_subcriber(number, name, phone, subscriber_ptr, phone_ptr); break;
            case 4: return 0;
            }
        }
    }
}

void Print_border()
{
    for (int border = 0; border < 30; ++border) {
        printf("_");
    }
    printf("\n");
}

void Print_without_N(char str[LEN])
{
    for (int i = 0; str[i] != '\n'; ++i) {
        printf("%c", str[i]);
    }
}

void Dynamic_space(char str[LEN]) {
    int i = 0, space = 17; //На один символ приходится 17 пробелов

    while (str[i] != '\n') {
        ++i; --space;
    }

    while (space >= 0) {
        printf(" ");
        --space;
    }
}

void Find_subcriber(int number, char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr)
{
    char value[LEN];

    Print_border();

    printf("Выберите способ поиска\n1. По имени\n2. По телефону\n");

    int count = 0, ret = 0;

    Print_border();

    printf("Ввод: ");
    scanf("%d", &number);

    fgets(value, LEN, stdin); //Первый ввод не работает из-за не очищенного буфера
    printf("\nВведите информацию о абоненте: ");
    fgets(value, LEN, stdin); //ввод

    Print_border();

    if (number == 1) {
        while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
            if (strcmp(name, value) == 0) {
                printf("\nТелефон абонента  Имя абонента\n");

                Print_without_N(phone); //Выводит значение до служебного символа \n
                Dynamic_space(phone); //Выводит столько пробелов чтобы значение было под "Имя абонента"
                printf("%s", name);
                ret = 1; //Пользователь найден!
            }
        }
    }
    else if (number == 2) {
        while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
            if (strcmp(phone, value) == 0) {
                printf("\nТелефон абонента  Имя абонента\n");

                Print_without_N(phone); //Выводит значение до служебного символа \n
                Dynamic_space(phone); //Выводит столько пробелов чтобы значение было под "Имя абонента"
                printf("%s", name);
                ret = 1; //Пользователь найден!
            }
        }
    }
    else {
        printf("Ошибка\n");
    }

    if (ret != 1) {
        printf("Абонент '");
        Print_without_N(value);
        printf("' не найден\n");
    }

    memset(value, 0, sizeof(value)); //Очистка переменной value
    fseek(subscriber_ptr, 0, SEEK_SET); //Очистка буфера subscriber_ptr
    fseek(phone_ptr, 0, SEEK_SET); //Очистка буфера phone_ptr
}

void Add_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr)
{
    fgets(name, LEN, stdin); //Первый ввод не работает из-за не очищенного буфера

    printf("Введите ФИО абонента\n");
    fgets(name, LEN, stdin); //Ввод
    fputs(name, subscriber_ptr);

        //Занесение значения переменной в файл

        printf("Введите номер абонента\n");
    fgets(phone, LEN, stdin); //Ввод
    fputs(phone, phone_ptr);  //Занесение значения переменной в файл

    printf("\nДля вступления изменений в силу перезагрузите программу.\n");
}

void Print_all_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr)
{
    printf("Телефон абонента  Имя абонента\n");

    while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
        Print_without_N(phone);  //Выводит значение до служебного символа \n
        Dynamic_space(phone); //Выводит столько пробелов чтобы значение было под "Имя абонента"
        printf("%s", name);
    }

    Print_border();

    fseek(subscriber_ptr, 0, SEEK_SET);  //Очистка буфера subscriber_ptr
    fseek(phone_ptr, 0, SEEK_SET);  //Очистка буфера phone_ptr
}