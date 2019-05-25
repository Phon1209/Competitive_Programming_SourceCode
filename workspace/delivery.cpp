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
#define inf 1e9
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
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int lim;
int dist(int i,int j)
{
    if(i<lim != j<lim)return inf;
    if(i>lim)
    {
        i-=lim;
        j-=lim;
    }
    int x,y;
    x=i;
    y=j;
    int d=0;
    while(x!=y)
    {
        if(x>y)x/=2;
        else y/=2;
        d++;
    }
    return d;
}
int to[20];
int ret[15][15];
int main()
{
    sint3(n,l,q);
    lim=(1<<n);
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            ret[i][j]=inf;
        }
    }
    for(int i=0;i<l;i++)
    {
        int2(to[i],to[i+5]);
        ret[i][i+5]=1;
        ret[i+5][i]=1;
        ret[i][i]=0;
        ret[i+5][i+5]=0;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            ret[i][j]=ret[j][i]=dist(to[i],to[j]);
//            printf(">%d %d %d %d\n",to[i],to[j],ret[i][j],ret[j][i]);
        }
    }
    for(int i=5;i<5+l;i++)
    {
        for(int j=5;j<5+l;j++)
        {
            ret[i][j]=ret[j][i]=dist(to[i],to[j]);
//            printf("<%d %d %d %d\n",to[i],to[j],ret[i][j],ret[j][i]);
        }
    }
    for(int k=0;k<5+l;k++)
    {
        for(int i=0;i<5+l;i++)
        {
            for(int j=0;j<5+l;j++)
            {
//                printf(">%d %d %d\n",i,j,k);
//                printf("%d %d %d\n",ret[i][j],ret[i][k],ret[k][j]);
                ret[i][j]=ret[j][i]=min(ret[i][j],ret[i][k]+ret[k][j]);
//                printf("%d %d %d\n",ret[i][j],ret[i][k],ret[k][j]);
//                pause;
            }
        }
    }
//    endl;
/*
    for(int i=0;i<2*l;i++)
    {
        for(int j=0;j<2*l;j++)
        {
            printf("%d %d %d %d\n",to[i],to[j],ret[i][j],ret[j][i]);
        }
    }
    */
    while(q--)
    {
        sint2(x,y);
        int ans=inf;
        if(x<lim == y<lim)
        {
            ans=dist(x,y);
        }
        if(x<lim)
        {
            if(y<lim)
            {
                for(int i=0;i<l;i++)
                {
                    for(int j=0;j<l;j++)
                    {
                        ans=min(ans,dist(x,to[i])+ret[i][j]+dist(to[j],y));
                    }
                }
            }
            else
            {
                for(int i=0;i<l;i++)
                {
                    for(int j=5;j<5+l;j++)
                    {
    //                    printf("%d\n",ans);
    //                    printf("%d %d\n",to[i],to[j]);
    //                    printf("%d %d %d\n",dist(x,to[i]),ret[i][j],dist(to[j],y));
                        ans=min(ans,dist(x,to[i])+ret[i][j]+dist(to[j],y));
                    }
                }
            }
        }
        else
        {
            if(y<lim)
            {
                for(int i=5;i<5+l;i++)
                {
                    for(int j=0;j<l;j++)
                    {
                        ans=min(ans,dist(x,to[i])+ret[i][j]+dist(to[j],y));
                    }
                }
            }
            else
            {
                for(int i=5;i<5+l;i++)
                {
                    for(int j=5;j<5+l;j++)
                    {
                        ans=min(ans,dist(x,to[i])+ret[i][j]+dist(to[j],y));
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*
4 2 3
1 18
15 20
9 6
7 21
15 1
*/
