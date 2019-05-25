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
int s, a, b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}
struct Node
{
    vector<Node*> warp;
    Node *next;
    Node *l,*r;
    int val;
    int ok;
    Node(int val):next(nullptr),ok(0),val(val){}
    Node(int val,Node *l,Node* r):l(l),r(r),ok(2),val(val){}
    Node(int val,Node *next):next(next),ok(1),val(val){}
};
int child[200005][5];
Node *dfs(int u)
{
    #define l child[u][0]
    #define r child[u][1]
    if(l==-1)return new Node(u);
    if(r==-1){return new Node(u,dfs(l));}
    return new Node(u,dfs(l),dfs(r));
    #undef l
    #undef r
}
Node *flag=nullptr;
void find(Node *now)
{
    // debug(now->val);
    // if(flag)printf("flag val = %d\n",flag->val);
    if(flag)flag->warp.pb(now);
    if(now->ok!=1)
        flag=nullptr;
    // debug(1);
    if(now->ok==1 && flag==nullptr)flag=now;
    // debug(2);
    if(now->ok==1)
    {
        find(now->next);
    }
    else
    {
        // debug(3);
        if(now->l)find(now->l);
        if(now->r)find(now->r);
    }
    return;
}
bool suc=0;
void query(Node *now,int len)
{
    if(suc)return;
    if(len==0)
    {
        printf("%d\n",now->val);
        suc=1;
        return;
    }
    if(now->ok==2)
    {
        int dr=dir();
        if(dr==0)query(now->l,len-1);
        if(dr==1)query(now->r,len-1);
    }
    if(now->ok==1)
    {
        int k=now->warp.size();
        if(len<=k)
        {
            query(now->warp[len-1],0);
        }
        else
        {
            query(now->warp[k-1],len-=k);
        }
    }
    if(now->ok==0)
    {
        printf("%d\n",now->val);
        suc=1;
        return;
    }
}
void print(Node *now)
{
    if(now->ok==0)
    {
        printf("val = %d\n",now->val);
        return;
    }
    if(now->ok==1)
    {
        printf("val = %d next = %d\n",now->val,now->next->val);
        print(now->next);
        return;
    }
    if(now->ok==2)
    {
        printf("val = %d l = %d r = %d\n",now->val,now->l->val,now->r->val);
        print(now->l);
        print(now->r);
        return;
    }
}
int main()
{
    sint2(n,q);
    for(int i=0;i<n;i++)
    {
        sint2(l,r);
        if(l==-1)swap(l,r);
        child[i][0]=l;
        child[i][1]=r;
    }
    Node *root=dfs(0);
    // print(root);
    // debug(1);
    find(root);
    while(q--)
    {
        sint(L);
        int3(s,a,b);
        suc=0;
        query(root,L);
    }
}
/*

*/
