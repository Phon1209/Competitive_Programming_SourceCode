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
int sg[400005];
int sglz[400005];
int a[100005];
int R[100005];
void upt(int idx,int l,int r,int x,int y,int val)
{
    if(y<l || x>r)return;
    if(x<=l && r<=y)
    {
        sg[idx]+=val;
        sglz[idx]+=val;
        return;
    }
    int md=(l+r)/2;
    if(sglz[idx])
    {
        sg[idx*2]+=sglz[idx];
        sg[idx*2+1]+=sglz[idx];
        sglz[idx*2]+=sglz[idx];
        sglz[idx*2+1]+=sglz[idx];
        sglz[idx]=0;
    }
    upt(idx*2,l,md,x,y,val);
    upt(idx*2+1,md+1,r,x,y,val);
    sg[idx]=max(sg[idx*2],sg[idx*2+1]);
}
int pos[100005];
int main()
{
    sint3(n,h,l);
    for(int i=1;i<=n;i++)
    {
        int2(pos[i],a[i]);
    }
    int p2=1;
    for(int ptr=1;ptr<=n;ptr++)
    {
        while(p2<=n && pos[p2]-pos[ptr]<=h)
        {
            R[p2++]=ptr;
        }
    }
    vii v;
    for(int i=1;i<=n;i++)
    {
        v.pb(mkp(a[i],i));
    }
    sort(all(v));
    p2=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u;
        while(p2<n && v[p2].F-l<=v[i].F)
        {
            u=v[p2].S;
            upt(1,1,n,R[u],u,1);
            p2++;
        }
        ans=max(ans,sg[1]);
        u=v[i].S;
        upt(1,1,n,R[u],u,-1);
    }
    printf("%d\n",ans);
}
/*

*/
