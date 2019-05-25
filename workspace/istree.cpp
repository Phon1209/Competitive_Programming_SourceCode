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
int in[1000005];
int  p[1000005];
class UnionFind
{
public:
    UnionFind(int n)
    {
        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        p[x]=y;
    }
    bool iss(int i,int j)
    {
        return (fs(i)==fs(j));
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
};
bool ok=1;
int main()
{
    sint(n);
    UnionFind uf(n);
    int cnt=n;
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        in[y]++;
        if(!uf.iss(x,y))
        {
            uf.us(x,y);
            cnt--;
        }
    }
    bool chk=0;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        {
            if(chk)ok=0;
            chk=1;
        }
    }
    if(cnt!=1)ok=0;
    printf("%s\n",(ok)? "Yes":"No");
}
