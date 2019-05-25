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
typedef pair<ll,ll> pll;

const ll MOD1=1000000007;
const ll MOD2=2038074743;
const ll H=123456789;
pll p[100005];
pll add(pll a,pll b){return pll((a.F+b.F)%MOD1,(a.S+b.S)%MOD2);}
pll subt(pll a,pll b){return add({MOD1,MOD2},add(a,{-b.F,-b.S}));}
pll mul(pll a,pll b){return {(a.F*b.F)%MOD1,(a.S*b.S)%MOD2};}

struct Node
{
    Node *l,*r;
    pll val,hsh;
    bool lz=0;
    Node(pll sum,Node *l,Node *r,pll hsh,bool lz):
        val(sum),l(l),r(r),hsh(hsh),lz(lz){}
    void shift();
};
Node *newleaf(pll val)
{
    return new Node(val,NULL,NULL,pll({0,0}),0);
}
Node *newpar(Node *l,Node *r)
{
    return new Node(add(l->val,r->val),l,r,add(l->hsh,r->hsh),0);
}
Node *newlz(Node *now)
{
    return new Node(now->val,now->l,now->r,subt(now->val,now->hsh),!now->lz);
}
void Node::shift()
{
    if(!lz)return;
    lz=0;
    if(l)
    {
        l=newlz(l);
        r=newlz(r);
    }
}
Node *build(int l,int r)
{
    if(l==r)
    {
        return newleaf(p[l]);
    }
    int md=(l+r)/2;
    return newpar(build(l,md),build(md+1,r));
}
void print(Node *now)
{
    now->shift();
    if(now->l==NULL)
        printf("%d",(now->hsh!=pll({0,0}))? 1:0);
    else
        print(now->l),print(now->r);
}
Node *upt(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return now;
    now->shift();
    if(x<=l && r<=y)
    {
        return newlz(now);
    }
    int md=(l+r)/2;
    return newpar(upt(now->l,l,md,x,y),upt(now->r,md+1,r,x,y));
}
bool cmp(Node *a,Node *b)
{
    a->shift();
    b->shift();
    if(!a->l)return (a->hsh==pll({0,0})) or (b->hsh!=pll({0,0}));
    if(a->l->hsh==b->l->hsh)return cmp(a->r,b->r);
    else return cmp(a->l,b->l);
}
int main()
{
    sint2(n,q);
    p[0]=pll(1,1);
    for(int i=1;i<=n;i++)
    {
        p[i]=mul(p[i-1],pll(H,H));
    }
    Node *last=build(1,n);
    Node *ans=last;
    while(q--)
    {
        sint2(x,y);
        last=upt(last,1,n,x,y);
        if(cmp(ans,last))
            ans=last;
    }
    print(ans);
    endl;
}
/*

*/
