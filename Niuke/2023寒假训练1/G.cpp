#include <bits/stdc++.h>
using namespace std;
int a[1005] = {0};
int main()
{
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        next_permutation(a + 1, a + n + 1);
    }
    
    return 0;
}