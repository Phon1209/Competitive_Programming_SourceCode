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
int a[505][505];
int segmn[2005][2005];
int segmx[2005][2005];
int build(int idxx,int idxy,int xl,int xr,int yl,int yr)
{
    if(xl>xr)return 0;
    if(yl>yr)return 0;
 //   pause;
  //  printf("%d %d %d %d %d %d\n",idxx,idxy,xl,xr,yl,yr);
    if(xl==xr && yl==yr)
    {
        segmn[idxx][idxy]=segmx[idxx][idxy]=a[xl][yl];
//        printf(">%d %d %d %d %d %d -> %d %d\n",idxx,idxy,xl,xr,yl,yr,segmn[idxx][idxy],segmx[idxx][idxy]);
        return 1;
    }
//    if(xl==xr)return;
//    if(yl==yr)return;
    int mdx,mdy;
    mdx=(xl+xr)/2;
    mdy=(yl+yr)/2;
    segmn[idxx][idxy]=inf;
    segmx[idxx][idxy]=0;
    if(build(idxx*2,idxy*2,xl,mdx,yl,mdy))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2][idxy*2]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2][idxy*2]);
    }
    if(build(idxx*2+1,idxy*2,mdx+1,xr,yl,mdy))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2+1][idxy*2]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2+1][idxy*2]);
    }
    if(build(idxx*2,idxy*2+1,xl,mdx,mdy+1,yr))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2][idxy*2+1]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2][idxy*2+1]);
    }
    if(build(idxx*2+1,idxy*2+1,mdx+1,xr,mdy+1,yr))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2+1][idxy*2+1]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2+1][idxy*2+1]);
    }
//    printf("%d %d %d %d %d %d -> %d %d\n",idxx,idxy,xl,xr,yl,yr,segmn[idxx][idxy],segmx[idxx][idxy]);
    return 1;
}
int upt(int idxx,int idxy,int xl,int xr,int yl,int yr,int x,int y,int val)
{
    if(xl>xr)return 0;
    if(yl>yr)return 0;
    if(xr<x || x<xl)return 1;
    if(yr<y || yl>y)return 1;
    if(xl==xr && yl==yr)
    {
        segmn[idxx][idxy]=segmx[idxx][idxy]=val;
        return 1;
    }
    int mdx,mdy;
    mdx=(xl+xr)/2;
    mdy=(yl+yr)/2;
    segmn[idxx][idxy]=inf;
    segmx[idxx][idxy]=0;
    if(upt(idxx*2,idxy*2,xl,mdx,yl,mdy,x,y,val))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2][idxy*2]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2][idxy*2]);
    }
    if(upt(idxx*2+1,idxy*2,mdx+1,xr,yl,mdy,x,y,val))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2+1][idxy*2]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2+1][idxy*2]);
    }
    if(upt(idxx*2,idxy*2+1,xl,mdx,mdy+1,yr,x,y,val))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2][idxy*2+1]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2][idxy*2+1]);
    }
    if(upt(idxx*2+1,idxy*2+1,mdx+1,xr,mdy+1,yr,x,y,val))
    {
        segmn[idxx][idxy]=min(segmn[idxx][idxy],segmn[idxx*2+1][idxy*2+1]);
        segmx[idxx][idxy]=max(segmx[idxx][idxy],segmx[idxx*2+1][idxy*2+1]);
    }
    return 1;
}
int querymn(int idxx,int idxy,int xl,int xr,int yl,int yr,int X1,int X2,int Y1,int Y2)
{
    if(xl>xr)return inf;
    if(yl>yr)return inf;
    if(yl>Y2 || yr<Y1) return inf;
    if(xl>X2 || xr<X1) return inf;
    if(X1<=xl && xr<=X2 && Y1<=yl && yr<=Y2)
    {
 //       printf("%d\n",segmn[idxx][idxy]);
        return segmn[idxx][idxy];
    }
    int mdx,mdy;
    mdx=(xl+xr)/2;
    mdy=(yl+yr)/2;
    int w1,w2,w3,w4;
    w1=querymn(idxx*2,idxy*2,xl,mdx,yl,mdy,X1,X2,Y1,Y2);
    w2=querymn(idxx*2+1,idxy*2,mdx+1,xr,yl,mdy,X1,X2,Y1,Y2);
    w3=querymn(idxx*2,idxy*2+1,xl,mdx,mdy+1,yr,X1,X2,Y1,Y2);
    w4=querymn(idxx*2+1,idxy*2+1,mdx+1,xr,mdy+1,yr,X1,X2,Y1,Y2);
 //   printf("%d\n",min(min(w1,w2),min(w3,w4)));
    return min(min(w1,w2),min(w3,w4));
}
int querymx(int idxx,int idxy,int xl,int xr,int yl,int yr,int X1,int X2,int Y1,int Y2)
{
    if(xl>xr)return 0;
    if(yl>yr)return 0;
    if(yl>Y2 || yr<Y1) return 0;
    if(xl>X2 || xr<X1) return 0;
    if(X1<=xl && xr<=X2 && Y1<=yl && yr<=Y2)
    {
        return segmx[idxx][idxy];
    }
    int mdx,mdy;
    mdx=(xl+xr)/2;
    mdy=(yl+yr)/2;
    int w1,w2,w3,w4;
    w1=querymx(idxx*2,idxy*2,xl,mdx,yl,mdy,X1,X2,Y1,Y2);
    w2=querymx(idxx*2+1,idxy*2,mdx+1,xr,yl,mdy,X1,X2,Y1,Y2);
    w3=querymx(idxx*2,idxy*2+1,xl,mdx,mdy+1,yr,X1,X2,Y1,Y2);
    w4=querymx(idxx*2+1,idxy*2+1,mdx+1,xr,mdy+1,yr,X1,X2,Y1,Y2);
    return max(max(w1,w2),max(w3,w4));
}
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    build(1,1,1,n,1,m);
    sint(k);
    while(k--)
    {
        sstring(c,5);
        if(c[0]=='c')
        {
            sint3(x,y,val);
            upt(1,1,1,n,1,m,x,y,val);
        }
        if(c[0]=='q')
        {
            sint2(x,y);
            sint2(d,r);
            printf("%d %d\n",querymx(1,1,1,n,1,m,x,d,y,r),querymn(1,1,1,n,1,m,x,d,y,r));
        }
    }
}
