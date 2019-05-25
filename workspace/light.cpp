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
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int sg[400005];
int lz[400005];
void lzup(int idx,int l,int r)
{
    sg[idx]=(r-l+1)-sg[idx];
    lz[idx]^=(0^1);
}
void shift(int idx,int l,int r)
{
    if(lz[idx]==0)return;
    int md=(l+r)/2;
    lzup(idx*2,l,md);
    lzup(idx*2+1,md+1,r);
    lz[idx]=0;
}
int query(int idx,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)
    {
        return sg[idx];
    }
    shift(idx,l,r);
    int md=(l+r)/2;
    return query(idx*2,l,md,x,y)+query(idx*2+1,md+1,r,x,y);
}
void sgup(int idx,int l,int r,int x,int y)
{
    if(y<l || x>r)return;
    if(x<=l && r<=y)
    {
        lzup(idx,l,r);
        return;
    }
    int md=(l+r)/2;
    shift(idx,l,r);
    sgup(idx*2,l,md,x,y);
    sgup(idx*2+1,md+1,r,x,y);
    sg[idx]=sg[idx*2]+sg[idx*2+1];
}
int main()
{
    sint2(n,m);
    for(int i=0;i<m;i++)
    {
        sint(cm)
        if(cm==0)
        {
            sint2(x,y);
            sgup(1,1,n,x,y);
        }
        if(cm==1)
        {
            sint2(x,y);
            printf("%d\n",query(1,1,n,x,y));
        }
    }
}
