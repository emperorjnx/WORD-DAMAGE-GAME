#include <stdio.h>
#include <time.h>
#include "GAMEPLAY.h"

int main()
{
char choice='\0';
int option = 0;

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

/*CHOICE OF PLAYERS*/
printf("            Play AGAINST ANOTHER PLAYER OR THE SYSTEM : \n");
printf("1. PLAYER\n2.COMPUTER\n\n");
printf("CHOICE : ");
scanf("%d",&option);
getchar();

clearscreen();
/* Main game */
printf("            BEGIN THE GAME (Y/N) : ");
choice = getchar();

if (choice=='Y' || choice=='y')
    {

        printf("\n\n%12sBEGINNING THE GAME!!!!!"," ");
        Sleep(4000);
        if(option == 1)
            playing_console();
        else
            comp_console();
    }
else
{
    printf("\nSEE YOU AGAIN\n");
}

clearscreen();
printf("\n\n%12sTHANKS FOR PLAYING!!"," ");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
Sleep(3000);
return 0;
}
