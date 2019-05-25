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
struct Node
{
    int val;
    int suf=0,pre=0;
    bool full=0;
    Node *l,*r;
    Node(int val,Node *l,Node *r):
        val(val),pre(val),suf(val),l(l),r(r){}
    void compute(int X,int Y)
    {
        pre=l->pre;
        if(l->full)pre+=r->pre;
        suf=r->suf;
        if(r->full)suf+=l->suf;
        val=max(l->suf+r->pre,max(l->val,r->val));
        full=0;
        if(val==(Y-X+1))full=1;
    }
};
int ret[100005];
Node *R[100005];
Node *build(int l,int r)
{
    Node *now=new Node(0,NULL,NULL);
    if(l==r)
    {
        return now;
    }
    int md=(l+r)/2;
    now->l=build(l,md);
    now->r=build(md+1,r);
    now->compute(l,r);
    return now;
}
Node *upt(Node *now,int l,int r,int pos,int val)
{
    Node *New=new Node(0,now->l,now->r);
    if(l==r)
    {
        New->val=now->val+val;
        New->pre=New->suf=New->val;
        New->full=1;
        return New;
    }
    int md=(l+r)/2;
    if(pos<=md) New->l=upt(now->l,l,md,pos,val);
    else        New->r=upt(now->r,md+1,r,pos,val);
    New->compute(l,r);
    return New;
}
void search(Node *now,int l,int r)
{
    printf("%d %d -> %d %d %d\n",l,r,now->pre,now->suf,now->val);
    if(l==r)return;
    int md=(l+r)/2;
    search(now->l,l,md);
    search(now->r,md+1,r);
}
pair<ii,ii> query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return mkp(mkp(0,0),mkp(0,0));
    if(x<=l && r<=y)
    {
        return mkp(mkp(now->val,now->full? 1:0),mkp(now->pre,now->suf));
    }
    int md=(l+r)/2;
    pair<ii,ii> P1,P2;
    P1=query(now->l,l,md,x,y);
    P2=query(now->r,md+1,r,x,y);
    int p,su,fll,value;
    p=P1.S.F;
    if(P1.F.S)p+=P2.S.F;
    su=P2.S.S;
    if(P2.F.S)su+=P1.S.S;
    value=max(P1.S.S+P2.S.F,max(P1.F.F,P2.F.F));
    fll=0;
    if(value==(r-l+1))fll=1;
    return mkp(mkp(value,fll),mkp(p,su));
}
int cnt=0;
int wasd(int n,int x,int y,int k,int mn,int mx)
{
    int ans=inf;
    while(mn<=mx)
    {
        int md=(mn+mx)/2;
        pair<ii,ii> p;
        p=query(R[md],1,n,x,y);
        int u=max(p.F.F,max(p.S.F,p.S.F));
        if(u>=k)
        {
            ans=min(ans,md);
            mx=md-1;
        }
        else
        {
            mn=md+1;
        }
    }
    return ans;
}
int main()
{
    // OPEN;
    // SEND;
    sint(n);
    vii v;
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        v.pb(mkp(-tmp,i));
    }
    sort(all(v));
    R[0]=build(1,n);
    for(int i=0;i<n;i++)
    {
        cnt++;
        if(i!=0 && v[i].F==v[i-1].F)
        {
            cnt--;
            R[cnt]=upt(R[cnt],1,n,v[i].S,1);
        }
        else
        {
            ret[cnt]=-v[i].F;
            R[cnt]=upt(R[cnt-1],1,n,v[i].S,1);
        }
    }
    /*
    for(int i=0;i<=cnt;i++)
    {
        debug(i);
        debug(ret[i]);
        search(R[i],1,n);
    }
    */
    sint(q);
    while(q--)
    {
        sint3(x,y,k);
        printf("%d\n",ret[wasd(n,x,y,k,1,cnt)]);
    }
}
/*

*/
