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
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define null NULL
int s, a, b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}
int id[200005][5];
class Node
{
public:
    Node *left,*right;
    int val;
    int child=0;
    // Node *skip[155];
    vector<Node*> v;
    int mxskip=0;
    bool warp;
};
class Tree
{
private:
    Node *root;
public:
    Node *build(int idx)
    {
        Node *now=new Node();
        now->val=idx;
        if(id[idx][0]!=-1)
        {
            now->left=build(id[idx][0]);
            now->child++;
        }
        else now->left=null;
        if(id[idx][1]!=-1)
        {
            now->right=build(id[idx][1]);
            now->child++;
        }
        else now->right=null;
        return now;
    }
    void create(int idx)
    {
        if(root==null)
        {
            root= new Node();
            root->val=idx;
            if(id[idx][0]!=-1)
            {
                root->left=build(id[idx][0]);
                root->child++;
            }
            else root->left=null;
            if(id[idx][1]!=-1)
            {
                root->right=build(id[idx][1]);
                root->child++;
            }
            else root->right=null;

        }
    }
    void chkwarp(Node *now)
    {
        Node *use=now;
        int cnt=0;
        now->warp=1;
        // printf("%d : ",now->val);
        while(now->child==1)
        {
            if(now->left!=null)
                now=now->left;
            else
                now=now->right;
            cnt++;
            now->warp=1;
//            use->skip[cnt]=now;
            use->v.pb(now);
            // printf("%d -> %d\n",use->val,now->val);
        }
        // printf("%d\n",cnt);
        use->mxskip=cnt;
        return;
    }
    void print()
    {
        preorder(root);
    }
    void preorder(Node *now)
    {
        if(now->warp==0 && now->child==1)
            chkwarp(now);
        if(now->left!=null)
            preorder(now->left);
        if(now->right!=null)
            preorder(now->right);
    }
    void traverse(int lv)
    {
        Node *now;
        now=root;
//        endl;
        while(1)
        {
            // printf(">>%d %d\n",lv,now->val);
            if(lv==0 || now->child==0)
            {
                printf("%d\n",now->val);
                break;
            }
            if(now->mxskip!=0)
            {
            //    printf("A\n");
                if(now->mxskip<=lv)
                {
                    lv-=now->mxskip;
                    // now=now->skip[now->mxskip];
                    now=now->v[now->mxskip-1];
                }
                else
                {
                    // now=now->skip[lv];
                    now=now->v[lv-1];
                    lv=0;
                }
                continue;
            }
            if(now->child==1)
            {
//                printf("A\n");
                if(now->left!=null)
                    now=now->left;
                else
                    now=now->right;
                lv--;
                continue;
            }
            int dr=dir();
            if(dr)
            {
                now=now->right;
            }
            else
            {
                now=now->left;
            }
            lv--;
        }
    }
};
int main()
{
    sint2(n,m);
    Tree *t=new Tree();
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        id[i][0]=x;
        id[i][1]=y;
    }
    t->create(0);
    t->print();
    //*
    while(m--)
    {
        sint(lv);
        int3(s,a,b);
        t->traverse(lv);
    }
    //*/
}
/*
9 5
3 -1
-1 -1
1 8
6 7
-1 -1
-1 -1
5 4
-1 2
-1 -1
2 100 1 1
4 8 10 10
4 8 1 8
10 8 1 8
10 100 10 1

9 10
1 -1
2 -1
3 -1
4 8
5 -1
6 7
-1 -1
-1 -1
-1 -1

*/
