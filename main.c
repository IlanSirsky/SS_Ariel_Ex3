#include <stdio.h>
#include "OutFunctions.h"

typedef enum { false, true } bool;

int sumGio(char word[], int size){
    int sum = 0;

    for(int i = 0; i<size; i++){
        sum += getGematria(word[i]);
    }

    return sum;
}

void addWord(char arr[], char data[] ,int start, int end ,int pos){

    while(start <= end){
        arr[pos++] = data[start++];
    }

    arr[pos] = '~';
}

void reverseAshar(char arr[],char arr2[], int size){
    for(int i = size-1; i>=0; i--){
        arr2[size-1-i] = arr[i];  
    }
}

void gioSearch(char text[], char word[], int counterWord, int counterText){
    int gioWord = sumGio(word, counterWord);

    char finaltext[1024];
    int pos = 0;
    int dest = 0;

    for(int i = 0; i<counterText; i++){
        int sum = getGematria(text[i]);
        if (sum == 0){
            continue;
        }
        dest = i;
        for(int j = i+1; j<counterText; j++){
            int value = getGematria(text[j]);
            if(sum + value == gioWord && j+1 == counterText){
                if(value != 0){
                    dest = j;
                }
                addWord(finaltext, text, i, dest, pos);
                pos += dest-i + 2;
                break;
            }
            else if(value == 0){
                continue;
            }
            else if(sum == gioWord && sum + value > gioWord){
                addWord(finaltext, text, i, dest, pos);
                pos += dest-i + 2;
                break;
            }
            else if(sum <= gioWord && sum + value <= gioWord){
                sum += value;
                dest = j;
            }
            else if(sum <= gioWord && sum + value > gioWord){
                break;
            }
            else{
                break;
            }
        }  
    }

    finaltext[--pos] = '\0';

    printf("Gematria Sequences: %s", finaltext);
}

void atbashSearch(char text[], char word[], int counterWord, int counterText){
    char atbashWord[counterWord];
    char reversedWord[counterWord];
   
    char finaltext[1024];
    int pos = 0;
    int dest = 0;

    for(int i = 0; i<counterWord; i++){
        atbashWord[i] = getAtbash(word[i]);
    }
    reverseAshar(atbashWord,reversedWord, counterWord);
    for(int i = 0; i<counterText; i++){
        int posAtbash = 0;
        int posReverse = 0;

        if (reversedWord[posReverse] != text[i] && atbashWord[posAtbash] != text[i]){
            continue;
        }
        if(atbashWord[posAtbash] == text[i]){
            posAtbash++;
        }
        if(reversedWord[posReverse] == text[i]){
            posReverse++;
        }
        
        dest = i;

        for(int j = i+1; j<counterText; j++){
            if (reversedWord[posReverse] != text[j] && posReverse > posAtbash){
                break;
            }
            else if(atbashWord[posAtbash] != text[j] && posAtbash > posReverse){
                break;
            }

            if(atbashWord[posAtbash] == text[j]){
                posAtbash++;
            }
            if(reversedWord[posReverse] == text[j]){
                posReverse++;
            }
            dest++;
            if(posAtbash == counterWord) {
                addWord(finaltext, atbashWord, 0, counterWord-1, pos);
                pos += counterWord + 1;
                break;
            }
            if(posReverse == counterWord) {
                addWord(finaltext, reversedWord, 0, counterWord-1, pos);
                pos += counterWord + 1;
                break;
            }
        }
    }

    finaltext[--pos] = '\0';

    printf("\nAtbash: %s", finaltext);

}


int main(){
    char word[30];
    char text[1024];

    char save = 0;

    int counterWord = 0;
    int counterText = 0;
    bool textMode = false;

    while(scanf("%c", &save)!=EOF){
        if(!textMode){
            if(save == '\n' || save == ' ' || save == '\t') {
                word[counterWord] = '\0';
                textMode = true;
                continue;
            }
            word[counterWord++] = save;
        }
        else{
            if(save == '~'){
                break;
            }
            text[counterText++] = save;
        }
    }

    gioSearch(text, word, counterWord, counterText);
    atbashSearch(text, word, counterWord, counterText);

    return 0;
}