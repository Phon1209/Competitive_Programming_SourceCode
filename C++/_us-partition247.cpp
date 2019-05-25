#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
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
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int v[20][20];
int dp[20][20];
int cost[20][20];
int s[20];
int main()
{
    sint2(n,k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int1(v[i][j]);
        }
    }
    int ans=inf;
    for(int mask=0;mask<(1<<(n-1));mask++)
    {
        int k1=__builtin_popcount(mask);
        if(k1>k)continue;
        for(int i=0;i<n;i++)
        {
            memset(s,0,sizeof(s));
            for(int i1=i+1;i1<=n;i1++)
            {
                cost[i][i1]=0;
                int s1=0;
                for(int j=0;j<n;j++)
                {
                    s[j]+=v[i1-1][j];
                    s1+=s[j];
                    cost[i][i1]=max(cost[i][i1],s1);
                    if((mask>>j)%2)
                    {
                        s1=0;
                    }
                }
            }
        }
        for(int k2=0;k2<=n;k2++)
        {
            for(int i=0;i<=n;i++){
                dp[k2][i]=inf;
            }
        }
        dp[0][0]=0;
        for(int k2=1;k2<=n && k2<=(k-k1+1);k2++)
        {
            for(int i=0;i<n;i++)
            {
                for(int i1=i+1;i1<=n;i1++)
                {
                    dp[k2][i1]=min(dp[k2][i1],max(dp[k2-1][i],cost[i][i1]));
                }
            }
            ans=min(ans,dp[k2][n]);
        }
    }
    printf("%d\n",ans);
}
/*

*/
