#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>

// #define INT_MIN INT_MIN
// #define INT_MAX INT_MAX

char *readFull(char *filename)
{
    char *buffer = 0;
    long length;
    FILE *f = fopen(filename, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer)
        {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }

    if (buffer)
    {
        buffer[length] = '\0';
        return buffer;
    }
    return NULL;
}

int countCharInStr(char *str, char ch)
{
    int i;
    for (i = 0; str[i]; str[i] == ch ? i++ : *str++)
        ;
    return i;
}

char **tokenize(char *str, char *delim)
{
    //counting
    int count = 0;
    for (int i = 0; i < strlen(delim); i++)
        count += countCharInStr(str, delim[i]);

    if (count == 0)
        return NULL;

    //initializing 2d array
    char **tokens = (char **)malloc((count + 1) * sizeof(char *));

    //storing tokens size at zero index;
    tokens[0] = (char *)malloc(32 * sizeof(char));
    tokens[0] = itoa(count + 1, tokens[0], 10);

    //using strtok
    int i = 1;
    char *token = strtok(str, delim);
    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }

    return tokens;
}

// int main()
// {
//     char *fdata = readFull("Input_File.txt");
//     printf("%s\n", fdata); // part a

//     char *onlydigits = malloc(strlen(fdata));
//     for (int i = 0, j = 0; i < strlen(fdata); i++)
//         if (fdata[i] <= '9' && fdata[i] >= '0')
//             onlydigits[j++] = fdata[i];

//     printf("%s\n", onlydigits); // part b
//     FILE *foutp = fopen("onlydigits.txt", "w");
//     if (foutp)
//         fprintf(foutp, "%s", onlydigits);
//     fclose(foutp);

//     return 0;
// }

void checkword(char *str, int *num, int *nonaplha, int *vowel)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            *num = INT_MAX;
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i]))
            *nonaplha = INT_MIN;
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            *vowel = INT_MAX;
    }
}

int main()
{
    char buffer[255];
    FILE *finp = fopen("Input_File.txt", "r"); //reading file

    FILE *fpd = fopen("digits.txt", "a");   //first you should delete all text
    FILE *fpn = fopen("nonalpha.txt", "a"); //first you should delete all text
    FILE *fpv = fopen("vowel.txt", "a");    //first you should delete all text

    while (fscanf(finp, "%s", buffer) == 1)
    {
        int num = INT_MIN, nonaplha = INT_MAX, vowel = INT_MIN;
        checkword(buffer, &num, &nonaplha, &vowel);
        if (num == INT_MAX)
        {
            for (int i = 0; i < strlen(buffer); i++)
                if (buffer[i] >= '0' && buffer[i] <= '9')
                    fprintf(fpd, "%c\n", buffer[i]);
        }
        if (nonaplha == INT_MIN)
        {
            fprintf(fpn, "%s\n", buffer);
        }
        if (vowel == INT_MAX)
        {
            fprintf(fpv, "%s\n", strrev(buffer));
        }
    }
}