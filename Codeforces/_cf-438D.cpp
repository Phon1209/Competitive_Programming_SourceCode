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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
struct Node
{
    ll val;
    ll mx=0,mn=0;
    Node *l,*r;
    void setval(ll v)
    {
        val=v;
        mx=v;
        mn=v;
    }
    void compute()
    {
        val=l->val+r->val;
        mx=max(l->mx,r->mx);
        mn=min(l->mn,r->mn);
    }
    bool exn()
    {
        return (mx==mn);
    }
    void allmod(ll mod)
    {
        mx%=mod;
        mn%=mod;
        val%=mod;
    }
};
ll a[100005];
Node *build(int l,int r)
{
    Node *now=new Node();
    if(l==r)
    {
        now->setval(a[l]);
        return now;
    }
    int md=(l+r)/2;
    now->l=build(l,md);
    now->r=build(md+1,r);
    now->compute();
    return now;
}
void changenum(Node *now,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        now->setval(val);
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)changenum(now->l,l,md,pos,val);
    else       changenum(now->r,md+1,r,pos,val);
    now->compute();
    return;
}
void modseg(Node *now,int l,int r,int x,int y,ll mod)
{
    if(y<l || x>r || (now->mx)<mod)return;
    if(l==r)
    {
        now->val%=mod;
        now->mx%=mod;
        now->mn%=mod;
        return;
    }
    int md=(l+r)/2;
    modseg(now->l,l,md,x,y,mod);
    modseg(now->r,md+1,r,x,y,mod);
    now->compute();
    return;
}
ll query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    ll A,B;
    A=query(now->l,l,md,x,y);
    B=query(now->r,md+1,r,x,y);
    // debug(A);
    // debug(B);
    return A+B;
}
int main()
{
    // OPEN;
    // SEND;
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    Node *root=build(1,n);
    while(m--)
    {
        sint(cmd);
        if(cmd==1)
        {
            sint2(x,y);
            printf("%lld\n",query(root,1,n,x,y));
        }
        if(cmd==2)
        {
            sint2(x,y);
            slong(mod);
            modseg(root,1,n,x,y,mod);
        }
        if(cmd==3)
        {
            sint(pos);
            slong(val);
            changenum(root,1,n,pos,val);
        }
    }
}
