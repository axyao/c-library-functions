#include <stdio.h>
#include <string.h>
#include <ctype.h>

// My version of C strstr() library function 
// Includes an option to turn on/off case sensitivity when searching for substring

char *strstrcs(char *str1, char *str2, int caseInsensitive);

int main(int argc, char *argv[])
{
    char line[256] = "In ac velit vitae turpis posuere rutrum nec quis est.";
    char keyword[256] = "viTae";

    char *result = strstrcs(line, keyword, 1);

    if (result != NULL)
    {
        printf("result is: %s\n", result);
    }
    else
    {
        printf("result is NULL\n", result);
    }

    return 0;
}

char *strstrcs(char *line, char *keyword, int caseInsensitive)
{
    int llen = strlen(line);
    int klen = strlen(keyword);

    if (klen == 0)
    {
        return line;
    }

    if (llen < klen)
    {
        return NULL;
    }

    int i = 0;
    int j = 0;

    while (i < llen)
    {
        char charLine = line[i];
        char charKeyword = keyword[j];

        if (caseInsensitive)
        {
            charLine = tolower(charLine);
            charKeyword = tolower(charKeyword);
        }

        if (charLine == charKeyword)
        {
            while (j < klen)
            {
                char charLine = line[i + j];
                charKeyword = keyword[j];

                if (caseInsensitive)
                {
                    charLine = tolower(charLine);
                    charKeyword = tolower(charKeyword);
                }

                if (charKeyword == '\0' && j == klen - 1)
                {
                    return &line[i];
                }

                if (charLine != charKeyword)
                {
                    j = 0;
                    break;
                }

                if (j == klen - 1)
                {
                    return &line[i];
                }

                j++;
            }
        }

        i++;
    }

    return NULL;
}
