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
int T[200005][5];
int main()
{
    sint3(n,t,m);
    int mx=0;
    while(m--)
    {
        sint(x);
        mx=max(mx,x);
        sstring(a,10);
        if(a[0]=='l')
            T[x][0]++;
        if(a[0]=='r')
            T[x][1]++;
    }
    int side=0;
    int other=(1^0);
    int load=0;
    int travel=0;
    queue<int> q[5];
    for(int i=0;i<=200000;i++)
    {
//        printf("%d %d %d\n",side,i,load);
        while(T[i][0]--)
        {
//            printf("A\n");
            q[0].push(1);
        }
        while(T[i][1]--)
        {
//            printf("B\n");
            q[1].push(1);
        }
        if(travel>0)
        {
            travel--;
            if(travel==0)
            {
                side^=other;
            }
            else continue;
        }
        for(int j=load;j>0;j--)
        {
            printf("%d\n",i);
            load--;
        }
        if(q[side].empty() && !q[side^other].empty())
        {
//            printf("C\n");
            travel=t;
        }
        if(!q[side].empty())
        {
//            printf("D\n");
            for(int j=0;j<n && !q[side].empty();j++)
            {
                q[side].pop();
                load++;
            }
        }
        if((q[side].empty() || load==n) && load!=0)
        {
//            printf("E\n");
            travel=t;
        }
//        pause;
    }
}
