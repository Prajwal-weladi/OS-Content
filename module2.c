#include<stdio.h>
#include<stdlib.h>

int main()
{
    char card_data[40];
    printf("Enter Card Data of 40 Charachters: ");
    gets(card_data);

    printf("%s",card_data);
    fflush(stdin);

    FILE *fp;

    fp = fopen("module2.txt", "w");
    fprintf(fp, card_data);

    fclose(fp);

    system("cls");
    printf("Data is written in file successfully!!\n");

    fp = fopen("module2.txt", "r");

    char data = fgetc(fp);

    printf("Data in File: ");
    while(data != EOF){
        printf("%c", data);
        data = fgetc(fp);
    }

    fclose(fp);

    return 0;
}