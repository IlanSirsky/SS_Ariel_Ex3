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

void funA(char *word, char *text)
{
    char finaltext[TXT];
    memset(finaltext, 0 , strlen(finaltext));
    int pos = 0;
    int dest = 0;
    int gematria = sumGem(word);
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


