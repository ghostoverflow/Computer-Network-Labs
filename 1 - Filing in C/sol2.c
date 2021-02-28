#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

void readFile(char *fname) //a
{
    FILE *fd = fopen(fname, "r");
    if (fd == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char buff[255];
    while (fgets(buff, 255, fd) != NULL)
    {
        printf("%s\n", buff);
    }
    fclose(fd);
}

void getIntegers(char *fname) //b
{
    FILE *inFile = fopen(fname, "r");
    FILE *outFile = fopen("Integers.txt", "w");
    if (inFile == NULL || outFile == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char buff[255];
    bool flag = false;
    while (fgets(buff, 255, inFile) != NULL)
    {
        char intArr[9];
        int i, j;
        for (i = 0, j = 0; i < strlen(buff); ++i)
        {
            if (buff[i] >= '0' && buff[i] <= '9')
            {
                if (!flag)
                {
                    j = 0;
                    flag = true;
                }
                intArr[j++] = buff[i];
            }
            else if (flag)
            {
                flag = false;
                intArr[j] = '\0';
                fputs(intArr, outFile);
                fputc('\n', outFile);
            }
        }
    }
    fclose(inFile);
    fclose(outFile);
}

bool checkWord(char *word)
{
    int size = strlen(word);
    bool flag = true;
    int i;
    for (i = 0; i < size && flag; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z' || word[i] >= 'a' && word[i] <= 'z')
            flag = false;
    }
    return flag;
}

void nonAlpha(char *fname) //c
{
    FILE *inFile = fopen(fname, "r");
    FILE *outFile = fopen("Non Alphabet.txt", "w");
    if (inFile == NULL || outFile == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char buff[255];
    bool flag = false;
    while (fgets(buff, 255, inFile) != NULL)
    {
        char *token = strtok(buff, " ");
        while (token != NULL)
        {
            if (checkWord(token))
            {
                fputs(token, outFile);
                fputc('\n', outFile);
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(inFile);
    fclose(outFile);
}

bool findVowel(char *word)
{
    int size = strlen(word);
    bool flag = false;
    int i;
    for (i = 0; i < size && !flag; i++)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
            flag = true;
    }
    return flag;
}

void invert(char *fname) //d
{
    FILE *inFile = fopen(fname, "r");
    FILE *outFile = fopen("Invert.txt", "w");
    if (inFile == NULL || outFile == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char buff[255];
    bool flag = false;
    while (fgets(buff, 255, inFile) != NULL)
    {
        fputs("Original: ", outFile);
        if (buff[strlen(buff) - 1] == '\n') //Removing newline character from file input
            buff[strlen(buff) - 1] = '\0';
        fputs(buff, outFile);
        fputc('\n', outFile);
        char *token = strtok(buff, " ");
        fputs("Inverted: ", outFile);
        while (token != NULL)
        {
            if (findVowel(token))
            {
                int size = strlen(token);
                int n = size;
                char temp;
                int i;
                for (i = 0; i < size / 2; i++, n--)
                {
                    temp = token[i];
                    token[i] = token[n - 1];
                    token[n - 1] = temp;
                }
            }
            fputs(token, outFile);
            fputc(' ', outFile);
            token = strtok(NULL, " ");
        }
        fputc('\n', outFile);
    }
    fclose(inFile);
    fclose(outFile);
}

int main()
{
    readFile("Input File.txt");
    getIntegers("Input File.txt");
    nonAlpha("Input File.txt");
    invert("Input File.txt");
    return 0;
}
