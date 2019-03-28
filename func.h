#include "GAMEPLAY.c"
#include "logo.c"

void logo();

void crossword(char *a);

/* Generates random letters when called */
void random(char *a);

void audio_sync(char *a);

void audio_async(char *a);

void audio_stop();

/* terminal clearing function */
void clearscreen();

/* Help section function */
void helpbox();

/* game handling function */
void playing_console();

/* Health display function */
void health_display(int n);

/* Damage Analysing function */
int damage_analyser(char s[]);

/*Word in array checker*/
int checker_array(const char *a, const char *word);

/*Word checking function*/
int checker(const char word[]);

void comp_console();

/* CROSSWORD */
void comp_crossword(char *a);

/*ARRAY SCATTERER*/
void array_scatter(char *a);

/* Comp words */
void comp_word(char *a);