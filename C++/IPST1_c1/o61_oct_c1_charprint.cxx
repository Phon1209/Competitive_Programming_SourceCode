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

int conv(char c)
{
    return c-'a'+1;
}
int fw[300005];
void add(int idx,int val)
{
    while(idx<=300000)
    {
        fw[idx]+=val;
        idx+=(idx&-idx);
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
queue<int> q[30];
int main()
{
    sint(mode);
    sstring(s);
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        add(i+1,1);
        int u=conv(c);
        q[u].push(i+1);
    }
    sstring(w);
    ll ans=0;
    for(int i=0;i<w.size();i++)
    {
        int u=conv(w[i]);
        if(q[u].empty())
        {
            printf("-1\n");
            return 0;
        }
        int y=q[u].front();
        q[u].pop();
        ans+=sum(y);
        if(mode)add(y,-1);
    }
    printf("%lld\n",ans);
}
/*

*/
