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
void wl(int x)
{
    printf("%d\n",x);
}
void wl(double x)
{
    printf("%lf\n",x);
}
void wl(string x)
{
    printf("%s\n",x.c_str());
}
void wl(ll x)
{
    printf("%lld\n",x);
}
void w(int x)
{
    printf("%d ",x);
}
void w(double x)
{
    printf("%lf ",x);
}
void w(string x)
{
    printf("%s ",x.c_str());
}
void w(ll x)
{
    printf("%lld ",x);
}
enum Type
{
    normal,del,undel
};
class Node
{
private:

public:
    Node *next,*prev;
    Type type;
    int val;
    Node *getnext()
    {
        return next;
    }
    int getval()
    {
        return val;
    }
    Type gettype()
    {
        return type;
    }
};
class List
{
private:
    Node *start,*end;
public:
    void newlist(int val,Type t)
    {
        Node *now=new Node();
        now->prev=NULL;
        now->next=null;
        now->val=val;
        now->type=t;
        start = now;
        end   = now;
    }
    void push_front(int val,Type t)
    {
        Node *now=new Node();
        start->prev=now;
        now->prev=NULL;
        now->next=start;
        now->val=val;
        now->type=t;
        start=now;
    }
    void push_back(int val,Type t)
    {
        Node *now=new Node();
        end->next=now;
        now->prev=end;
        now->next=null;
        now->val=val;
        now->type=t;
        end=now;
    }
    Node *getstart()
    {
        return start;
    }
    Node *getend()
    {
        return end;
    }
    void merge(Node *stY,Node *endY)
    {
        end->next=stY;
        stY->prev=end;
        end=endY;
    }
    void DEL()
    {
        start=null;
        end=null;
    }
    void print()
    {
        Node *now=start;
        while(now!=null)
        {
            if(now->gettype()==normal)
            {
                printf("%d ",now->val);
            }
            now=now->getnext();
        }
    }
};
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+4,0);
        for(int i=0;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        if(y>x)p[x]=y;
        else p[y]=x;
    }
};
int main()
{
    List *lst=new List[150005];
    sint(n);
    UnionFind uf(n);
    for(int i=1;i<=n;i++)
    {
        lst[i].newlist(i,normal);
    }
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        x=uf.fs(x);
        y=uf.fs(y);
        if(x<y)swap(x,y);
        Node *Y=lst[y].getstart();
        Node *Z=lst[y].getend();
        lst[x].merge(Y,Z);
        lst[y].DEL();
        uf.us(x,y);
    }
    lst[uf.fs(1)].print();
}
/*

*/
