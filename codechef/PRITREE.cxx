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
typedef unsigned long long ull;

ull seed=3905348978240129619LL;
ull multiplier=0x5DEECE66DLL;
ull addend=0xBLL;
ull mask = (1LL << 48) - 1;
int version=1;
long long nextBits(int bits)
{
    if (bits <= 48)
    {
        seed = (seed * multiplier + addend) & mask;
        return (long long)(seed >> (48 - bits));
    }
    else
    {
        int lowerBitCount = (version == 0 ? 31 : 32);

        long long left = (nextBits(31) << 32);
        long long right = nextBits(lowerBitCount);
        return left ^ right;
    }
}
int next(int n)
{
    if ((n & -n) == n)  // n is a power of 2
        return (int)((n * (long long)nextBits(31)) >> 31);

    const long long limit = INT_MAX / n * n;

    long long bits;
    do {
        bits = nextBits(31);
    } while (bits >= limit);

    return int(bits % n);
}
int a[1005];
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
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        p[fs(i)]=fs(j);
    }
    void clear()
    {
        for(int i=0;i<p.size();i++)p[i]=i;
    }
};
vector<bool> prime;
bool leaf[1005];
int deg[1005];
int main()
{
    srand(14);
    prime.resize(20005);
    prime[1]=1;
    for(int i=4;i<=20000;i+=2)prime[i]=1;
    for(int i=3;i<=20000;i+=2)
        if(!prime[i])
            for(int j=i+i;j<=20000;j+=i)prime[j]=1;
    sint(n);
    bool all=true;
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        if(!prime[a[i]])
            leaf[i]=1;
        else all=false;
    }
    if(all)
    {
        for(int i=2;i<=n;i++)printf("%d %d\n",1,i);
        return 0;
    }
    vector<pair<int,ii> > v;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            v.pb(mkp(next(INT_MAX/2)*rand()+rand(),mkp(i,j)));
        }
    }
    sort(all(v));
    UnionFind uf(n);
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].S.F;
        int y=v[i].S.S;
        // debug(i);
        if(!uf.iss(x,y))
        {
            if(leaf[x] && leaf[y])continue;
            if(leaf[x] && deg[x]==1)continue;
            if(leaf[y] && deg[y]==1)continue;
            printf("%d %d\n",x,y);
            uf.us(x,y);
        }
    }
}
/*

*/
