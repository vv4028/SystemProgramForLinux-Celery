#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIMESTRSIZE 1024

int main(int argc, char **argv)
{
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];

    stamp = time(NULL);
    tm = localtime(&stamp);
    strftime(timestr, TIMESTRSIZE, "Now:%Y-%m-%d", tm);

    tm->tm_mday += 100;
    (void)mktime(tm);
    strftime(timestr, TIMESTRSIZE, "100 days later:%Y-%m-%d", tm);
    puts(timestr);

    exit(0);
}
