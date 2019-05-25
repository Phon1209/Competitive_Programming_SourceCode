#include<bits/stdc++.h>
using namespace std;
#define SEND freopen("output.txt","w",stdout)
long long a[505];
long long dp[505][505];
int cnt[505][505];
int _main()
{
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        cnt[i][1]=1;
        dp[i][1]=a[i];
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            for(int k=1;k<=i;k++)
            {
                if(cnt[j][k]!=0)
                {
                    if(dp[j][k]<=a[i]*6)
                    {
                        if(cnt[j][k]+1>cnt[i][k+1] || (dp[i][k+1]<dp[j][k]+a[i]))
                        {
                            cnt[i][k+1]=cnt[j][k]+1;
                            ans=max(ans,cnt[i][k+1]);
                            dp[i][k+1]=dp[j][k]+a[i];
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
    // fflush(stdout);
    return 0;
}
int main()
{
    // SEND;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
        if(i!=t)printf("\n");
    }
}
