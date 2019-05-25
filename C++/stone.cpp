#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("O3")
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
int a[1005];
ii dp[1005][1005];
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
        dp[i][i]={a[i],0};
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            //look for range j to j+i
            if(a[j]+dp[j+1][j+i].S<a[j+i]+dp[j][j+i-1].S)
            {
                dp[j][j+i].F=a[j+i]+dp[j][j+i-1].S;
                dp[j][j+i].S=dp[j][j+i-1].F;
            }
            else
            {
                dp[j][j+i].F=a[j]+dp[j+1][j+i].S;
                dp[j][j+i].S=dp[j+1][j+i].F;
            }// 6 1 2 102 103 3 101
        }
    }
    printf("%d\n",dp[0][n-1].F);
}
/*

*/
