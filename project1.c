/* 
* Author: Emma Lucas 
* project1.c
* 
* Performs find and replace functionality on a given input file. 
* Every instance of the find text replaced with the replacement text. 
*/ 

#include <stdio.h>

int findStringLength(char str[]);
int findSubstring(char str[], char sub[], int start);
void stringConcat(char str1[], char str2[], int start, int stop);

int main(int argc, char* argv[])
{
    char* oldWord = argv[1];
    char* newWord = argv[2];
    char oldText[1024];
    char newText[1024];

    if (argc != 3)
    {
        printf("Proper command line arguments were not supplied.\n\n");
        return 1;
    }

    while (fgets(oldText, 1024, stdin) != NULL)
    {
        int position = 0;
        int textLength = findStringLength(oldText);
        int oldLength = findStringLength(oldWord);
        int newLength = findStringLength(newWord);
        while (position != textLength)
        {
            int subIndex = findSubstring(oldText, oldWord, position);
            if (subIndex == -1)
            {
                strConcat(newText, oldText, position, textLength);
                position = textLength;
            }
            else
            {
                stringConcat(newText, oldText, position, subIndex);
                stringConcat(newText, newWord, 0, newLength);
                position = subIndex + oldLength;
            }
        }
        printf("%s", newText);
    }
    return 0;
}

/* 
* finds the length of a string 
* 
* str: string
* 
* returns length of the string passed in  
*/ 
int findStringLength(char str[])
{
    int strLength = 0;
    char cur = str[0];
    int index = 0;
    while (cur != '\0')
    {   
        strLength++;
        index++;
        cur = str[index];
    }
    return strLength;
}

/* 
* finds a substring within a string
* 
* str: string
* sub: substring
* start: index to start search for substring in string
* 
* returns index that substring starts, or -1 if not found
*/ 
int findSubstring(char str[], char sub[], int start)
{
    int strLength = findStringLength(str);
    int subLength = findStringLength(sub);
    for (int i = start; i < strLength; i++)
    {
        int count = 0;
        for (int j = i; j < i + subLength; j++)
        {
            if (str[j] == sub[j - i])
            {
                count++;
            }
            if (count == subLength)
            {
                return i;
            }
        }
    }
    return -1;
}

/* 
* concats one string onto another
* 
* str1: first string
* str2: second string
* start: index to start concating str2 to str1
* stop: index to stop concating
*/ 
void stringConcat(char str1[], char str2[], int start, int stop)
{
    int index = findStringLength(str1);
    for (int i = start; i < stop; i++)
    {
        str1[index] = str2[i];
        index++;
    }
    str1[index] = '\0';
}

