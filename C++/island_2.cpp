#include<bits/stdc++.h>
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
int cnt[200005];
int main()
{
    sint2(n,m);
    for(int i=1;i<n+m;i++)
    {
        sint2(x,y);
        if(x>n)cnt[x-n]++;
        if(y>n)cnt[y-n]++;
    }
    for(int i=1;i<=200000;i++)
    {
        cnt[i]--;
        while(cnt[i]>1)
            printf("%d 1\n",cnt[i]--);
    }
}
/*

*/
