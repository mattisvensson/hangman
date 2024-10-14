#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char getLetter();
void checkLetter(char letter, const char *word, char *revealedWord);
void start(char *word);
bool isFinished(char *revealWord);

void main()
{
  char word[100];

  start(word);

  int length = strlen(word);

  char revealedWord[length + 1];
  char guessedLetters[26];

  for (int i = 0; i < length; i++)
  {
    revealedWord[i] = '_';
  }
  revealedWord[length] = '\0';

  printf("%s\n", revealedWord);


  while(!isFinished) {
    char letter = getLetter();
    checkLetter(letter, word, revealedWord);
    printf("%s\n", revealedWord);
  }

}

void start(char *word) {
  printf("Welcome to HANGMAN\n");
  printf("Please enter a word\n");

  scanf("%99s", word);

  printf("\n\n");
  printf("Great, let's play hangman!\n");
}

char getLetter()
{
  char letter;
  printf("Please enter a letter.\n");
  scanf(" %c", &letter);

  return letter;
}

void checkLetter(char letter, const char *word, char *revealedWord)
{
  int length = strlen(word);
  for (int i = 0; i < length; i++)
  {
    if (word[i] == letter)
    {
      revealedWord[i] = letter;
    }
  }
}

bool isFinished(char *revealedWord) {
  int length = strlen(revealedWord);

  for (int i = 0; i < length; i++)
  {
    if (revealedWord[i] == '_')
      return false;
  }
  return true;
}
