#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/* defining the max health for the characters */
#define HEALTH 100

struct words
{
    char word[10];
};

void crossword(char *a)
{
    srand(time(0));
    random(a);
	int i, j, k=0;
	/* Initialising the row and column */
	for (i = 0; i <= 17; i++)
	{
		for (j = 1; j < 18; j++)
		{
			if (i > 0 && i < 2 || i>4 && i < 6 || i>8 && i < 10 || i>12 && i < 14 || i>16 && i < 18 || i >= 2 && i <= 18 && j == 1 || i >= 2 && i <= 18 && j == 5 || i >= 2 && i <= 18 && j == 9 || i >= 2 && i <= 18 && j == 13 || i >= 2 && i <= 18 && j == 17)
			{
				printf("* ");
			}
			else if (i == 3 && j == 3 || i == 3 && j == 7 || i == 3 && j == 11 || i == 3 && j == 15 ||
				i == 7 && j == 3 || i == 7 && j == 7 || i == 7 && j == 11 || i == 7 && j == 15 ||
				i == 11 && j == 3 || i == 11 && j == 7 || i == 11 && j == 11 || i == 11 && j == 15 ||
				i == 15 && j == 3 || i == 15 && j == 7 || i == 15 && j == 11 || i == 15 && j == 15)
			{
				printf("%c ",a[k]);
				k++;
			}

			else
			{
				printf("  ");
			}

		}
		printf("\n");

	}

}

/* Generates random letters when called */
void random(char *a)
{
    char consonent[]={'Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    char vowel[]={'A','I','O','U','E'};
    srand(time(NULL));
    int i=0,j=0;
    while(j<16)
    {
        if(i==0||i==2||i==1)
            {
                a[j]=consonent[rand()%21];
                i++;
            }

        if(i == 3)
            {
                a[j]=vowel[rand()%5];
                i=0;
            }
    j++;
    }
    a[17]='\0';
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
    int health_1 = HEALTH, health_2 = HEALTH;
    struct words plWord[1000]; int i = -1,j, flag = 0;
    char a[100];
    int dam_1=0 ,dam_2=0;

    while(health_1>0 && health_2>0)
    {
    clearscreen();
    crossword(a);

    printf("\nPlayer - 1\n");
    health_display(health_1);

    printf("\nPlayer - 2\n");
    health_display(health_2);

    printf("\n\nEnter your word\n\n");
    i++;
    printf("Player - 1 : ");
    scanf("%s",plWord[i].word);

    for( j=0; j<i ; j++)
    {
        if( strcmp(plWord[j].word, plWord[i].word)==0)
            {
                flag = 1;
                break;
            }
    }

    if(!checker_array(a,plWord[i].word))
        printf("\nPlease Enter a word, Using letters from the matrix!!\n");
    else if(!checker(plWord[i].word))
        printf("\nINVALID WORD!!\n");
    else if(flag)
    {
        printf("\nSorry that word has already been used\nRESURRECTED DAMAGE you lose 10 bars of HP!!");
        health_1-=10;
        flag = 0;
    }
    else
    {
    dam_1=damage_analyser(plWord[i].word);
    printf("\nPlayer - 1 does %d damage\n",dam_1);
    }

    printf("\n\nEnter your word\n\n");
    i++;
    printf("Player - 2 : ");
    scanf("%s",plWord[i].word);

    for( j=0; j<i ; j++)
    {
        if( strcmp(plWord[j].word, plWord[i].word)==0)
            {
                flag = 1;
                break;
            }
    }

    if(!checker_array(a,plWord[i].word))
        printf("\nPlease Enter a word, Using letters from the matrix!!\n");
    else if(!checker(plWord[i].word))
        printf("\nINVALID WORD!!\n");
    else if(flag)
    {
        printf("\nSorry that word has already been used\nRESURRECTED DAMAGE you lose 10 bars of HP!!");
        health_2-=10;
        flag = 0;
    }
    else
    {
    dam_2=damage_analyser(plWord[i].word);
    printf("\nPlayer - 2 does %d damage\n",dam_1);
    }

    health_1 -= dam_2;
    health_2 -= dam_1;
    Sleep(2000);
    }
    clearscreen();
    printf("\n\n\n\n          THE WINNER IS !!!!\n          ");
    health_1>health_2?printf("PLAYER - 1"):printf("PLAYER - 2");
    Sleep(3000);
}

/* Health display function */
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

/*Word in array checker*/
int checker_array(const char *a, const char *word)
{
    int flag = 0;
    int m = strlen(a), n = strlen(word);
    for( int i=0; i<n ; i++ )
    {
        for( int j=0; j<m ; j++)
        {
            if(word[i] == a[j])
                flag = 1;
        }
        if (flag == 1)
            flag=0;
        else
            return 0;
    }
    return 1;
}

/*Word checking function*/
int checker(const char word[])
{
    FILE *dictionary;
    int line, col;
    line = col = -1;
    dictionary = fopen("dictionary.txt", "r");

    //checking whether the file exists or not
    if (dictionary == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");
        exit(EXIT_FAILURE);
    }

    char str[1000];
    char *pos;

    while ((fgets(str, 1000, dictionary)) != NULL)
    {
        line += 1;
        pos = strstr(str, word);

        if (pos != NULL)
        {
           col = (pos - str);
            break;
        }
    }

    if (col == -1)
        line = -1;


    if (line != -1)
        {
        //if the word is present in the dictionary
        fclose(dictionary);
        return 1;
        }
    else
        {
        //if the word is present in the dictionary
        fclose(dictionary);
        return 0;
        }
}

void comp_console()
{
    int health_1 = HEALTH, health_2 = HEALTH;
    struct words plWord[1000]; int i = -1,j, flag = 0;
    char a[]= {'A','E','I','O','Q','W','R','B','T','H','S','P','L','M','G','Y','\0'};
    int dam_1=0 ,dam_2=0;

    while(health_1>0 && health_2>0)
    {
    clearscreen();
    comp_crossword(a);

    printf("\nPlayer\n");
    health_display(health_1);

    printf("\nCOMPUTER\n");
    health_display(health_2);

    printf("\n\nEnter your word\n\n");
    i++;
    printf("Player : ");
    scanf("%s",plWord[i].word);

    for( j=0; j<i ; j++)
    {
        if( strcmp(plWord[j].word, plWord[i].word)==0)
            {
                flag = 1;
                break;
            }
    }

    if(!checker_array(a,plWord[i].word))
        printf("\nPlease Enter a word, Using letters from the matrix!!\n");
    else if(!checker(plWord[i].word))
        printf("\nINVALID WORD!!\n");
    else if(flag)
    {
        printf("\nSorry that word has already been used\nRESURRECTED DAMAGE you lose 10 bars of HP!!");
        health_1-=10;
        flag = 0;
    }
    else
    {
    dam_1=damage_analyser(plWord[i].word);
    printf("\nPlayer does %d damage\n",dam_1);
    }

    printf("\n\nEnter your word\n\n");
    i++;
    printf("COMPUTER : ");
    Sleep(1000);
    comp_word(plWord[i].word);
    printf("%s\n",plWord[i].word);

    for( j=0; j<i ; j++)
    {
        if( strcmp(plWord[j].word, plWord[i].word)==0)
            {
                flag = 1;
                break;
            }
    }

    if(flag)
    {
        printf("\nSorry that word has already been used\nRESURRECTED DAMAGE you lose 10 bars of HP!!");
        health_2-=10;
        flag = 0;
    }
    else
    {
    dam_2=damage_analyser(plWord[i].word);
    printf("\nCOMPUTER does %d damage\n",dam_1);
    }

    health_1 -= dam_2;
    health_2 -= dam_1;
    Sleep(2000);
    }
    clearscreen();
    printf("\n\n\n\n          THE WINNER IS !!!!\n          ");
    health_1>health_2?printf("PLAYER"):printf("COMPUTER");
    Sleep(3000);
}

/* CROSSWORD */
void comp_crossword(char *a)
{
    srand(time(0));
    array_scatter(a);

	int i, j, k=0;
	/* Initialising the row and column */
	for (i = 0; i <= 17; i++)
	{
		for (j = 1; j < 18; j++)
		{
			if (i > 0 && i < 2 || i>4 && i < 6 || i>8 && i < 10 || i>12 && i < 14 || i>16 && i < 18 || i >= 2 && i <= 18 && j == 1 || i >= 2 && i <= 18 && j == 5 || i >= 2 && i <= 18 && j == 9 || i >= 2 && i <= 18 && j == 13 || i >= 2 && i <= 18 && j == 17)
			{
				printf("# ");
			}
			else if (i == 3 && j == 3 || i == 3 && j == 7 || i == 3 && j == 11 || i == 3 && j == 15 ||
				i == 7 && j == 3 || i == 7 && j == 7 || i == 7 && j == 11 || i == 7 && j == 15 ||
				i == 11 && j == 3 || i == 11 && j == 7 || i == 11 && j == 11 || i == 11 && j == 15 ||
				i == 15 && j == 3 || i == 15 && j == 7 || i == 15 && j == 11 || i == 15 && j == 15)
			{
				printf("%c ",a[k]);
				k++;
			}

			else
			{
				printf("  ");
			}

		}
		printf("\n");

	}

}

/*ARRAY SCATTERER*/
void array_scatter(char *a)
{
    int i,j=0;
    char fake[16];

    for(i=0;i<16;i++)
    {
        fake[i] = a[rand()%(16-i)];
        for(j=0;j<16;j++)
        {
            if(fake[i]==a[j])
            {
                for(int c = j;c<16;c++)
                {
                    a[c]=a[c+1];
                }
            }
        }
    }

    for(i=0;i<16;i++)
        a[i]=fake[i];
}

/* Comp words */
void comp_word(char *a)
{
    char possible_words[100][100] =
    {"POLYMER","HEAL","BREATH","PLATE","BLAME","YES","LOW","WORM","LOST","LOSE",
    "WAITER","TOWER","MAY","THIS","GLOW","PLAY","SHIT","PART","WAR","RAW","WORTH",
    "HATE","HAY","GAY","LAY","LAME","EAT","TEA","MIGHT","LIGHT","STEW","WEST","SHIT",
    "SPIT","TIPS","TIP","HIPS","HIP","SOAP","SHIP","SPERM","WRITE","PALMISTRY","BEST","REST",
    "WASTE","YEAST","LEAST","LASER","BREAST","REST","BRA","BRO","GRIM","MIRE","MAYOR","MAYBE",
    "WORTHY","LAWYER","LAW","LOST","LAST","PLOT","HOT","LOT","ABORT","ABSORB","AGLET"};
    strcpy(a,possible_words[rand()%68]);
}
