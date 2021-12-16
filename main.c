#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"

#define TXT 1024
#define WORD 30

int main()
{
    char word[WORD] = {0};
    char txt[TXT] = {0};
    for (size_t i = 0; i < WORD - 1; i++)
    {
        char c;
        scanf("%c", &c);
        if (isspace(c))
        {
            break;
        }
        else
        {
            word[i] = c;
        }
    }

    for (size_t i = 0; i < TXT - 1; i++)
    {
        char c;
        scanf("%c", &c);
        txt[i] = c;
        if (c == '~')
        {
            break;
        }
    }
    funA(word, txt);
    funB(word, txt);
    funC(word, txt);
    return 0;
}