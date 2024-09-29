#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char *lineBuf;
    size_t lineSize;

    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    lineBuf = NULL;
    lineSize = 0;

    while (1)
    {
        if (getline(&lineBuf, &lineSize, fp) < 0)
            break;
        printf("%ld\n", strlen(lineBuf));
        printf("%ld\n", lineSize);
    }

    fclose(fp);

    exit(0);
}
