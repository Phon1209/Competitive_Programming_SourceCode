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
#define MOD 1000000007
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

char m[5][1005];
void _main()
{
    sint(n);
    ll ans=1;
    if(n%2)ans=0;
    for(int i=1;i<=3;i++)
    {
        scanf("%s",m[i]);
    }
    m[3][0]='#';
    m[1][n-1]='#';
    if(m[1][0]=='#')ans=0;
    if(m[3][n-1]=='#')ans=0;
    for(int i=0;i<n;i++)
    {
        if(m[2][i]=='#')ans=0;
    }
    for(int i=1;i<n;i+=2)
    {
        int cnt=2;
        if(m[1][i]=='#' || m[1][i+1]=='#')cnt--;
        if(m[3][i]=='#' || m[3][i+1]=='#')cnt--;
        ans*=cnt;
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    IN("let_it_flow.txt");
    SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
}
/*

*/
