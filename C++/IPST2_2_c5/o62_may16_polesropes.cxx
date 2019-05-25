#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("O3")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
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
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
int tmpsum;
class Segment
{
private:
    struct Node{
        Node *l,*r;
        int val;
        int lz;
        bool islz=false;
        void compute()
        {
            val = l->val + r->val;
        }
        Node(int val):val(val),l(nullptr),r(nullptr){
            islz=false;
        }
        Node(Node *l,Node *r):l(l),r(r){
            compute();
        }
        void uplz(int v)
        {
            val = v;
            islz=true;
            lz=v;
        }
        void shift()
        {
            if(islz)
            {
                if(l)l->uplz(lz);
                if(r)r->uplz(lz);
                islz=false;
            }
        }
    };
    Node *root;
    int left,right;
public:
    Segment(int l,int r){
        left=l;
        right=r;
        root=build2(l,r);
    }
    Node *build2(int l,int r){
        if(l==r)return new Node(10);
        int md=(l+r)/2;
        return new Node(build2(l,md),build2(md+1,r));
    }
    int sum(Node *now,int l,int r,int x,int y){
        if(x>r || y<l)return 0;
        if(x<=l && r<=y)return now->val;
        int md=(l+r)/2;
        now->shift();
        return sum(now->l,l,md,x,y)+sum(now->r,md+1,r,x,y);
    }
    int getsum(int l,int r){
        return sum(root,left,right,l,r);
    }

    int getright(int l,int r,int val){
        int pos=l;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(sum(root,left,right,pos,md)>=val)
            {
                r=md-1;
            }
            else l=md+1;
        }
        return r+1;
    }
    int getleft(int l,int r,int val){
        int pos=r;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(sum(root,left,right,md,pos)>=val)
            {
                l=md+1;
            }
            else r=md-1;
        }
        return l-1;
    }

    int Right(Node *now,int l,int r,int x,int y,int ex){
        // printf("%d %d %d %d %d\n",l,r,x,y,ex);
        if(y<l || x>r)return 0;
        int md=(l+r)/2;
        now->shift();
        if(l==r)
        {
            if(now->val>=ex)throw l;
            else return now->val;
        }
        if(x<=l && r<=y)
        {
            if(now->val>=ex)
            {
                if(now->l->val>=ex)
                {
                    Right(now->l,l,md,x,y,ex);
                }
                else Right(now->r,md+1,r,x,y,ex-now->l->val);
            }
            else
            {
                return now->val;
            }
        }
        int got=0;
        got=Right(now->l,l,md,x,y,ex);
        got+=Right(now->r,md+1,r,x,y,ex-got);
        return got;
    }
    int Left(Node *now,int l,int r,int x,int y,int ex){
        // printf("%d %d %d %d %d\n",l,r,x,y,ex);
        if(y<l || x>r)return 0;
        int md=(l+r)/2;
        // debug(2);
        now->shift();
        // debug(1);
        if(l==r)
        {
            if(now->val>=ex)throw l;
            else return now->val;
        }
        if(x<=l && r<=y)
        {
            if(now->val>=ex)
            {
                if(now->r->val>=ex)
                {
                    Left(now->r,md+1,r,x,y,ex);
                }
                else Left(now->l,l,md,x,y,ex-now->r->val);
            }
            else
            {
                return now->val;
            }
        }
        int got=0;
        got=Left(now->r,md+1,r,x,y,ex);
        got+=Left(now->l,l,md,x,y,ex-got);
        return got;
    }
    void Update(Node *now,int l,int r,int x,int y,int val){
        if(l>r)return;
        int md=(l+r)/2;
        if(y<l || x>r)return ;
        if(x<=l && r<=y)
        {
            now->uplz(val);
            return ;
        }
        now->shift();
        Update(now->l,l,md,x,y,val);
        Update(now->r,md+1,r,x,y,val);
        now->compute();
    }
    void setone(int pos,int val){
        Update(root,left,right,pos,pos,val);
    }
    void setall(int l,int r,int val){
        if(l>r)return;
        Update(root,left,right,l,r,val);
    }
};
int main()
{
    sint2(n,m);
    Segment T(1,n-1);
    /*
    1 = Pull
    2 = Check
    */
    while(m--)
    {
        sint(t);
        if(t==1)
        {
            sint2(pos,val);
            int req=(val/2);
            int u = T.getsum(pos,pos);
            T.setone(pos,u+val);
            int ar,al;
            ar=T.getsum(pos+1,n-1);
            al=T.getsum(1,pos-1);
            if(ar<req)
            {
                T.setall(pos+1,n-1,0);
                int idx=T.getleft(1,pos-1,val-ar);
                int P=T.getsum(idx,pos-1)-(val-ar);
                T.setall(idx+1,pos-1,0);
                T.setone(idx,P);
            }
            else if(al<req)
            {
                T.setall(1,pos-1,0);
                int idx=T.getright(pos+1,n-1,val-al);
                int P=T.getsum(pos+1,idx)-(val-al);
                T.setall(pos+1,idx-1,0);
                T.setone(idx,P);
            }
            else
            {
                int idx=T.getleft(1,pos-1,req);
                int P=T.getsum(idx,pos-1)-req;
                T.setall(idx+1,pos-1,0);
                T.setone(idx,P);

                idx = T.getright(pos+1,n-1,req);
                P = T.getsum(pos+1,idx)-req;
                T.setall(pos+1,idx-1,0);
                T.setone(idx,P);
            }
        }
        if(t==2)
        {
            sint(pos);
            Wl(T.getsum(pos,pos));
        }
        // for(int i=1;i<=n-1;i++)
        // {
        //     W(T.getsum(i,i));
        // }
        // endl;
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
