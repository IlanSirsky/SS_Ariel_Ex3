#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_Prog.h"

#define TXT 1024
#define WORD 30

//C functions
char *sortString(char *word)
{
    char *sorted = malloc(strlen(word));
    if (sorted == NULL){
        return NULL;
    }
    strcpy(sorted, word);
    for (size_t i = 0; i < strlen(word) - 1; i++)
    {
        for (size_t j = i + 1; j < strlen(word); j++)
        {
            if (sorted[i] > sorted[j])
            {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

int stringCompare(char *word, char *temp){
    int j = 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if(temp[i] == ' '){
            continue;
        }
        if (word[j++] != temp[i])
        {
            return 0;
        }
    }
    return 1;
}

void funC(char *word, char *text)
{
    char finaltext[TXT];
    memset(finaltext, 0 , strlen(finaltext));
    char *sortedWord = sortString(word);
    int pos = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char temp[WORD];
        int charCount = 0;
        int index = 0;
        for (int j = i; j < strlen(text); j++)
        {
            if (text[j] == '~')
            {
                memset(temp, 0, strlen(temp));
                break;
            }
            if ((!(isupper(text[j])) && !islower(text[j])) && index == 0)
            {
                memset(temp, 0, WORD);
                break;
            }
            if ((isupper(text[j])) || islower(text[j]))
            {
                temp[index++] = text[j];
                charCount++;
            }
            else if ((!isupper(text[j])) && !islower(text[j]))
            {
                temp[index++] = text[j];
            }
            if (charCount == strlen(word))
            {
                break;
            }
        }
        if (temp[0] != '\0')
        {
            char *sortedTemp = sortString(temp);
            if (stringCompare(sortedWord, sortedTemp))
            {           
                addWord(finaltext, temp, 0, strlen(temp) - 1, pos);
                pos += strlen(temp) + 1;
            }
            free(sortedTemp);
        }
    }
    free(sortedWord);
    finaltext[--pos] = '\0';
    printf("Anagram Sequences: %s\n", finaltext);
}