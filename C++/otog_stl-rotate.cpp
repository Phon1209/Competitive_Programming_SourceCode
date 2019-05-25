#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
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
    int key,prior;
    int cnt=1;
    Node *l,*r;
    Node(){}
    Node(int key,int prior):key(key),prior(prior),cnt(1),l(NULL),r(NULL){}
};
typedef Node * node;
int cnt(node now)
{
    return now? now->cnt:0;
}
void upt_cnt(node t)
{
    if(t)t->cnt=1+cnt(t->l)+cnt(t->r);
}
void split(node t,int k,node &l,node &r)
{
    if(!t)
    {
        l=r=NULL;
        return;
    }
    int key=cnt(t->l);
    if(key<k)split(t->r,k-1-key,t->r,r),l=t;
    else split(t->l,k,l,t->l),r=t;
    upt_cnt(t);
}
void merge(node &t,node l,node r)
{
    if(!l or !r)t= l? l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upt_cnt(t);
}
void chk(node t)
{
    if(!t)return;
    chk(t->l);
    printf("%d ",t->key);
    chk(t->r);
}
void search(node t)
{
    if(!t)return;
    printf("%d %d\n",t->key,t->cnt);
    search(t->l);
    search(t->r);
}
int main()
{
    node T;
    srand(time(0));
    sint(n);
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        Node *New=new Node(tmp,rand());
        if(i==1)T=New;
        else merge(T,T,New);
    }
    sint(m);
    while(m--)
    {
        node T1,T2,T3,T4;
        sint3(a,b,c);
        split(T,a,T1,T2);
        split(T2,b-a,T2,T3);
        split(T3,c-b,T3,T4);
        merge(T,T1,T3);
        merge(T,T,T2);
        merge(T,T,T4);
    }
    chk(T);
    endl;
}
/*

*/
