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
vector<pair<ii,int> > v[5];
int rnk[100005];
int prv[100005];
int plcp[100005];
int lcp[100005];
bitset<100005> bt;
int rev[100005];
int main()
{
    sint2(n,m);
    cstring(s,n+5);
    for(int i=0;i<n;i++)
    {
        v[0].pb(mkp(mkp(0,s[i]-'A'),i));
    }
    sort(all(v[0]));
    int rk=0;
    for(int i=0;i<n;i++)
    {
        rk++;
        if(i!=0 && v[0][i].F==v[0][i-1].F)rk--;
        rnk[v[0][i].S]=rk;
    }
    int b=1,o;
    int t=1;
    // debug(1);
    while(t<=n)
    {
        b++;
        b%=2;
        o=(b+1)%2;
        v[o].clear();
        for(int i=0;i<n;i++)
        {
            int u=v[b][i].S;
            v[o].pb(mkp(mkp(rnk[u],rnk[u+t]),u));
        }
        sort(all(v[o]));
        rk=0;
        for(int i=0;i<n;i++)
        {
            rk++;
            if(i!=0 && v[o][i-1].F==v[o][i].F)rk--;
            rnk[v[o][i].S]=rk;
        }
        if(rk==n)break;
        t*=2;
    }
    /*
    endl;
    for(int i=0;i<v[o].size();i++)
    {
        int y=v[o][i].S;
        for(int j=y;j<n;j++)
        {
            printf("%c",s[j]);
        }
        endl;
    }
    endl;
    // */
    prv[v[o][0].S]=-1;
    for(int i=1;i<n;i++)
    {
        prv[v[o][i].S]=v[o][i-1].S;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(prv[i]==-1)continue;
        while(s[i+cnt]==s[prv[i]+cnt])cnt++;
        debug(cnt);
        plcp[i]=cnt;
        cnt=max(cnt-1,0);
    }
    for(int i=0;i<n;i++)
    {
        int u=v[o][i].S;
        lcp[i+1]=plcp[u];
        rev[u+1]=i;
        // debug(lcp[i]);
    }
    bt[rev[1]]=1;
    while(m--)
    {
        sint(cmd);
        if(cmd==1)
        {
            sint(tmp);
            if(bt[tmp])
            {
                printf("%d\n",n-tmp+1);
                continue;
            }

        }
        else if(cmd==2)
        {
            sint(tmp);
            tmp=rev[tmp];
            bt[tmp]=1;
            ??ขี้เกียจเขียนต่อ??
        }
    }
}
/*

*/
