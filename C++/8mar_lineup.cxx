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
map<int,int> mp;
int cnt[100005];
int main()
{
    sint2(n,k);
    vi v;
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        v.pb(tmp);
        mp[tmp];
    }
    int num=0;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        mp[it->F]=++num;
        it++;
    }
    int dif=0;
    int mx=0;
    queue<int> q;
    // debug(1);
    for(int i=0;i<n;i++)
    {
        int u=mp[v[i]];
        if(cnt[u]==0)dif++;
        cnt[u]++;
        q.push(u);
        // printf("%d %d %d\n",i,u,dif);
        while(dif>k+1)
        {
            int o=q.front();
            // debug(o);
            cnt[o]--;
            // debug(cnt[o]);
            if(cnt[o]==0)dif--;
            q.pop();
        }
        mx=max(mx,cnt[u]);
        // debug(mx);
    }
    printf("%d\n",mx);
}
/*

*/
