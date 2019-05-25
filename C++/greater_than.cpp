#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
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
multiset<int>::iterator it;
struct Node
{
    Node *l,*r;
    multiset<int> ms;
    int mn,mx;
    void compute()
    {
        mn=min(l->mn,r->mn);
        mx=max(l->mx,r->mx);
    }
    Node(Node *l,Node *r):l(l),r(r)
    {
        it=l->ms.begin();
        while(it!=l->ms.end())ms.insert((*it)),it++;
        it=r->ms.begin();
        while(it!=r->ms.end())ms.insert((*it)),it++;
        compute();
    }
    Node(int val):mn(val),mx(val)
    {
        ms.insert(val);
        l=NULL;
        r=NULL;
    }
};

Node *build(int l,int r)
{
    if(l==r)return new Node(a[l]);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
int tmp;
void upt(Node *now,int l,int r,int pos,int val)
{
    now->ms.insert(val);
    if(l==r)
    {
        tmp=now->mn;
        now->mn=val;
        now->mx=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)upt(now->l,l,md,pos,val);
    else       upt(now->r,md+1,r,pos,val);
    now->compute();
    it=now->ms.lower_bound(tmp);
    now->ms.erase(it);
}
int query(Node *now,int l,int r,int x,int y,int k)
{
    if(now->mx<=k)return inf;
    if(y<l || x>r)return inf;
    int md=(l+r)/2;
    if(x<=l && r<=y)
    {
        if(now->mn>k)return now->mn;
        else
        {
            it=now->ms.upper_bound(k);
            return (*it);
        }
    }
    return min(query(now->l,l,md,x,y,k),query(now->r,md+1,r,x,y,k));
}
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    Node *root=build(1,n);
    while(m--)
    {
        cstring(cmd,5);
        if(cmd[0]=='c')
        {
            sint2(pos,val);
            upt(root,1,n,pos,val);
        }
        if(cmd[0]=='q')
        {
            sint3(x,y,k);
            int ans=query(root,1,n,x,y,k);
            if(ans==inf)printf("no\n");
            else printf("%d\n",ans);
        }
    }
}
/*

*/
