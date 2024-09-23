#include<bits/stdc++.h>
using namespace std; 
long long a[100005], b[100005];
long long n, TT;
long long ans = 1e15;

long long find (long long x) {
    if (x > b[n]) return -1;
    return *lower_bound (b + 1, b + n + 1, x);
}

int main() {
    cin >> n >> TT;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= TT;
    for (int i = 1; i <= n; i++) cin >> b[i], b[i] %= TT;
    sort (a + 1, a + n + 1); sort (b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        ans = min (ans , (a[i] + b[1]) % TT);
        long long x = find (TT - a[i]);
        if (x != -1)
            ans = min (ans, (a[i] + x) % TT);
    }
    cout << ans << endl;
    return 0;
}

