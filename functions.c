#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"

#define TXT 1024
#define WORD 30

//A functions

void addWord(char *arr, char *data, int start, int end, int pos)
{
    while (start <= end)
    {
        arr[pos++] = data[start++];
    }
    arr[pos] = '~';
}

int sumGem(char *word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += getGematria(word[i]);
    }
    return sum;
}

int getGematria(char c)
{
    if (islower(c))
    {
        return c - 'a' + 1;
    }
    else if (isupper(c))
    {
        return c - 'A' + 1;
    }
    else
        return 0;
}

void funA(int gematria, char *text)
{
    char finaltext[TXT];
    int pos = 0;
    int dest = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int sum = getGematria(text[i]);
        if (sum == 0)
        {
            continue;
        }
        dest = i;
        for (int j = i + 1; j < strlen(text); j++)
        {
            int value = getGematria(text[j]);
            if (sum + value == gematria && j + 1 == strlen(text))
            {
                if (value != 0)
                {
                    dest = j;
                }
                addWord(finaltext, text, i, dest, pos);
                pos += dest - i + 2;
                break;
            }
            else if (value == 0)
            {
                continue;
            }
            else if (sum == gematria && sum + value > gematria)
            {
                addWord(finaltext, text, i, dest, pos);
                pos += dest - i + 2;
                break;
            }
            else if (sum <= gematria && sum + value <= gematria)
            {
                sum += value;
                dest = j;
            }
            else if (sum <= gematria && sum + value > gematria)
            {
                break;
            }
            else
            {
                break;
            }
        }
    }
    finaltext[--pos] = '\0';
    printf("Gematria Sequences: %s\n", finaltext);
}

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

    int pos = 0;
    int dest = 0;

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
        dest = i;

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
            dest++;
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