#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        int n;int temp;
        scanf("%d", &n);
        vector<int> m[n+1];
        int cnt=n;  //cnt表示还剩几个宝石
        for (int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            m[temp].push_back(i);
        }
        int sum = 0;
        while (cnt) {
            int mymin =n+1;
            for (int i=1;i<=n;i++) {
                if (!m[i].empty()) {
                    mymin = min(mymin,m[i].back());
                }
            }
            sum++;
            for (int i=1;i<=n;i++) {
                while (!m[i].empty() && m[i].back() >= mymin) {
                    m[i].pop_back();
                    cnt--;
                }
            }
        }
        printf("%d\n", sum);
        t--;
    }
    return 0;
}