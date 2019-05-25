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
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        p[x]=y;
    }
};
vector<pair<int,ii> > v;
ll a[5005];
int main()
{
    sint3(n,m,q);
    UnionFind uf(n);
    while(m--)
    {
        sint3(x,y,w);
        v.pb(mkp(w,mkp(x,y)));
    }
    sort(all(v));
    ll cost=0;
    int cnt=n;
    for(int i=0;i<v.size();i++)
    {
        int x,y;
        x=v[i].S.F;
        y=v[i].S.S;
        if(!uf.iss(x,y))
        {
            cost=max(cost,(ll)v[i].F);
            uf.us(x,y);
            cnt--;
            a[cnt]=cost;
        }
    }
    while(q--)
    {
        sint(tmp);
        printf("%lld\n",a[tmp]);
    }
}
/*

*/
