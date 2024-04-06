#include <stdio.h>

int main()
{
    int s = 10;
    int x;
    while (s) {
        x = getchar();
        putchar(x);
        s = s-1;
    }
    return 0;
}