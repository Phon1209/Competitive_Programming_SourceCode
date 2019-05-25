#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
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
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}

int dp[10][30][30][30][30];
void print(int p,int i,int j,int k,int l)
{
    int tmp=dp[p][i][j][k][l];
    if(tmp==-1)return;
    if(p==1)printf("0"),i--;
    if(p==2)printf("1"),j--;
    if(p==3)printf("0"),k--;
    if(p==4)printf("1"),l--;
    print(tmp,i,j,k,l);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    dp[1][1][0][0][0]=0;
    dp[2][0][1][0][0]=0;
    dp[3][0][0][1][0]=0;
    dp[4][0][0][0][1]=0;
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            for(int k=0;k<=20;k++)
            {
                for(int l=0;l<=20;l++)
                {
                    for(int p=1;p<=4;p++)
                    {
                        if(p==1)
                        {
                            if(i!=0)
                            {
                                if(dp[1][i-1][j][k][l]!=-1)dp[p][i][j][k][l]=1;
                                if(dp[2][i-1][j][k][l]!=-1)dp[p][i][j][k][l]=2;
                            }
                        }
                        if(p==2)
                        {
                            if(j!=0)
                            {
                                if(dp[3][i][j-1][k][l]!=-1)dp[p][i][j][k][l]=3;
                                if(dp[4][i][j-1][k][l]!=-1)dp[p][i][j][k][l]=4;
                            }
                        }
                        if(p==3)
                        {
                            if(k!=0)
                            {
                                if(dp[1][i][j][k-1][l]!=-1)dp[p][i][j][k][l]=1;
                                if(dp[2][i][j][k-1][l]!=-1)dp[p][i][j][k][l]=2;
                            }
                        }
                        if(p==4)
                        {
                            if(l!=0)
                            {
                                if(dp[3][i][j][k][l-1]!=-1)dp[p][i][j][k][l]=3;
                                if(dp[4][i][j][k][l-1]!=-1)dp[p][i][j][k][l]=4;
                            }
                        }
                    }
                }
            }
        }
    }
    sint(t);
    // 1-> 1 2  - 00
    // 2-> 3 4  - 01
    // 3-> 1 2  - 10
    // 4-> 3 4  - 11
    while(t--)
    {
        sint2(x,y);
        sint2(a,b);
        // debug(dp[1][x][y][a][b]);
        // debug(dp[2][x][y][a][b]);
        // debug(dp[3][x][y][a][b]);
        // debug(dp[4][x][y][a][b]);
        bool ok=0;
        for(int i=1;i<=4;i++)
        {
            if(dp[i][x][y][a][b]!=-1)
            {
                if(i==1 || i==2)printf("0");
                else printf("1");
                print(i,x,y,a,b);
                ok=1;
                break;
            }
        }
        if(!ok)printf("impossible");
        endl;
        debug(1);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
