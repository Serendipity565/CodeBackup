#include <stdio.h>

unsigned int change(unsigned int x, int p, int n)
{
    unsigned int k;

    if (n >= p + 1)
    {
        k = (1U << (p + 1)) - 1;
        return x ^ k;
    }
    else
    {
        k = (1U << (p + 1)) - 1;
        int m = (1U << (p - n + 1)) - 1;
        return x ^ k ^ m;
    }
}

int main()
{
    unsigned int x;
    int p, n;

    scanf("%u %d %d", &x, &p, &n);

    unsigned int result = change(x, p, n);
    printf("%u\n", result);
    return 0;
}
