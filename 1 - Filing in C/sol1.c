#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    char buffer[255];
    FILE *finp = fopen("Input_File.txt", "r"); //reading file

    FILE *fpd = fopen("digits.txt", "a");   //first you should delete all text
    FILE *fpn = fopen("nonalpha.txt", "a"); //first you should delete all text
    FILE *fpv = fopen("vowel.txt", "a");    //first you should delete all text

    while (fscanf(finp, "%s", buffer) == 1) //scanning input file
    {
        int num = INT_MIN, nonaplha = INT_MAX, vowel = INT_MIN;

        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] >= '0' && buffer[i] <= '9')
                num = INT_MAX;
            if ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i]))
                nonaplha = INT_MIN;
            if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u')
                vowel = INT_MAX;
        }

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