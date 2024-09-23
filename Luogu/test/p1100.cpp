#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int a;
    scanf("%u",&a);
    unsigned int b=a<<16;
    unsigned int c=a>>16;
    printf("%u",b+c);
    return 0;
}