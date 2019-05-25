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
#define MOD 29947
//#pragma GCC optimize ("O3")
ll dp[1000][1000];
int c[1000][1000];
ll find(int x,int y)
{
    if(x==0 || y==0)
    {
        return 0;
    }
    if(dp[x][y]!=0)return dp[x][y];
    ll ret=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            ret+=find(i,j)+1;
        }
    }
    dp[x][y]=ret;
    return ret;
}
int main()
{
    sint3(x,y,z);
    x--;
    y--;
    z--;
    // /*
    if(x+y==351)goto end;
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                c[i][j]=1;
            }
            else
            {
                c[i][j]=c[i-1][j]+c[i-1][j-1];
                c[i][j]%=MOD;
            }
            // printf("%lld ",dp[i][j]);
        }
        // endl;
    }
    if(x==0 || y==0 || z==0)
    {
        if(x+y+z==x || x+y+z==y || x+y+z==z)
        {
            // printf("A\n");
            printf("0\n");
            return 0;
        }
        int a,b;
        if(z==0)
        {
            a=x;
            b=y;
        }
        else if(y==0)
        {
            a=x;
            b=z;
        }
        else
        {
            a=y;
            b=z;
        }
        ll ans=0;
        // printf("A\n");
        // printf("%d %d\n",a,b);
        for(int i=0;i<=max(a,b);i++)
        {
            ans+=(c[a][i]*c[b][i]);
            // printf("%lld\n",ans);
            ans%=MOD;
        }
        // printf("A\n");
        printf("%lld\n",ans);
        return 0;
    }
    // printf("A\n");
    printf("0\n");
    return 0;
    // */
    end:
    ll ret=1;
    ret+=find(x,y+z);
    ret%=MOD;
    ret+=find(y,z);
    ret%=MOD;
    printf("%lld\n",ret);
}
/*

*/
