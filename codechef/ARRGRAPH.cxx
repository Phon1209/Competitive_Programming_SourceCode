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
vi p;
int fs(int i)
{
    return (p[i]==i)? i:(p[i]=fs(p[i]));
}
void us(int i,int j)
{
    p[fs(i)]=fs(j);
}
bool iss(int i,int j)
{
    return (fs(i)==fs(j));
}
void _main()
{
    vi v;
    sint(n);
    p.assign(n+5,0);
    bool ex=0;
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        if(tmp==47)ex=1;
        v.pb(tmp);
    }
    int cnt=n;
    FOR(i,0,n)
        FOR(j,i+1,n)
        {
            int u=__gcd(v[i],v[j]);
            if(u==1 && !iss(i,j))
            {
                us(i,j);
                cnt--;
            }
        }
    if(cnt==1)
    {
        printf("0\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",v[i]);
        }
        endl;
        return ;
    }
    printf("1\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",v[i]);
    }
    printf("%d\n",ex? 2:47);

}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
