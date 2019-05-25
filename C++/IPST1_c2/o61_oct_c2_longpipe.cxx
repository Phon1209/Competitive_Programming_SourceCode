#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define eb emplace_back
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
#define MOD 1000000007
ll dp[60005][5][5];
void find(int n)
{

}
int main()
{
    sint(n);
    dp[1][1][1]=1;
    dp[1][1][2]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][2][3]=1;
    dp[1][3][2]=1;
    dp[1][3][3]=1;
    dp[2][1][3]=1;
    dp[2][3][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int l=1;l<=3;l++)
                {
                    printf("%d\n",i);
                    printf("%d %d %d  %lld %lld\n",j,k,l,dp[i-1][j][l],dp[i-1][l][k]);
                    dp[i][j][k]+=(dp[i-1][j][l]*dp[1][l][k]);
                    dp[i][j][k]%=MOD;
                }
                printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);
            }
        }
    }
    ll sum=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            sum+=dp[n][i][j];
            sum%=MOD;
        }
    }
    printf("%lld\n",sum);
}
/*

*/
