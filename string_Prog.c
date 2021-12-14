#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"
#define TXT 1024
#define WORD 30

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

char getAtbash(char c)
{
    if ('a' <= c && c <= 'z')
        return 'z' - c + 'a';
    else if ('A' <= c && c <= 'Z')
        return 'Z' - c + 'A';
    else
        return 0;
}

int getGematria(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a' + 1;
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 1;
    else
        return 0;
}

void funA(int gematria, char *text)
{
    char finaltext[1024];
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