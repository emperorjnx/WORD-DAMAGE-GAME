#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void clearscreen()
{
    system("cls");
}




void helpbox()
{
    FILE *help;
    char c;

    help = fopen("helpbox.txt", "r");
    if (help == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    clearscreen();
    c = fgetc(help);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(help);
    }

    fclose(help);
    _getch();
    clearscreen();

}





int main()
{
char choice='\0';

printf("%10s WELCOME TO OUR GAME\n\n\n\n"," ");
printf("DO YOU WANT TO VIEW THE HELP SECTION (Y/N) : ");
choice = getchar();
getchar();

if (choice=='Y' || choice=='y')
    {
        helpbox();
        choice='\0';
    }

clearscreen();
printf("            BEGIN THE GAME (Y/N) : ");
choice = getchar();

if (choice=='Y' || choice=='y')
    {
        printf("\n\n%10sBEGINNING THE GAME!!!!!"," ");
        Sleep(4000);
        clearscreen();
    }
else
{
    printf("THANKS FOR PLAYING!!");
    exit(0);
}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}

