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
int dl[205],dr[205],cl[105],rw[105];
int mp[105][105];
int dir[10];
bool ok;
int n,m;
vector<pair<int,ii> >  v;
void chk(int x,int y,int code)
{
    if(x<=0 || x>n)return;
    if(y<=0 || y>m)return;
    ok=1;
    dir[code]++;
    if(mp[x][y]!=0)return;
    mp[x][y]=code;
    v.pb(mkp(code,mkp(x,y)));
    rw[x]++;
    cl[y]++;
    dl[x+y]++;
    dr[y-x+100]++;
}
bool pos(int x,int y)
{
    if(x<=0 || x>n)return 0;
    if(y<=0 || y>m)return 0;
    return 1;
}
void _main()
{
    memset(dl,0,sizeof(dl));
    memset(dr,0,sizeof(dr));
    memset(rw,0,sizeof(rw));
    memset(cl,0,sizeof(cl));
    v.clear();
    memset(mp,0,sizeof(mp));
    memset(dir,0,sizeof(dir));
    ll ans=0;
    int2(n,m);
    sint2(x,y);
    for(int i=1;;i++)
    {
        ok=false;
        chk(x+i,y-i,1);
        chk(x+i,y,2);
        chk(x+i,y+i,3);
        chk(x,y-i,4);
        chk(x,y+i,5);
        chk(x-i,y-i,6);
        chk(x-i,y,7);
        chk(x-i,y+i,8);
        if(!ok)break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x==i && j==y)continue;
            ll tmp=n*m;
            tmp-=n;
            tmp-=m;
            tmp-=min(min(n,m),min(i+j-1,n+m-(i+j)+1));
            tmp-=min(min(n,m),min(m-j+i,j-i+n));
            tmp+=3;
            if(mp[i][j]!=0)tmp+=dir[9-mp[i][j]];
            else tmp--;
            // debug(tmp);
            ans+=tmp;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
