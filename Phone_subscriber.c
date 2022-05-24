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
            printf("�������� ��������.\n1. ���������� ���� ���������\n2. �������� ��������\n3. ����� �������� � ����\n4. �����\n");
            Print_border();

            printf("����: ");
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
    int i = 0, space = 17; //�� ���� ������ ���������� 17 ��������

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

    printf("�������� ������ ������\n1. �� �����\n2. �� ��������\n");

    int count = 0, ret = 0;

    Print_border();

    printf("����: ");
    scanf("%d", &number);

    fgets(value, LEN, stdin); //������ ���� �� �������� ��-�� �� ���������� ������
    printf("\n������� ���������� � ��������: ");
    fgets(value, LEN, stdin); //����

    Print_border();

    if (number == 1) {
        while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
            if (strcmp(name, value) == 0) {
                printf("\n������� ��������  ��� ��������\n");

                Print_without_N(phone); //������� �������� �� ���������� ������� \n
                Dynamic_space(phone); //������� ������� �������� ����� �������� ���� ��� "��� ��������"
                printf("%s", name);
                ret = 1; //������������ ������!
            }
        }
    }
    else if (number == 2) {
        while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
            if (strcmp(phone, value) == 0) {
                printf("\n������� ��������  ��� ��������\n");

                Print_without_N(phone); //������� �������� �� ���������� ������� \n
                Dynamic_space(phone); //������� ������� �������� ����� �������� ���� ��� "��� ��������"
                printf("%s", name);
                ret = 1; //������������ ������!
            }
        }
    }
    else {
        printf("������\n");
    }

    if (ret != 1) {
        printf("������� '");
        Print_without_N(value);
        printf("' �� ������\n");
    }

    memset(value, 0, sizeof(value)); //������� ���������� value
    fseek(subscriber_ptr, 0, SEEK_SET); //������� ������ subscriber_ptr
    fseek(phone_ptr, 0, SEEK_SET); //������� ������ phone_ptr
}

void Add_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr)
{
    fgets(name, LEN, stdin); //������ ���� �� �������� ��-�� �� ���������� ������

    printf("������� ��� ��������\n");
    fgets(name, LEN, stdin); //����
    fputs(name, subscriber_ptr);

        //��������� �������� ���������� � ����

        printf("������� ����� ��������\n");
    fgets(phone, LEN, stdin); //����
    fputs(phone, phone_ptr);  //��������� �������� ���������� � ����

    printf("\n��� ���������� ��������� � ���� ������������� ���������.\n");
}

void Print_all_subcriber(char name[LEN], char phone[LEN], FILE* subscriber_ptr, FILE* phone_ptr)
{
    printf("������� ��������  ��� ��������\n");

    while (fgets(name, LEN, subscriber_ptr) && fgets(phone, LEN, phone_ptr)) {
        Print_without_N(phone);  //������� �������� �� ���������� ������� \n
        Dynamic_space(phone); //������� ������� �������� ����� �������� ���� ��� "��� ��������"
        printf("%s", name);
    }

    Print_border();

    fseek(subscriber_ptr, 0, SEEK_SET);  //������� ������ subscriber_ptr
    fseek(phone_ptr, 0, SEEK_SET);  //������� ������ phone_ptr
}