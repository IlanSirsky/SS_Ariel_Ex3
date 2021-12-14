#include "OutFunctions.h"

char getAtbash(char c){
    if('a' <= c && c <= 'z') return 'z'-c+'a';
    else if('A' <= c && c <= 'Z') return 'Z'-c+'A';
    else return 0;
}

int getGematria(char c){
    if('a' <= c && c <= 'z') return c-'a'+1;
    else if('A' <= c && c <= 'Z') return c-'A'+1;
    else return 0;
}