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
vii v[100005];
struct Node
{
    ll hsh;
    int val=0;
    Node *l,*r;
    Node(int val,Node *l,Node *r):
        val(val),l(l),r(r){}
    void compute(int x,int y)
    {
        int md=(x+y)/2;
        hsh=(l->hsh*(y-md))+r->hsh;
        val=l->val+r->val;
    }
    bool operator()  (const Node* a,const Node* b)
    {
        while(1)
        {
            if(b->l==NULL && b->r==NULL)
            {
                // printf("%d %d\n",a->val,b->val);
                return a->val>b->val;
            }
            if((a->l->hsh)==b->l->hsh)
            {
                // debug((a? a->l->hsh:l->hsh));
                // debug(b->l->hsh);
                a=a->r;
                b=b->r;
            }
            else
            {
                a=a->l;
                b=b->l;
            }
        }
    }
};
priority_queue<Node*> pq;
Node *build(int l,int r)
{
    if(l==r)
    {
        return new Node(0,NULL,NULL);
    }
    int md=(l+r)/2;
    return new Node(0,build(l,md),build(md+1,r));
}
bool ok=true;
Node *upt(Node *now,int l,int r,int pos)
{
    Node *New=new Node(now->val,now->l,now->r);
    if(l==r)
    {
        New->val=1;
        return New;
    }
    int md=(l+r)/2;
    if(pos<=md)New->l=upt(now->l,l,md,pos);
    else New->r=upt(now->r,md+1,r,pos);
    New->compute(l,r);
    return New;
}
Node *clr(Node *now,int l,int r,int pos)
{
    if(l>pos || !ok)return now;
    Node *New=new Node(now->val,now->l,now->r);
    if(l==r)
    {
        if(New->val==0)ok=false;
        New->val=0;
        return New;
    }
    int md=(l+r)/2;
    New->r=clr(now->r,md+1,r,pos);
    New->l=clr(now->l,l,md,pos);
    New->compute(l,r);
    return New;
}
void print(Node *now,int l,int r)
{
    printf("%d %d %d\n",l,r,now->val);
    if(l==r)
    {
        return;
    }
    int md=(l+r)/2;
    print(now->l,l,md);
    print(now->r,md+1,r);
}
int main()
{
    Node *r=build(1,10);
    Node *t=upt(r,1,10,5);
    pq.push(r);
    pq.push(t);
    t=upt(t,1,10,7);
    pq.push(t);
    debug((r<t));
    while(!pq.empty())
    {
        t=pq.top();
    pq.pop();
    print(t,1,10);
    endl;
    }
    sint2(n,m);
    while(m--)
    {
        sint3(x,y,w);
        v[x].pb(mkp(y,w));
        v[y].pb(mkp(x,w));
    }
    // sint2(s,t);
}
/*

*/
