#include <stdio.h>

ssize_t getlineCpy(char **lineptr, size_t *n, FILE *fp);



ssize_t getlineCpy(char **lineptr, size_t *n, FILE *fp)
{
    if (feof(fp))
    {
        return -1;
    }

    char *tmpptr;

    if (*lineptr == NULL)
    {
        tmpptr = (char *)malloc(32 * sizeof(char)); // size_t type conversion

        if (tmpptr)
        {
            *lineptr = tmpptr;
            *n = (size_t)32;
        }
        else
        {
            printf("Error getline: Memory not allocated.\n");
            return -1;
        }
    }
    else
    {
        tmpptr = *lineptr;
    }

    ssize_t i = 0;
    char c = '0';

    while ((c = fgetc(fp)) != EOF)
    {
        tmpptr[i] = c;
        i++;

        if (c == '\n')
        {
            break;
        }

        if (i == (*n) - 1)
        {
            tmpptr = realloc(tmpptr, (*n) * 2 * sizeof(char));
            if (tmpptr)
            {
                *lineptr = tmpptr;
                (*n) *= 2;
            }
            else
            {
                printf("Error getline: unsuccessful memory reallocation.\n");
                return -1;
            }
        }
    }

    tmpptr[i] = '\0';

    return i;
}