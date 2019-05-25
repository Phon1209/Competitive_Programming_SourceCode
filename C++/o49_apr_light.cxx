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
int cnt=0;
int lenght[600005];
map<int,int> mp;
int n;
struct Node
{
    int len,B,R;
    int isLazy=0;
    Node *l,*r;
    void compute()
    {
        len = l->len + r->len;
        B = l->B + r->B;
        R = l->R + r->R;
    }
    void uplz()
    {
        isLazy^=1;
        swap(R,B);
    }
    void shift()
    {
        if(isLazy)
        {
            l->uplz();
            r->uplz();
            isLazy=0;
        }
    }
    void upt(int nl,int nr,int x,int y)
    {
        if(y<nl || x>nr)return;
        if(x<=nl && nr<=y)
        {
            uplz();
            return;
        }
        shift();
        int md=(nl+nr)/2;
        l->upt(nl,md,x,y);
        r->upt(md+1,nr,x,y);
        compute();
    }
    Node(int x):len(lenght[x]),l(nullptr),r(nullptr){
        B=len;
        R=0;
    }
    Node(Node *l,Node *r):l(l),r(r)
    {
        compute();
    }
    void Debug(int nl,int nr)
    {
        printf("%d %d\n",nl,nr);
        // printf("sum = %lld  len = %lld  lazy = %lld  isLazy = %d\n",sum,len,lazy,isLazy? 1:0);
        if(nl==nr)return;
        int md=(nl+nr)/2;
        l->Debug(nl,md);
        r->Debug(md+1,nr);
    }
};
Node *root;
Node *build(int l,int r)
{
    if(l==r)return new Node(l);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void addpos(int x)
{
    mp[x];
    if(x+1<=n)mp[x+1];
    if(x-1>0) mp[x-1];
}
struct cmd
{
    int x;
    cmd(int x):x(x){
    }
    void execute()
    {
        root->upt(1,cnt,mp[x+1],cnt);
        printf("%d\n",root->B);
    }
};
int main()
{
    int m;
    int2(n,m);
    vector<cmd> com;
    mp[1];
    mp[n];
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        com.pb({tmp});
        addpos(tmp);
    }
    auto it=mp.begin();
    cnt=0;
    while(it!=mp.end())
    {
        mp[it->F]=++cnt;
        int u=it->F;
        it++;
        if(it==mp.end())lenght[cnt]=1;
        else lenght[cnt]=(it->F - u);
    }
    root=build(1,cnt);
    for(int i=0;i<m;i++)
    {
        com[i].execute();
    }
}
/*

*/
