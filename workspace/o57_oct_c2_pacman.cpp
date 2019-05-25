#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[1005][1005];
ll dp[1005][1005][5];
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    dp[1][1][1]=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==0)
                {
                    dp[i][j][0]=max(dp[i-1][j][0],max(dp[i-1][j][1],dp[i-1][j][2]));
                    dp[i][j][0]=max(max(dp[i][j][0],dp[i][j-1][0]),max(dp[i][j-1][1],dp[i][j-1][2]));
                    continue;
                }
                dp[i][j][k]=max(dp[i-1][j][k-1],dp[i][j-1][k-1])+a[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<3;i++)
    {
        ans=max(ans,dp[n][m][i]);
    }
    printf("%lld\n",ans);
}
/*

*/
