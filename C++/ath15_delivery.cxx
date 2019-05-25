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
int h[100005];
int no[100005];
hjtng
void _main()
{
    memset(h,0,sizeof(h));
    memset(no,0,sizeof(no));
    sint2(n,k);
    vi v;
    v.pb(0);
    for(int i=1;i<=n;i++)
    {
        sint2(w,c);
        v.pb(w);
        if(h[c])no[i]=h[c];
        h[c]=i;
    }
    int l=1,r=100000000;
    int ans=inf;
    while(l<=r)
    {
        int md=(l+r)/2;
        int box=1;
        int cap=0;
        int since=1;
        for(int i=1;i<=n;i++)
        {
            if(no[i]>=since || cap+v[i]>md)
            {
                box++;
                cap=v[i];
            }
            else cap+=v[i];
        }
        if(box<=k)
        {
            ans=min(md,ans);
            r=md-1;
        }
        else l=md+1;
    }
    printf("%d\n",(ans==inf)? -1:ans);
}
int main()
{
    sint(t);
    while(t--)
    {
        _main();
    }
}
/*

*/
