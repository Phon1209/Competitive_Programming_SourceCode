#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
int main()
{
    sint3(n,k,x);
    int ans=0;
    for(int i=0;i<n-k;i++)
    {
        sint(tmp);
        ans+=tmp;
    }
    ans+=(k*x);
    printf("%d\n",ans);
}
