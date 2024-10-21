#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
 * -y: year
 * -m:month
 * -d:day
 * -H:hour
 * -M:minute
 * -S:second
 */
#define TIMESTRSIZE 1024
#define FMTSTRSIZE 1024

int main(int argc, char **argv)
{
    FILE *fp = stdout;
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    char fmtstr[FMTSTRSIZE];
    int c;

    fmtstr[0] = '\0';

    stamp = time(NULL);
    tm = localtime(&stamp);

    while (1)
    {
        c = getopt(argc, argv, "-H:MSy:md");
        if (c < 0)
            break;

        switch (c)
        {
            case 1:
                if (fp == stdout)
                {
                    fp = fopen(argv[optind - 1], "w");
                    if (fp == NULL)
                    {
                        perror("fopen()");
                        fp = stdout;
                    }
                }
                break;
            case 'H':
                if (strcmp(optarg, "12") == 0)
                    strncat(fmtstr, "%I(%P) 时", FMTSTRSIZE);
                else if (strcmp(optarg, "24") == 0)
                    strncat(fmtstr, "%H时 ", FMTSTRSIZE);
                else
                    fprintf(stderr, "Invalid argument of -H");
                break;
            case 'M':
                strncat(fmtstr, "%M分", FMTSTRSIZE);
                break;
            case 'S':
                strncat(fmtstr, "%S秒", FMTSTRSIZE);
                break;
            case 'y':
                if (strcmp(optarg, "2") == 0)
                    strncat(fmtstr, "%y年", FMTSTRSIZE);
                else if (strcmp(optarg, "4") == 0)
                    strncat(fmtstr, "%Y年", FMTSTRSIZE);
                else
                    fprintf(stderr, "Invalid argument of -y");
                break;
            case 'm':
                strncat(fmtstr, "%m月", FMTSTRSIZE);
                break;
            case 'd':
                strncat(fmtstr, "%d日", FMTSTRSIZE);
                break;
            default:
                break;
        }
    }
    strncat(fmtstr, "\n", FMTSTRSIZE);
    strftime(timestr, TIMESTRSIZE, fmtstr, tm);
    fputs(timestr, fp);

    if (fp != stdout)
        fclose(fp);
    exit(0);
}
