#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],b[100010],cnt;
inline ll read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
void hebin(int l,int mid,int r){
    int p=l,q=mid+1;
    for(int i=l;i<=r;i++){
        if((q>r)||(p<=mid&&a[p]<=a[q])){
            b[i]=a[p];
            p++;
        }
        else{
            b[i]=a[q];
            q++;
            cnt+=mid-p+1;
        }
    }
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
}
void merge_sort(int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    hebin(l,mid,r);
    return;
}
signed main(){
    int n;
    scanf(" %d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %lld",&a[i]);
    }
    cnt=0;
    merge_sort(1,n);
    int m;
    scanf(" %d",&m);
    for(int i=1;i<=m;i++){
        int sta,en;
        scanf(" %d %d",&sta,&en);
        cnt=cnt+(en-sta+1)/2;
        if(cnt%2!=0) printf("dislike\n");
        else printf("like\n");
    }
    return 0;
    
}

