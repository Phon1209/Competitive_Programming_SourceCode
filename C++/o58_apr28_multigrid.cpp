#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : Greedy + DP + Observe
Source : Evaluator
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
ii jump[10][25],jump2[10][25];
map<ii,int> dp[2],ext[2];
tuple<ii,ii,ii,ii> getnear(int x,int y,int i)
{
    ii r[5];
    int p=(1<<i);
    r[1]=mkp(x/p,y/p);
    r[2]=mkp(x/p,ceil((double)y/p));
    r[3]=mkp(ceil((double)x/p),y/p);
    r[4]=mkp(ceil((double)x/p),ceil((double)y/p));
    for(int i=1;i<=4;i++)r[i].F*=p,r[i].S*=p;
    return make_tuple(r[1],r[2],r[3],r[4]);
}
int cost(ii a,ii b,int skip)
{
    return (abs(a.F-b.F)+abs(a.S-b.S))/(1<<skip);
}
int main()
{
    sint2(n,m);
    while(m--)
    {
        for(int i=0;i<2;i++)
        {
            ext[i].clear();
            dp[i].clear();
        }
        sint2(x1,y1);
        sint2(x2,y2);
        for(int i=0;i<=n;i++)
            tie(jump[1][i],jump[2][i],jump[3][i],jump[4][i])=getnear(x1,y1,i);
        ext[0][mkp(x1,y1)]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(!ext[0][jump[j][i]])
                {
                    ext[0][jump[j][i]]=1;
                    dp[0][jump[j][i]]=1e9;
                }
                for(int k=1;k<=4;k++)
                {
                    // printf("%d %d\n",jump[j][i].F,jump[j][i].S);
                    dp[0][jump[j][i]]=min(dp[0][jump[j][i]],dp[0][jump[k][i-1]]+cost(jump[k][i-1],jump[j][i],i-1));
                }
            }
        }

        for(int i=0;i<=n;i++)
            tie(jump2[1][i],jump2[2][i],jump2[3][i],jump2[4][i])=getnear(x2,y2,i);
        ext[1][mkp(x2,y2)]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(!ext[1][jump2[j][i]])
                {
                    ext[1][jump2[j][i]]=1;
                    dp[1][jump2[j][i]]=1e9;
                }
                for(int k=1;k<=4;k++)
                {
                    // printf(">%d %d\n",jump2[j][i].F,jump2[j][i].S);
                    dp[1][jump2[j][i]]=min(dp[1][jump2[j][i]],dp[1][jump2[k][i-1]]+cost(jump2[k][i-1],jump2[j][i],i-1));
                }
            }
        }
        int ans=inf;
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=4;j++)
            {
                for(int k=1;k<=4;k++)
                {
                    // printf(">>%d %d %d \n",i,j,k);
                    // printf("%d %d %d\n",dp[0][jump[j][i]],cost(jump[j][i],jump2[k][i],i),dp[1][jump2[k][i]]);
                    ans=min(ans,dp[0][jump[j][i]]+cost(jump[j][i],jump2[k][i],i)+dp[1][jump2[k][i]]);
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*

*/
