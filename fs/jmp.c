#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf save;

static void d(void)
{
    printf("%s():Begin.\n", __FUNCTION__);
    printf("%s*()Jump now\n", __FUNCTION__);
    longjmp(save, 6);

    printf("%s():End.\n", __FUNCTION__);
}

static void c(void)
{
    printf("%s():Begin.\n", __FUNCTION__);
    printf("%s():Call d().\n", __FUNCTION__);

    d();
    printf("%s():d() return.\n", __FUNCTION__);
    printf("%s():End.\n", __FUNCTION__);
}

static void b(void)
{
    printf("%s():Begin.\n", __FUNCTION__);
    printf("%s():Call c().\n", __FUNCTION__);

    c();
    printf("%s():c() return.\n", __FUNCTION__);
    printf("%s():End.\n", __FUNCTION__);
}

static void a(void)
{
    int ret;

    printf("%s():Begin.\n", __FUNCTION__);
    ret = setjmp(save);
    if (ret == 0)
    {
        printf("%s():Call b().\n", __FUNCTION__);
        b();
        printf("%s():b() return.\n", __FUNCTION__);
    }
    else
    {
        printf("%s():Jumped back here with code %d\n", __FUNCTION__, ret);
    }
    printf("%s():End.\n", __FUNCTION__);
}

int main()
{
    printf("%s():Begin.\n", __FUNCTION__);
    printf("%s():Call a().\n", __FUNCTION__);

    a();
    printf("%s():a() return.\n", __FUNCTION__);
    printf("%s():End.\n", __FUNCTION__);

    exit(0);
}
