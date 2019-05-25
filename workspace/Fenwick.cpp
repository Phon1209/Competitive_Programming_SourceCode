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
vi v;
int a[10005];
void build(int idx,int val)
{
    int y=idx+(idx&-idx);
    a[y]+=val;
    a[idx]+=val;
}
void add(int idx,int val,int lim)
{
    while(idx<=lim)
    {
        a[idx]+=val;
        idx+=(idx&-idx);
    }
}
void pt(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
        a[i]=0;
    }
    endl;
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=a[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
    }
    for(int i=0;i<n;i++)
    {
        build(i+1,v[i]);
    }
    pt(n);
    for(int i=0;i<n;i++)
    {
        add(i+1,v[i],n);
    }
    pt(n);
}
