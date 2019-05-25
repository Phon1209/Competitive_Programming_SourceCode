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
int cnt;
int lenght[700005];
map<int,int> mp;
struct Node
{
    int len,lazy=0;
    ll sum=0;
    bool isLazy=0;
    Node *l,*r;
    void compute()
    {
        len = l->len + r->len;
        sum = l->sum + r->sum;
    }
    void uplz(int val)
    {
        isLazy=1;
        lazy=val;
        sum=(ll)(len)*(ll)val;
    }
    void shift()
    {
        if(isLazy)
        {
            l->uplz(lazy);
            r->uplz(lazy);
            lazy=0;
            isLazy=0;
        }
    }
    void upt(int nl,int nr,int x,int y,int val)
    {
        if(y<nl || x>nr)return;
        if(x<=nl && nr<=y)
        {
            uplz(val);
            return;
        }
        shift();
        int md=(nl+nr)/2;
        l->upt(nl,md,x,y,val);
        r->upt(md+1,nr,x,y,val);
        compute();
    }
    ll query(int nl,int nr,int x,int y)
    {
        if(y<nl || x>nr)return 0;
        if(x<=nl && nr<=y)
            return sum;
        shift();
        int md=(nl+nr)/2;
        return l->query(nl,md,x,y)+r->query(md+1,nr,x,y);
    }
    Node(int x):len(lenght[x]),l(nullptr),r(nullptr),sum(0){}
    Node(Node *l,Node *r):l(l),r(r)
    {
        isLazy=0;
        lazy=0;
        compute();
    }
    void Debug(int nl,int nr)
    {
        printf("%d %d\n",nl,nr);
        printf("sum = %lld  len = %d  lazy = %d  isLazy = %d\n",sum,len,lazy,isLazy? 1:0);
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
struct cmd
{
    bool isQuery;
    int x,y;
    ll arg;
    cmd(int x,int y,ll arg):x(x),y(y),arg(arg){
        isQuery=0;
    }
    cmd(int x,int y):x(x),y(y){
        isQuery=1;
    }
    void execute()
    {
        // printf("%d %d %d %s\n",x,y,arg,isQuery? "isQuery":"notQuery");
        if(isQuery){
            ll u=root->query(1,cnt,mp[x],mp[y+1]-1);
            printf("%lld\n",u);
        }
        else
        {
            root->upt(1,cnt,mp[x],mp[y+1]-1,arg);
        }
    }
};
int n;
int main()
{
    vector<cmd> v;
    int m;
    // printf("%d\n",INT_MAX);
    scanf("%d %d",&n,&m);
    n++;
    mp[1];
    mp[n];
    while(m--)
    {
        sint(q);
        if(q==0)
        {
            sint2(x,y);
            slong(k);
            x++;
            mp[x];
            mp[y+1];
            v.pb({x,y,k});
        }
        if(q==1)
        {
            sint2(x,y);
            x++;
            mp[x];
            mp[y+1];
            v.pb({x,y});
        }
    }
    cnt=0;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        mp[it->F]=++cnt;
        // debug(it->F);
        // debug(mp[it->F]);
        int u=it->F;
        it++;
        if(it==mp.end())lenght[cnt]=1;
        else lenght[cnt]=(it->F - u);
        // debug(lenght[cnt]);
    }
    root=build(1,cnt);
    // root->Debug(1,cnt);
    // pause;
    for(int i=0;i<v.size();i++)
    {
        v[i].execute();
        // root->Debug(1,cnt);
        // pause;
    }
}
/*

*/
