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

int pre[1005];
int post[1005];
int sz;
int idx;
struct Node
{
    int val;
    Node *l,*r;
    Node(int val):val(val){
        l=r=NULL;
    }
};

Node *make(int x,int y)
{
    if(idx>sz || x>y)return NULL;
    Node *New=new Node(pre[idx++]);
    if(x==y)
    {
        return New;
    }
    int i;
    for(i=x;i<=y;i++)
    {
        if(pre[idx]==post[i])
        {
            break;
        }
    }
    if(i<=y)
    {
        New->l=make(x,i);
        New->r=make(i+1,y);
    }
    return New;
}
void inorder(Node *now)
{
    if(now==NULL)return;
    inorder(now->l);
    printf("%d\n",now->val);
    inorder(now->r);
}
int main()
{
    OPEN;
    SEND;
    sint(n);
    for(int i=0;i<n;i++)
    {
        int1(pre[i]);
    }
    for(int i=0;i<n;i++)
    {
        int1(post[i]);
    }
    std::cerr << "Hello World" << '\n';
    idx=0;
    sz=n-1;
    Node *root=make(0,n-1);
    inorder(root);
}
/*
4
1
2
7
8
2
8
7
1
*/
