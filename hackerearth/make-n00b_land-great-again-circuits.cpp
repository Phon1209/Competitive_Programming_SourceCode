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
vector<pair<int,pair<ll,ll> > > order;
vi v[100005];
vi own[100005];
ll want[100005];
int L[1000005];
int R[1000005];
int ans[100005];
void apply()
{

}
ll getmoney(int idx)
{

}
int main()
{
    sint2(n,m);
    for(int i=2;i<=n;i++)
    {
        sint(tmp);
        v[tmp].pb(i);
    }
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        own[tmp].pb(i);
    }
    for(int i=1;i<=m;i++)
    {
        slong(tmp);
        want[i]=tmp;
    }
    sint(q);
    for(int i=0;i<q;i++)
    {
        sint3(x,f,d);
        order.pb(mkp(x,mkp(f,d)));
    }
    for(int i=1;i<=m;i++)
    {
        L[i]=0;
        R[i]=q-1;
        ans[i]=inf;
    }
    bool again=true;
    while(again)
    {
        again=0;
        queue<int> chk[100005];
        for(i=1;i<=m;i++)
        {
            if(L[i]<=R[i])
            {
                int md=(L[i]+R[i])/2;
                chk[md].pb(i);
                again=1;
            }
        }
        for(int i=0;i<q;i++)
        {
            apply(i);
            while(!chk[md].empty())
            {
                int u=chk[md].front();
                chk[md].pop();
                ll mny=0;
                for(auto idx:v[u])
                {
                    mny+=getmoney(idx);
                }
                if(mny<want[u])
                {
                    L[u]=i+1;
                }
                else
                {
                    ans[u]=min(ans[u],i+1);
                    R[u]=i-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==inf)printf("reks\n");
        else printf("%d\n",ans[i]);
    }
}
/*
BUG
*/
