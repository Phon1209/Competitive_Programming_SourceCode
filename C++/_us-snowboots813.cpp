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
int a[100005];
int gf[100005];
int gb[100005];
bool ans[100005];
int main()
{
    IN("snowboots.in");
    OUT("snowboots.out")
    vii v,v2;
    sint2(n,b);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(mkp(tmp,i));
    }
    sort(all(v));
    for(int i=0;i<b;i++)
    {
        sint(dpt);
        int1(a[i]);
        v2.pb(mkp(dpt,i));
    }
    sort(all(v2));
    for(int i=0;i<n;i++)
    {
        gf[i]=i+1;
        gb[i]=i-1;
    }
    int cnt=n-1;
    int mx=1;
    for(int i=v2.size()-1;i>=0;i--)
    {
        int use=v2[i].F;
        // debug(use);
        while(cnt>=0 && v[cnt].F>use)
        {
            // debug(v[cnt].F);
            int pos=v[cnt].S;
            gf[gb[pos]]=gf[pos];
            gb[gf[pos]]=gb[pos];
            cnt--;
            mx=max(mx,gf[pos]-gb[pos]);
        }
        // debug(mx);
        // debug(a[v2[i].S]);
        ans[v2[i].S]=1;
        if(mx>a[v2[i].S])ans[v2[i].S]=0;
    }
    for(int i=0;i<b;i++)
    {
        printf("%d\n",(ans[i])? 1:0);
    }
}
