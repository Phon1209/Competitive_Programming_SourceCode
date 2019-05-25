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
int ans=0;
struct Node
{
    int mx,len,m=0,lazy,en;
    bool isLazy=false;
    Node *l,*r;
    void compute()
    {
        en= l->en + r->en;
        len=l->len + r->len;
        mx = max(l->mx,max(l->en+r->mx,en));
    }
    void pr()
    {
        printf("mx = %d  len = %d  m = %d  en = %d  isLazy = %d\n",mx,len,m,en,isLazy? 1:0);
    }
    Node(int p):l(nullptr),r(nullptr)
    {
        len=p; //BUG?
        mx = m = lazy = en = isLazy = false;
    }
    Node(Node *l,Node *r):l(l),r(r)
    {
        compute();
    }
    void uplz(int v)
    {
        m=v;
        lazy=v;
        en=m*len;
        mx=en;
        isLazy=1;
    }
    void update(int nl,int nr,int x,int y,int nm)
    {
        if(y<nl || x>nr)return;
        if(x<=nl && nr<=y)
        {
            uplz(nm);
            return;
        }
        int md=(nl+nr)/2;
        shift();
        l->update(nl,md,x,y,nm);
        r->update(md+1,nr,x,y,nm);
        compute();
    }
    void shift()
    {
        if(isLazy)
        {
            isLazy=0;
            l->uplz(lazy);
            r->uplz(lazy);
            lazy=0;
        }
    }
    void query(int nl,int nr,int k)
    {
        // printf("do %d %d now ans = %d\n",nl,nr,ans);
        if(nl==nr)
        {
            if(m<=0)ans+=len;
            else ans+=min(len,k/m);
            return;
        }
        int md=(nl+nr)/2;
        shift();
        if(k<l->mx)l->query(nl,md,k);
        else{
            ans+=l->len;
            r->query(md+1,nr,k - l->en);
        }
    }
};
Node *root;
int n;
map<int,int> mp;
int lenght[600005];
int cnt=0;
struct cmd
{
    bool isQuery;
    int x,y,arg;
    cmd(int x,int y,int arg):x(x),y(y),arg(arg){
        isQuery=0;
    }
    cmd(int arg):arg(arg),x(0),y(0){
        isQuery=1;
    }
    void execute()
    {
        if(!isQuery)root->update(1,cnt,mp[x],mp[y],arg);
        else {
            ans=0;
            // debug(arg);
            root->query(1,cnt,arg);
            printf("%d\n",ans);
        }
    }
};
void Debug(Node *now,int l,int r)
{

    printf("%d %d\n",l,r);
    now->pr();
    if(l==r)return;
    int md=(l+r)/2;
    Debug(now->l,l,md);
    Debug(now->r,md+1,r);
}
void addpos(int x)
{
    mp[x];
    if(x+1<=n)
        mp[x+1];
    if(x-1>0)
        mp[x-1];
}
Node *build(int l,int r)
{
    if(l==r)return new Node(lenght[l]);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}

int main()
{
    int1(n);
    int x,y,k;
    char s[5];
    vector<cmd> Com;
    mp[1];
    mp[n];
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='Q')
        {
            int1(k);
            Com.eb(k);
        }
        else if(s[0]=='I')
        {
            int3(x,y,k);
            Com.eb(x,y,k);
            addpos(x);
            addpos(y);
        }
        else break;
    }
    cnt=0;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        mp[it->F]=++cnt;
        int u=it->F;
        it++;
        if(it==mp.end())lenght[cnt]=1;
        else lenght[cnt]=(it->F)-u;
    }
    root=build(1,cnt);
    // Debug(root,1,cnt);
    // pause;
    for(int i=0;i<Com.size();i++)
    {
        Com[i].execute();
        // Debug(root,1,cnt);
        // pause;
    }
}
/*

*/
