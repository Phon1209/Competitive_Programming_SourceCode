#include<bits/stdc++.h>
using namespace std;
/*
Problem : Palindrome (True Solution)
*/
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
#define MOD 1000000007
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
map<ii,int> mp;
vi v[8005];
bool chk[8005];
int main()
{
    sint3(n,k,m);
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        if(x>y)swap(x,y);
        ii key;
        int md=(x+y)/2;
        if((x+y)%2)
        {
            key=mkp(md,md+1);
        }
        else key=mkp(md,md);
        mp[key]=max(mp[key],md-x);
    }
    map<ii,int>::iterator it;
    it=mp.begin();
    while(it!=mp.end())
    {
        int val=(*it).S;
        int x,y;
        x=(*it).F.F;
        y=(*it).F.S;
        for(int i=0;i<=val;i++)
        {
            v[x-i].pb(y+i);
            v[y+i].pb(x-i);
        }
        it++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(chk[i])continue;
        cnt++;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=0;i<v[u].size();i++)if(!chk[v[u][i]])q.push(v[u][i]),chk[v[u][i]]=1;
        }
    }
    ll ans=1;
    for(int i=0;i<cnt;i++)
    {
        ans*=k;
        ans%=MOD;
    }
    printf("%lld\n",ans);
}
/*

*/
