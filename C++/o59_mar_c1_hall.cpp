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
vector<pair<ii,int> >  v[5];
int rnk[100005];
int a[100005];
int prv[100005];
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        a[i]=tmp;
        v[0].pb(mkp(mkp(0,tmp),i));
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
    while(t<=n)
    {
        b++;
        b%=2;
        o=(b+1)%2;
        v[o].clear();
        for(int i=0;i<n;i++)
        {
            int u=v[b][i].S;
            v[o].pb(mkp(mkp(rnk[u],rnk[(u+t)%n]),u));
        }
        sort(all(v[o]));
        rk=0;
        for(int i=0;i<n;i++)
        {
            rk++;
            if(i!=0 && v[o][i].F==v[o][i-1].F)rk--;
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
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[(y+j)%n]);
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
    for(int i=0;i<n;i++)
    {
        printf("%d\n",prv[i]);
    }
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(prv[i]==-1)continue;
        while(a[(i+cnt)%n]==a[(prv[i]+cnt)%n])
        {
            cnt++;
            if(cnt==n)break;
        }
        ans=max(ans,cnt);
        cnt=max(cnt-1,0);
    }
    printf("%d\n",ans==n? -1:ans);
}

/*

*/
