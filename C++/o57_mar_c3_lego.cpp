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
    int cnt;
    int val;
    int prior;
    Node *l,*r;
    Node(int val,int prior):
        val(val),prior(prior),l(NULL),r(NULL),cnt(1){}
};
typedef Node* node;
int cnt(node t)
{
    return t? t->cnt:0;
}
void upt_cnt(node t)
{
    t->cnt=1+cnt(t->l)+cnt(t->r);
}
void split(node t,int k,node &l,node &r)
{
    if(!t)
    {
        l=r=NULL;
        return;
    }
    int key=cnt(t->l);
    if(k<=key)split(t->l,k,l,t->l),r=t;
    else split(t->r,k-key-1,t->r,r),l=t;
    upt_cnt(t);
}
void merge(node &t,node l,node r)
{
    if(!l or !r) t=l? l:r;
    else if(l->prior > r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upt_cnt(t);
}
void search(node t,int k)
{
    int key=cnt(t->l);
    if(k==key+1)
    {
        printf("%d\n",t->val);
        return;
    }
    if(k<=key)search(t->l,k);
    else search(t->r,k-key-1);
}
int main()
{
    srand(time(0));
    node T;
    sint2(n,m);
    for(int i=0;i<n;i++){
        sint(tmp);
        node New=new Node(tmp,rand());
        if(i==0)T=New;
        else merge(T,T,New);
    }
    while(m--)
    {
        sint(cmd);
        if(cmd==1)
        {
            sint3(a,l,b);
            node T1,T2,T3,T4;
            if(b<a)
            {
                split(T,a-1,T1,T3);
                split(T1,b-1,T1,T2);
                split(T3,l,T3,T4);
                merge(T1,T1,T3);
                merge(T2,T2,T4);
                merge(T,T1,T2);
            }
            else if(b>a+l-1)
            {
                split(T,a-1,T1,T2);
                split(T2,l,T2,T3);
                split(T3,b-l-a,T3,T4);
                merge(T1,T1,T3);
                merge(T2,T2,T4);
                merge(T,T1,T2);
            }
        }
        else if(cmd==2)
        {
            sint(tmp);
            search(T,tmp);
        }
    }
}
/*
6 6
10
30
40
20
50
30
2 4
1 2 2 6
1 3 3 1
2 4
1 3 3 7
2 5

*/
