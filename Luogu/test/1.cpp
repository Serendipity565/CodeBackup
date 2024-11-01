#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, w = 0, c, f, d;
    char a = ',';
    scanf("%d", &n);
    m = n;
    while (m > 0)
    {
        m /= 10;
        w++;
    }
    printf("%d", w);
    m = n;
    for (int i = w - 1; i >= 0; i--)
    {
        c = pow(10, i);
        f = m / c;
        m = m % c;
        printf("%d%c", f, a);
    }
    d = pow(10, (n - 1));
    printf("%d", n % d);
    return 0;
}