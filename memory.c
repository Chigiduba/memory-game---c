#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*this function generates an array of random values that will be used as
indexes of the cards generated from the next function*/
int *shuffle ( int n )
{
  int i;
  int *r = malloc ( n * sizeof(int) );

  /* initial range of numbers */
  for( i=0; i < n; i++ )
  {
    r[i]=i+1;
  }

  for (int i = n-1; i >= 0; --i)
  {
    /* generate a random number [0, n-1] */
    int j = rand() % (i+1);

    /* swap the last element with element at random index */
    int temp = r[i];
    r[i] = r[j];
    r[j] = temp;
  }

  return r;
}

/*return a pointer to the generated array? Uses the pairs generated from ^ */
char *generateGame ()
{
  int level;
  int i;

  printf ( "What level?" );
  scanf("%d", &level);

  int *pairs = shuffle ( level*2 ); /* *2 because we want pairs of cards*/

  char *symbols = malloc ( level * 2 * sizeof(int));

  /*we prevoiously generated an array of random values.*/
  /*this for loop takes those random values two by two and assigns to them
  symbols, generating the pairs of cards to be found*/
  for ( i = 0; i < level * 2; i += 2 )
  {
     symbols[pairs[i]] = 65 + i; /*assigns letters in order to non ordered*/
     symbols[pairs[i+1]] = 65 + i; /*see above comment*/
  }

  return symbols;
}

/*function to manage one turn*/
int turn ( char *cards )
{
  int choice1;
  int choice2;

  printf("First card?\n");
  scanf("%d", &choice1 );
  printf("Second card?\n");
  scanf("%d", &choice2 );

  if ( cards[choice1] == cards[choice2] )
  {
    printf("Correct!\n");
    return 1; /*1 point for correct match*/
  }
  else
  {
    printf("Incorrect\n");
    return 0; /*0 points for incorrect match*/
  }
}

/*function to play the entire game*/
int playGame ()
{
  char *game = generateGame();
  int points = 0;
  int i;

  for ( i=0; i < sizeof(game); i++) /*sizeof doesnt need to be divided by the size of char since this is 1*/
  {
    printf("%c", game[i]);
  }

  while ( points < sizeof(game)/2 )
  {
    points += turn(game);
  }

  return points;
}

int main()
{
  char userin;

  do
  {
    playGame();
    printf("play again?");
    scanf(" %c", &userin );
  }while( userin == 'y');

  return 0;
}
