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
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[405][405];
int dp[405][405];
int dp2[405][405];
int main()
{
    sint(n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int1(a[i][j]);
        }
    }

//    endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j-1]+a[i][j];
            // printf("%d ",dp[i][j]);
        }
        // endl;
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            dp2[i][j]=dp2[i+1][j-1]+a[i][j];
        }
    }

    /* endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",dp2[i][j]);
        }
        endl;
    }
    endl;
*/
    int mx=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            for(int k=1;k<=n-i+1;k++)
            {
//                printf("%d %d %d\n",i,j,k);
                int down=dp[j+i-1][k+i-1]-dp[j-1][k-1];
                int up=dp2[j][k+i-1]-dp2[j+i][k-1];
//                printf("%d %d\n",dp2[j][k+i-1],dp2[j+i][k-1]);
//                printf("%d %d\n",down,up);
                mx=max(mx,down-up);
            }
        }
    }
    printf("%d\n",mx);
    while(1)pause;
}
/*

*/
