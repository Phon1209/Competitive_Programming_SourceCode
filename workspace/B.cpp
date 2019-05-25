#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
int a[100005];
map<int,int> mp;
int main()
{
    sint(n);
    sstring(g,n+5);
    for(int i=1;i<=n;i++)
    {
        int tmp=g[i-1]-'0';
        if(tmp)
            a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
 //       printf("%d %d\n",i,a[i]);
        if(mp.find(a[i])!=mp.end())
        {
            ans=max(ans,i-mp[a[i]]);
        }
        else mp[a[i]]=i;
    }
    if(a[n]==0) ans=max(ans,n);
    printf("%d\n",ans);
}
