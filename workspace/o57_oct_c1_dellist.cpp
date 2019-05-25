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
//        printf("%d>>%d\n",val,now->prev->val);
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
        unordered_map<int,int> mp;
        Node *now=start;
        while(now!=null)
        {
            if(now->gettype()==del)
            {
                int v=now->val;
                mp[v]++;
            }
            else if(now->gettype()==undel)
            {
                int v=now->val;
                mp[v]--;
            }
            else if(now->gettype()==normal)
            {
                int v=now->val;
                if(mp[v]==0)
                {
                    printf("%d\n",v);
                }
            }
            now=now->getnext();
        }
    }
};
int main()
{
    List *list=new List[100005];
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        for(int j=0;j<tmp;j++)
        {
            sint(val);
            if(j==0)
            {
                list[i].newlist(val,normal);
            }
            else
            {
                list[i].push_back(val,normal);
            }
        }
        /*
        endl;
        list[i].print();
        endl;
        */
    }
    while(m--)
    {
        sint(cm);
        if(cm==1)
        {
            sint2(rw,val);
            list[rw].push_front(val,del);
            list[rw].push_back(val,undel);
        }
        else if(cm==2)
        {
            sint2(x,y);
            Node *Y=list[y].getstart();
            Node *Z=list[y].getend();
            list[x].merge(Y,Z);
            list[y].DEL();
        }
    }
    for(int i=1;i<=n;i++)
    {
        list[i].print();
    }
}
/*

*/
