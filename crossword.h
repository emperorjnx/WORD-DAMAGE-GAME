#include <stdio.h>
#include <time.h>
#include <time.h>

void crossword()
{
    srand(time(0));
	int i, j, k=0;
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
				random(1,k);
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

random(int n, int k)
{
	char consonent[] = { 'Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
	char vowel[] = { 'A','I','O','U','E' };
	int i = 0, j = 0;
	while (j < n) {
		if ((k%5) == 0)
        {
			printf("%c ", vowel[rand() % 5]);
			i++;
		}
		else
        {
            printf("%c ", consonent[rand() % 21]);

			--i;
		}
		j++;
	}
}
