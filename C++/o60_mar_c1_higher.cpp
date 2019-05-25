#include<bits/stdc++.h>
using namespace std;
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
int n,m;
int sg[2000005];
void build()
{
    for(int i=n-1;i>=1;i--){
        sg[i]=max(sg[i<<1],sg[i<<1|1]);}
}
void upt(int pos,int val)
{
    for(sg[pos+=n]=val;pos>1;pos>>=1)sg[pos>>1]=max(sg[pos],sg[pos^1]);
}
int query(int l,int r)
{
    int mx=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1)mx=max(mx,sg[l++]);
        if(r&1)mx=max(mx,sg[--r]);
    }
    return mx;
}
int f(int i)
{
    if(i<0)return 0;
    if(i>=n)return n-1;
    return i;
}
int main()
{
    int2(n,m);
    while(m--)
    {
        sint2(pos,h);
        upt(pos,h);
        int l=0,r=n;
        while(l<r)
        {
            int md=(l+r+1)>>1;
            if(query(f(pos-md),f(pos+md))==h)l=md;
            else r=md-1;
        }
        printf("%d\n",l);
    }
}
/*

*/
