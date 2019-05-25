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
#define MOD 1000000007ll
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
ll ans=1;
int in[105],pre[105];
ll find(int l,int r,int x,int y)
{
    printf("%d %d %d %d\n",l,r,x,y);
    pause;
    if(l>=r)return 1;
    int i;
    for(i=x;i<=y;i++)
    {
        if(in[i]==pre[l])break;
    }
    debug(i);
    ll u=find( l+1 , l+i-x , x , i-1 );
    int j;
    for(j=i+1;j<=y;j++)
    {
        if(in[j]==pre[l+i-x+1])break;
    }
    debug(j);
    ll q=0;
    for(int k=j;k<=y;k++)
    {
        q+=find(l+i-x+1,l+i-x+k,i+1,k)*find(l+i-x+k+1,r,k+1,y);
        ans%=MOD;
    }
    return (u*q)%MOD;
}
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        int1(pre[i]);
    }
    for(int i=0;i<n;i++)
    {
        int1(in[i]);
    }
    //inclusive
    ans=find(0,n-1,0,n-1);
    printf("%lld\n",ans%MOD);
}
/*

*/
