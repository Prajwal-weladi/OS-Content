#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;

    fp = fopen("file1.txt", "w");

    char text[100];

    printf("Enter Text: ");
    gets(text);

    fprintf(fp, text);

    fclose(fp);

    system("cls");
    printf("Data is written in file successfully!!\n");

    fp = fopen("file1.txt", "r");

    char data = fgetc(fp);

    printf("Data in File: ");
    while(data != EOF){
        printf("%c", data);
        data = fgetc(fp);
    }

    fclose(fp);

    return 0;
}