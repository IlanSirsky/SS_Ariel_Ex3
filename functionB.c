#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"

#define TXT 1024
#define WORD 30

//B functions
char *getAtbash(char *word)
{
    char *atbash = malloc(strlen(word));
    for (size_t i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        if (islower(c))
        {
            atbash[i] = 'z' - c + 'a';
        }
        else if (isupper(c))
        {
            atbash[i] = 'Z' - c + 'A';
        }
        else
            continue;
    }
    return atbash;
}

char *reverse(char *word)
{
    char *rev = malloc(strlen(word));
    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        rev[strlen(word) - 1 - i] = word[i];
    }
    return rev;
}

void funB(char *word, char *text)
{
    char *atbashWord = getAtbash(word);
    char *reversedWord = reverse(atbashWord);
    char finaltext[TXT];
    memset(finaltext, 0 , strlen(finaltext));
    int pos = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        int posAtbash = 0;
        int posReverse = 0;    
        if (reversedWord[posReverse] != text[i] && atbashWord[posAtbash] != text[i])
        {
            continue;
        }
        if (atbashWord[posAtbash] == text[i])
        {
            posAtbash++;
        }
        if (reversedWord[posReverse] == text[i])
        {
            posReverse++;
        }

        for (int j = i + 1; j < strlen(text); j++)
        {
            if (reversedWord[posReverse] != text[j] && posReverse > posAtbash)
            {
                break;
            }
            else if (atbashWord[posAtbash] != text[j] && posAtbash > posReverse)
            {
                break;
            }
            if (atbashWord[posAtbash] == text[j])
            {
                posAtbash++;
            }
            if (reversedWord[posReverse] == text[j])
            {
                posReverse++;
            }
            if (posAtbash == strlen(word))
            {
                addWord(finaltext, atbashWord, 0, strlen(word) - 1, pos);
                pos += strlen(word) + 1;
                break;
            }
            if (posReverse == strlen(word))
            {
                addWord(finaltext, reversedWord, 0, strlen(word) - 1, pos);
                pos += strlen(word) + 1;
                break;
            }
        }
    }
    finaltext[--pos] = '\0';
    printf("Atbash Sequences: %s\n", finaltext);
    free(atbashWord);
    free(reversedWord);
}