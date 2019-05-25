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
#define null NULL
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[200005];
class Node
{
public:
    Node *l,*r;
    int val;
};
class BST
{
public:
    Node *create(int l,int r)
    {
//        printf("A\n");
        int md=(l+r)/2;
        Node *now=null;
        if(l>r)return NULL;
//        printf("%d %d %d\n",l,r,md);
        if(now==NULL)
        {
//            printf("B\n");
            now = new Node();
            now->val=a[md];
            now->l=null;
            now->r=null;
        }
        now->l=create(l,md-1);
        now->r=create(md+1,r);
        return now;
    }
    void search(int v,Node *now)
    {
//        printf("%d\n",now->val);
        while(1)
        {
//            printf("%d\n",now->val);
            if(now->val==v)
            {
                printf("y\n");
                break;
            }
            else if(now->val<v)
            {
                if(now->r==null)
                {
                    printf("n\n");
                    break;
                }
                now=now->r;
            }
            else if(now->val>v)
            {
                if(now->l==null)
                {
                    printf("n\n");
                    break;
                }
                now=now->l;
            }
        }
    }
};
int main()
{
    sint2(n,m);
    BST *tree=new BST();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    Node *rt=tree->create(0,n-1);
//    printf("A\n");
    while(m--)
    {
        sint(tmp);
        tree->search(tmp,rt);
    }
}

/*
5 5
10
2
7
20
25

2
10
13
15
20
*/
