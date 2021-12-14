#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"
#define TXT 1024
#define WORD 30

int calcGematria(char *word)
{
    int gematria = 0;
    for (size_t i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            gematria += (word[i] - 'A' + 1);
        }
        else if (islower(word[i]))
        {
            gematria += (word[i] - 'a' + 1);
        }
        else
        {
            gematria += 0;
        }
    }
    return gematria;
}

void funA(int gematria, char *txt)
{
    printf("im in funA\n");
    printf("Gematria Sequences: ");
    int gem = 0;
    char temp[gematria];
    int index = 0;
    int remember = 0;
    for (int i = 0; i < TXT; i++)
    {
        if (txt[i] == '~')
        {
            break;
        }
        if (index == 1)
        {
            remember = i;
        }
        if ((!isupper(txt[i]) || !islower(txt[i])) && index != 0)
        {
            temp[index++] = txt[i];
        }
        else if (isupper(txt[i]) || islower(txt[i]))
        {
            temp[index++] = txt[i];
        }
        printf("%s %d\n", temp , i);
        gem = calcGematria(temp);
        if (gem == gematria)
        {
            printf("%s~", temp);
            memset(temp, 0, sizeof(temp));
            i = i - index + 1;
            remember = i;
            gem = 0;
            index = 0;
        }
        else if (gem > gematria)
        {
            gem = 0;
            memset(temp, 0, sizeof(temp));
            index = 0;
            i = remember - 1;
        }
    }
    printf("\n");
}