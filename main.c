#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "frequency.h"

int main(int argc, char* argV[])
{
    //check for valid argV
    if(argc > 2 || (argc == 2 && *argV[1] != 'r'))
    {
        printf("Invalid Arguments");
        return 0;
    }

    node* head = getNewTrieNode();
    int wordSize = 0;
    char* str = (char *)malloc(sizeof(char) * 2);
    char c;
    while(scanf("%c", &c) == 1)
    {
        if(validCharacter(c))
        {
            c = tolower(c);
            str[wordSize++] = c;
            str = (char *)realloc(str, wordSize + 1);
        }
        if(endOfWord(c))
        {
            str[wordSize] = '\0';
            wordSize = 0;
            insert(head,str);
            free(str);
            char* str = (char *)malloc(sizeof(char) * 2);
        }
    }
    if(argc == 2 && *argV[1] == 'r')
    {
        printR(head, str);
    }
    else
    {
        print(head, str);
    }
    free(str);
}
