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
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define inf INT_MAX
#define F first
#define S second
#define pause system("pause")
#define endl printf("\n")
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define debug(x) cout<< #x << " = " << x;endl;
int apsp[10][10];
int dv=1;
int dist(int x,int y)
{
    if((x>dv) ^ (y>dv))return 1e9;
    if(x>dv)x-=dv,y-=dv;
    int cnt=0;
    while(x!=y)
    {
        if(x>y)x/=2;
        else y/=2;
        cnt++;
    }
    return cnt;
}
int warp[15][15];
int re[15];
int main()
{
    OPEN;
    SEND;
    for(int i=0;i<15;i++)for(int j=0;j<15;j++)warp[i][j]=1e9;
    sint3(k,l,q);
    dv=1<<k;
    for(int i=0;i<l;i++)
    {
        int2(re[i],re[i+l]);
        warp[i][i+l]=1;
        warp[i+l][i]=1;
    }
    FOR(i,0,l)FOR(j,0,l)     warp[i][j]=dist(re[i],re[j]);
    FOR(i,l,2*l)FOR(j,l,2*l) warp[i][j]=dist(re[i],re[j]);
    FOR(m,0,2*l)FOR(i,0,2*l)FOR(j,0,2*l)
        warp[i][j]=min(warp[i][j],warp[i][m]+warp[m][j]);
    while(q--)
    {
        sint2(x,y);
        int ans=dist(x,y);
        for(int i=0;i<2*l;i++)
            for(int j=0;j<2*l;j++)
                ans=min(ans,dist(x,re[i])+warp[i][j]+dist(re[j],y));
        printf("%d\n",ans);
        // ans=1001;
        assert(ans<1000);
    }
}
/*

*/
