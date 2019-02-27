#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "crossword.h"

/* defining the max health for the characters */
#define HEALTH 100

int main()
{
char choice='\0';

printf("%13s WELCOME TO OUR GAME\n\n\n\n"," ");

/* Help section part of the game */
printf("      DO YOU WANT TO VIEW THE HELP SECTION (Y/N) : ");
choice = getchar();
getchar();
if (choice=='Y' || choice=='y')
    {
        helpbox();
        choice='\0';
    }
clearscreen();

/* Main game */
printf("            BEGIN THE GAME (Y/N) : ");
choice = getchar();

if (choice=='Y' || choice=='y')
    {
        printf("\n\n%12sBEGINNING THE GAME!!!!!"," ");
        Sleep(4000);
        playing_console();
    }
else
{
    printf("THANKS FOR PLAYING!!");
}

clearscreen();
printf("\n\n%12sTHANKS FOR PLAYING!!"," ");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
Sleep(3000);
return 0;
}



/* terminal clearing function */
void clearscreen()
{
    system("cls");
}

/* Help section function */
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
    getch();
    clearscreen();

}

/* game handling function */
void playing_console()
{
    int health_1=HEALTH ,health_2=HEALTH;
    char plWord[10];
    int dam_1=0 ,dam_2=0;
    while(health_1>0 && health_2>0)
    {
    clearscreen();
    crossword();

    printf("\nPlayer - 1\n");
    health_display(health_1);

    printf("\nPlayer - 2\n");
    health_display(health_2);

    printf("\n\nEnter your word\n\n");
    printf("Player - 1 : ");
    scanf("%s",plWord);
    dam_1=damage_analyser(plWord);
    printf("\nPlayer - 1 does %d damage\n",dam_1);

    printf("\n\nEnter your word\n\n");
    printf("Player - 2 : ");
    scanf("%s",plWord);
    dam_2=damage_analyser(plWord);
    printf("\nPlayer - 2 does %d damage\n",dam_2);

    health_1 -= dam_2;
    health_2 -= dam_1;
    Sleep(2000);
    }
    clearscreen();
    printf("\n\n\n\n          THE WINNER IS !!!!\n          ");
    health_1>health_2?printf("PLAYER - 1"):printf("PLAYER - 2");
    Sleep(3000);
}


void health_display(int n)
{
    for(int i=0;i<=(n/2);i++)
    {
        printf("#");
    }
    printf("\n");
}

/* Damage Analysing function */
int damage_analyser(char s[])
{
    char epic_letter[4]={'Q','Z','Y','X'};
    int point=0,damage=0,i=0,j=0;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<4;j++)
        {
            if(s[i]==epic_letter[j])
                point++;
        }
    }
    damage=(strlen(s)+point)*5;
    return damage;
}


int checker(char s[])
{
    return 0;
}
