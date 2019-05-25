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
// 1111-2
// 1111-2
// 1111--
// -----4
// 3333-4
ll a[305][305],qs[305][305];
ll mx[5][305][305],mh[305];
ll dp[305][305][305]; // dp[i][j][k] mean  block 1 in area [1][1] to [i][k] sum block 2 in area [1][n] to [j][k+1]
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int1(a[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mx[1][i][j]=max(qs[i][j],mx[1][i-1][j-1]);
            mx[1][i][j]=max(mx[1][i][j],max(mx[1][i-1][j],mx[1][i][j-1]));
        }
    }
    for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			mx[2][i][j] = max(mx[2][i-1][j+1],max(mx[2][i][j+1],mx[2][i-1][j]));
			mx[2][i][j] = max(mx[2][i][j],qs[i][m]-qs[i][j-1]);
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			mx[3][i][j] = max(mx[3][i+1][j-1],max(mx[3][i][j-1],mx[3][i+1][j]));
			mx[3][i][j] = max(mx[3][i][j],qs[n][j]-qs[i-1][j]);
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			mx[4][i][j] = max(mx[4][i+1][j+1],max(mx[4][i][j+1],mx[4][i+1][j]));
			mx[4][i][j] = max(mx[4][i][j],qs[n][m]-qs[i-1][m]-qs[n][j-1]+qs[i-1][j-1]);
		}
	}
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                dp[i][j][k]=mx[1][i][k]+mx[2][j][k+1];
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans=max(ans,mx[3][][]+mx[4][][]+dp[i-1][][]);
            }
        }
    }
	printf("%lld\n",ans);
}
/*

*/
