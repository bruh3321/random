#include <stdio.h>

int OSdetect()
{
#if __WIN32__
    return 1;
#endif
#if __UNIX__
    return 2;
#endif
#if __LINUX__
    return 3;
#endif
}