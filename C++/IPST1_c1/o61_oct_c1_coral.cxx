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
#define eb emplace_back
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
    bool can=0;
    bool allcan=0;
    Node *l,*r;
    void shift()
    {
        if(!can)return;
        if(l==nullptr)
        {
            allcan=1;
            return;
        }
        if(l->can && !r->can)
        {
            r->can=1;
            r->shift();
            r->compute();
        }
        if(!l->can && r->can)
        {
            l->can=1;
            l->shift();
            l->compute();
        }
    }
    void compute()
    {
        if(!l)return;
        allcan = (l->allcan && r->allcan);
        if(!can)can = l->can && r->can;
    }
    Node():l(nullptr),r(nullptr){}
    Node(Node *l,Node *r):l(l),r(r){}
};
Node *root;
Node *build(int l,int r)
{
    if(l==r)return new Node();
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}

void update(Node* now,int l,int r,int x,int y)
{
    if(now->allcan)return;
    if(y<l || x>r)return;
    // printf("%d %d %d %d\n",l,r,x,y);
    if(l==x && r==y)
    {
        if(l==r)now->allcan=1;
        // debug(2);
        now->can=1;
        // debug(root->can);
        now->shift();
        if(l!=r)now->compute();
        return;
    }
    int md=(l+r)/2;
    update(now->l,l,md,x,y);
    update(now->r,md+1,r,x,y);
    now->shift();
    now->compute();
}
void print(Node *now,int l,int r)
{
    printf("%d %d\n",l,r);
    // printf("%d\n",root->can? 1:0);
    printf("can = %d  allcan = %d\n",now->can? 1:0,now->allcan? 1:0);
    if(l==r)return ;
    int md=(l+r)/2;
    print(now->l,l,md);
    print(now->r,md+1,r);
}
int main()
{
    sint2(n,m);
    n=(1<<n);
    root=build(1,n);
    for(int i=1;i<=m;i++)
    {
        sint2(a,b);
        // debug(b+1);
        // debug(b+(1<<a));
        update(root,1,n,b+1,b+(1<<a));

        // print(root,1,n);
        // pause;
        if(root->allcan)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    vi v;
    while(1)
    {
        v.pb(1);
    }
}
/*1 3
0 0
1 0
0 1

*/
