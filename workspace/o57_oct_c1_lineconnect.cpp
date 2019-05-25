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
int cost[100005];
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=0;i<n;i++)p[i]=i;
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        p[x]=y;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return (fs(i)==fs(j));
    }
};
int main()
{
    sint(n);
    vi v,v2;
    vi::iterator it,it2;
    for(int i=0;i<n;i++)
    {
        int1(cost[i]);
    }
    UnionFind uf(n);
    for(int i=0;i<n-2;i++)
    {
        sint2(x,y);
        x--;
        y--;
//        printf("%d %d\n",x,y);
        uf.us(x,y);
    }
    int t=uf.fs(0);
    for(int i=0;i<n;i++)
    {
        if(uf.fs(i)==t)
        {
            v.pb(cost[i]);
        }
        else
        {
            v2.pb(cost[i]);
        }
    }
    sort(all(v));
    sort(all(v2));
    /*
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
    endl;
    for(int i=0;i<v2.size();i++)
    {
        printf("%d ",v2[i]);
    }
    endl;
    */
    int mx=inf;
    for(int i=0;i<v.size();i++)
    {
        it=lower_bound(all(v2),v[i]-mx-mx);
        it2=upper_bound(all(v2),v[i]+mx+mx);
        ///*
        if(it==v2.begin() && it2==v2.end())
        {
            for(int j=0;j<v2.size();j++)
            {
                mx=min(mx,abs(v[i]-v2[j]));
            }
//            continue;
        }
        //*/
        if(it2!=v2.end())
            it2++;
        while(it!=it2)
        {
            mx=min(mx,abs(v[i]-(*it)));
            it++;
        }
    }
    printf("%d\n",mx);
}
/*

*/
