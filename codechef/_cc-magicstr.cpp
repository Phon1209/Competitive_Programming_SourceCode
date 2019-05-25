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
#define MOD 1000000007

class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=0;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:p[i]=fs(p[i]);
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        p[fs(i)]=fs(j);
    }
};
void _main()
{
    sint2(n,m);
    vector<pair<ii,int> > v;
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        int md=(x+y)/2;
        if((x+y)%2==1)v.pb(mkp(mkp(md,md+1),-(md-x)));
        else v.pb(mkp(mkp(md,md),-(md-x)));
    }
    UnionFind uf(n);
    sort(all(v));
    ii past={-1,-1};
    int cnt=n;
    for(int i=0;i<m;i++)
    {
        // printf("%d %d %d %d %d\n",past.F,past.S,v[i].F.F,v[i].F.S,v[i].S);
        if(v[i].F!=past)
        {
            past=v[i].F;
            int x,y;
            x=v[i].F.F;
            y=v[i].F.S;
            for(int j=0;j<=-v[i].S;j++)
            {
                // printf(">>%d %d\n",x-j,y+j);
                if(!uf.iss(x-j,y+j))
                {
                    // printf(">%d %d\n",x-j,y+j);
                    uf.us(x-j,y+j);
                    cnt--;
                }
                if(cnt==1)break;
            }
        }
        if(cnt==1)break;
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",i,uf.fs(i));
    }
    */
    ll ans=1;
    for(int i=1;i<=cnt;i++){
        ans*=26;
        ans%=MOD;
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
