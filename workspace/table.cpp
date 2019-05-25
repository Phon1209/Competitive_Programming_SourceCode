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
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int sg[305][20005];
int lz[305][20005];
void lzup(int idx,int l,int r,int rw,int val)
{
    lz[rw][idx]=val;
    sg[rw][idx]=val;
}
void shift(int idx,int l,int r,int rw)
{
    if(lz[rw][idx]!=0)
    {
        int md=(l+r)/2;
        lzup(idx*2,l,md,rw,lz[rw][idx]);
        lzup(idx*2+1,md+1,r,rw,lz[rw][idx]);
        lz[rw][idx]=0;
    }
}
void up(int idx,int l,int r,int val,int rw,int pos)
{
    if(l==r)
    {
        sg[rw][idx]=val;
        return;
    }
    int md=(l+r)/2;
    shift(idx,l,r,rw);
    if(pos<=md)
    {
        up(idx*2,l,md,val,rw,pos);
    }
    else up(idx*2+1,md+1,r,val,rw,pos);
    sg[rw][idx]=min(sg[rw][idx*2],sg[rw][idx*2+1]);
}
int query(int idx,int rw,int l,int r,int x)
{
    int md=(l+r)/2;
    if(l==r)
    {
        return sg[rw][idx];
    }
    shift(idx,l,r,rw);
    if(x<=md)
    {
        return query(idx*2,rw,l,md,x);
    }
    return query(idx*2+1,rw,md+1,r,x);
}
int main()
{
    sint3(r,c,m);
    while(m--)
    {
        sint(cm);
        if(cm==1)
        {
            sint3(x,y,val);
            up(1,1,c,val,x,y);
        }
        if(cm==2)
        {
            sint2(rw,val);
            sg[rw][1]=val;
            lz[rw][1]=val;
        }
        if(cm==3)
        {
            sint2(x,y);
            printf("%d\n",query(1,x,1,c,y));
        }
        if(cm==4)
        {
            int ans=inf;
            for(int i=1;i<=r;i++)
            {
                ans=min(ans,sg[i][1]);
            }
            printf("%d\n",ans);
        }

    }
}
/*

*/
