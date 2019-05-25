#include<bits/stdc++.h>
using namespace std;
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
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
string cm;
int cnt=0;
class Node
{
    int val;
public:
    Node *left,*right;
    void setval(int n)
    {
        val=n;
    }
    void pt()
    {
        printf("%d\n",val);
    }
    Node *newl()
    {
        return left=new Node();
    }
    Node *newr()
    {
        return right=new Node();
    }
    Node *getl()
    {
        if(left==NULL)newl();
        return left;
    }
    Node *getr()
    {
        if(right==NULL)newr();
        return right;
    }
};
class tree
{
private:
    Node *root;
public:
    void in(int i)
    {
        if(root==NULL)
        {
            root=new Node();
            return;
        }
        Node *now=root;
        while(1)
        {
            if(cm[i]=='L')now=now->getl();
            else if(cm[i]=='R')now=now->getr();
            else if(cm[i]=='*')break;
            i++;
        }
    }
    void find()
    {
        Node *now=root;
        go(now);
    }
    void go(Node *now)
    {
        if(now->left!=NULL)go(now->left);
        now->setval(++cnt);
        if(now->right!=NULL)go(now->right);
    }
    void print(int i)
    {
        Node *now=root;
        while(1)
        {
            if(cm[i]=='L')now=now->getl();
            else if(cm[i]=='R')now=now->getr();
            else if(cm[i]=='*')
            {
                now->pt();
                break;
            }
            i++;
        }
    }
};
vector<string> v;
int main()
{
    tree *t= new tree();
    sint(n);
    for(int i=0;i<n;i++)
    {
        sstring(a,100005);
        cm=a;
        v.pb(cm);
        t->in(0);
    }
    t->find();
    for(int i=0;i<n;i++)
    {
        cm=v[i];
        t->print(0);
    }
}
