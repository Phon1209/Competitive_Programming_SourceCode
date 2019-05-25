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
int sgmn[400005];
int sgmx[400005];
int qmx(int idx,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return sgmx[idx];
    int md=(l+r)/2;
    return max(qmx(idx*2,l,md,x,y),qmx(idx*2+1,md+1,r,x,y));
}
int qmn(int idx,int l,int r,int x,int y)
{
    if(y<l || x>r)return inf;
    if(x<=l && r<=y)return sgmn[idx];
    int md=(l+r)/2;
    return min(qmn(idx*2,l,md,x,y),qmn(idx*2+1,md+1,r,x,y));
}
void sgup(int idx,int l,int r,int pos,int val)
{
    if(l==r)
    {
        sgmn[idx]=sgmx[idx]=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md) sgup(idx*2,l,md,pos,val);
    else sgup(idx*2+1,md+1,r,pos,val);
    sgmn[idx]=min(sgmn[idx*2],sgmn[idx*2+1]);
    sgmx[idx]=max(sgmx[idx*2],sgmx[idx*2+1]);
}
int search(int idx,int l,int r,int pos)
{
    if(l==r && pos==l)
    {
        return sgmn[idx];
    }
    int md=(l+r)/2;
    if(pos<=md) return search(idx*2,l,md,pos);
    else return search(idx*2+1,md+1,r,pos);
}
void update(int pos,int pos2,int n)
{
    int v=search(1,1,n,pos);
    int v2=search(1,1,n,pos2);
    sgup(1,1,n,pos,v2);
    sgup(1,1,n,pos2,v);
}
void build(int idx,int l,int r)
{
    if(l==r)
    {
        sgmn[idx]=sgmx[idx]=l;
        return;
    }
    int md=(l+r)/2;
    build(idx*2,l,md);
    build(idx*2+1,md+1,r);
    sgmn[idx]=min(sgmn[idx*2],sgmn[idx*2+1]);
    sgmx[idx]=max(sgmx[idx*2],sgmx[idx*2+1]);
}
int main()
{
    sint2(n,m);
    build(1,1,n);
    while(m--)
    {
        sint(cm);
        if(cm==0)
        {
            sint2(x,y);
            update(x+1,y+1,n);
        }
        if(cm==1)
        {
            sint2(x,y);
            x++;
            y++;
            int d,r;
            d=qmx(1,1,n,x,y);
            r=qmn(1,1,n,x,y);
//            printf(">%d %d\n",d,r);
            bool ok=false;
            if(d==max(x,y) && r==min(x,y)) ok=true;
            printf("%s\n",ok? "YES":"NO");
        }
    }
}
