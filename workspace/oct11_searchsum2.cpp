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
int a[1005];
int dp[1005][1005];
int ans[1005];
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        dp[i][i]=a[i];
        ans[1]=min(ans[1],a[i]);
    }
    vi v;
    for(int i=1;i<=n;i++)
    {
        ans[i]=inf;
        for(int j=1;j<=n-i+1;j++)
        {
            // printf("%d %d %d\n",dp[j][])
            dp[j][j+i-1]=dp[j][j]+dp[j+1][j+i-1];
            ans[i]=min(dp[j][j+i-1],ans[i]);
        }
//        printf(">%d\n",ans[i]);
        v.pb(ans[i]);
    }
    vi::iterator it;
    /*
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
    */
    while(m--)
    {
        sint(tmp);
        it=upper_bound(all(v),tmp);
        printf("%d\n",it-v.begin());
    }
}
/*

*/
