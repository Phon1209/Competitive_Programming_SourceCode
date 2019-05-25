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
#define eb emplace_back
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
ll dist(int x,int y,int x1,int y1)
{
    int dif=abs(y-y1);
    // debug(dif);
    if(x+dif<=x1 || x-dif>=x1)
    {
        if(x+dif<=x1)return (x1-x);
        else return x-x1;
    }
    if(x1<x+dif && x-dif<x1)
    {
        int difx=abs(x-x1);
        return dif+((difx%2)^(dif%2));
    }
    while(1);
    return -1;
}
ii sp[205];
ll spdist[205][205];
int main()
{
    for(int i=0;i<=200;i++)
        FOR(j,0,201)spdist[i][j]=(i==j)? 0:4611686018427387894;
    sint2(m,q);
    for(int i=0;i<m;i++)
    {
        int2(sp[i].F,sp[i].S);
        int2(sp[i+m].F,sp[i+m].S);
        spdist[i][i+m]=1;
        spdist[i+m][i]=1;
    }
    FOR(i,0,2*m)
        FOR(j,0,2*m)
            spdist[i][j]=min(spdist[i][j],dist(sp[i].F,sp[i].S,sp[j].F,sp[j].S));

    FOR(k,0,2*m)
        FOR(i,0,2*m)
            FOR(j,0,2*m)
            {
                spdist[i][j]=min(spdist[i][j],spdist[i][k]+spdist[k][j]);
            }
    /*
    FOR(i,0,2*m)
    {    FOR(j,0,2*m)
        {
            printf("%d ",spdist[i][j]);
        }
        endl;
    }
    */
    for(int i=0;i<q;i++)
    {
        sint2(x,y);
        sint2(x1,y1);
        ll ans=dist(x,y,x1,y1);
        FOR(j,0,2*m)
        FOR(k,0,2*m)
        ans=min(ans,dist(x,y,sp[j].F,sp[j].S)+dist(sp[k].F,sp[k].S,x1,y1)+spdist[j][k]);
        printf("%lld\n",ans);

    }
}
/*

*/
