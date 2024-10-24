#include <shadow.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *input_pass, *crypted_pass;
    struct spwd *shdowline;

    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    input_pass = getpass("PassWord:");

    shdowline = getspnam(argv[1]);

    crypted_pass = crypt(input_pass, shdowline->sp_pwdp);

    if (strcmp(shdowline->sp_pwdp, crypted_pass) == 0)
        puts("ok!");
    else
        puts("faile!");

    exit(0);
}
