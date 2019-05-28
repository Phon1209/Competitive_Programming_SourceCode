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

int dp[105][105][6];
int a[105],n,k;
int find(int l,int r,int ff)
{
    if(l>r)return 0;
    if(l==r)return k-ff-1;
    int &ret=dp[l][r][ff];
    if(ret!=-1)return ret;
    ret=inf;
    if(ff==k-1)ret=find(l+1,r,0);
    if(ff<k-1)ret=find(l,r,ff+1)+1;
    for(int i=l+1;i<=r;i++)
    {
        if(a[l]!=a[i])continue;
        ret=min(ret,find(l+1,i-1,0)+find(i,r,min(k-1,ff+1)));
    }
    // printf("%d %d %d = %d\n",l,r,ff,ret);
    return ret;
}
int main()
{
    int2(n,k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",find(0,n-1,0));
}
/*

*/
