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
int sgmn[2005][2005];
int sgmx[2005][2005];
void buildy(int idxx,int idxy,int lx,int ly,int rx,int ry)
{
    if(rx==ry)
    {
        if(lx==ly) sgmn[idxx][idxy]=sgmx[idxx][idxy]=a[lx][rx];
        else
        {
          sgmn[idxx][idxy]=min(sgmn[idxx*2][idxy],sgmn[idxx*2+1][idxy]);
          sgmx[idxx][idxy]=max(sgmx[idxx*2][idxy],sgmx[idxx*2+1][idxy]);
        }
        return;
    }
    int md=(rx+ry)/2;
    buildy(idxx,idxy*2,lx,ly,rx,md);
    buildy(idxx,idxy*2+1,lx,ly,md+1,ry);
    sgmn[idxx][idxy]=min(sgmn[idxx][idxy*2],sgmn[idxx][idxy*2+1]);
    sgmx[idxx][idxy]=max(sgmx[idxx][idxy*2],sgmx[idxx][idxy*2+1]);
}
void build(int idxx,int idxy,int lx,int ly,int rx,int ry)
{
    if(lx==ly)
    {
        buildy(idxx,idxy,lx,ly,rx,ry);
        return;
    }
    int md=(lx+ly)/2;
    build(idxx*2,idxy,lx,md,rx,ry);
    build(idxx*2+1,idxy,md+1,ly,rx,ry);
    buildy(idxx,idxy,lx,ly,rx,ry);
}
void upy(int idxx,int idxy,int lx,int ly,int rx,int ry,int posx,int posy,int val)
{
//  printf(">%d %d %d %d %d %d %d %d %d\n",idxx,idxy,lx,ly,rx,ry,posx,posy,val);
    if(rx==ry)
    {
      if(lx==ly)
      {
        sgmn[idxx][idxy]=val;
        sgmx[idxx][idxy]=val;
      }
      else
      {
        sgmn[idxx][idxy]=min(sgmn[idxx*2][idxy],sgmn[idxx*2+1][idxy]);
        sgmx[idxx][idxy]=max(sgmx[idxx*2][idxy],sgmx[idxx*2+1][idxy]);
      }
      return;
    }
    int md=(rx+ry)/2;
    if(posy<=md)
    {
      upy(idxx,idxy*2,lx,ly,rx,md,posx,posy,val);
    }
    else
    {
      upy(idxx,idxy*2+1,lx,ly,md+1,ry,posx,posy,val);
    }
//    printf("%d %d %d %d\n",idxx,idxy,sgmx[idxx][idxy*2],sgmx[idxx][idxy*2+1]);
    sgmn[idxx][idxy]=min(sgmn[idxx][idxy*2],sgmn[idxx][idxy*2+1]);
    sgmx[idxx][idxy]=max(sgmx[idxx][idxy*2],sgmx[idxx][idxy*2+1]);
}
void up(int idxx,int idxy,int lx,int ly,int rx,int ry,int posx,int posy,int val)
{
//  printf("%d %d %d %d %d %d %d %d %d\n",idxx,idxy,lx,ly,rx,ry,posx,posy,val);
    if(lx==ly)
    {
        upy(idxx,idxy,lx,ly,rx,ry,posx,posy,val);
        return;
    }
    int md=(lx+ly)/2;
    if(posx<=md)
    {
      up(idxx*2,idxy,lx,md,rx,ry,posx,posy,val);
    }
    else
    {
      up(idxx*2+1,idxy,md+1,ly,rx,ry,posx,posy,val);
    }
    upy(idxx,idxy,lx,ly,rx,ry,posx,posy,val);
}
int qmxy(int idxx,int idxy,int rx,int ry,int y,int r)
{
//  printf(">%d %d %d %d %d %d\n",idxx,idxy,rx,ry,y,r);
  if(ry<rx)return -1;
  if(r<rx || y>ry)return -1;
  if(y<=rx && ry<=r)
  {
    return sgmx[idxx][idxy];
  }
  int md=(rx+ry)/2;
  return max(qmxy(idxx,idxy*2,rx,md,y,r),qmxy(idxx,idxy*2+1,md+1,ry,y,r));
}
int qmx(int idxx,int idxy,int lx,int ly,int rx,int ry,int x,int y,int d,int r)
{
//  printf("%d %d %d %d %d %d\n",idxx,idxy,lx,ly,x,d);
  if(lx>ly)return -1;
  if(d<lx || x>ly)return -1;
  if(x<=lx && ly<=d)
  {
//    printf("A\n");
    return qmxy(idxx,idxy,rx,ry,y,r);
  }
  int md=(lx+ly)/2;
  return max(qmx(idxx*2,idxy,lx,md,rx,ry,x,y,d,r),qmx(idxx*2+1,idxy,md+1,ly,rx,ry,x,y,d,r));
}
int qmny(int idxx,int idxy,int rx,int ry,int y,int r)
{
//  printf(">%d %d %d %d %d %d\n",idxx,idxy,rx,ry,y,r);
  if(ry<rx)return inf;
  if(r<rx || y>ry)return inf;
  if(y<=rx && ry<=r)
  {
    return sgmn[idxx][idxy];
  }
  int md=(rx+ry)/2;
  return min(qmny(idxx,idxy*2,rx,md,y,r),qmny(idxx,idxy*2+1,md+1,ry,y,r));
}
int qmn(int idxx,int idxy,int lx,int ly,int rx,int ry,int x,int y,int d,int r)
{  //printf("%d %d %d %d %d %d\n",idxx,idxy,lx,ly,x,d);

  if(lx>ly)return inf;
  if(d<lx || x>ly)return inf;
  if(x<=lx && ly<=d)
  {
//    printf("A\n");
    return qmny(idxx,idxy,rx,ry,y,r);
  }
  int md=(lx+ly)/2;
  return min(qmn(idxx*2,idxy,lx,md,rx,ry,x,y,d,r),qmn(idxx*2+1,idxy,md+1,ly,rx,ry,x,y,d,r));
}
int main()
{
    sint2(n,m);
    FOR(i,1,n+1)
        FOR(j,1,m+1)
            int1(a[i][j]);
    build(1,1,1,n,1,m);
    sint(p);
    while(p--)
    {
//        printf("%d\n",p);
        sstring(cm,5);
        if(cm[0]=='q')
        {
            sint2(x,y);
            sint2(d,r);
            int mx,mn;
            mx=qmx(1,1,1,n,1,m,x,y,d,r);
            mn=qmn(1,1,1,n,1,m,x,y,d,r);
            printf("%d %d\n",mx,mn);
        }
        if(cm[0]=='c')
        {
            sint3(x,y,val);
            up(1,1,1,n,1,m,x,y,val);
        }
    }
}
