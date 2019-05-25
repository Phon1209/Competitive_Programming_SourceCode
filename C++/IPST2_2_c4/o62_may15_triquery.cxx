#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
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
int a[2005][2005];
int qs2d[2005][2005];
int qstrir[2005][2005];
ll square(int x,int y,int a,int b)
{
    return qs2d[a][b]-qs2d[x-1][b]-qs2d[a][y-1]+qs2d[x-1][y-1];
}
int fw[2005][2005];
void add(int id,int idx,int val)
{
    while(idx<=500)
    {
        fw[id][idx]+=val;
        idx+=(idx&-idx);
    }
}
int sum(int id,int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[id][idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    // if (not true and false or not false xor true)debug(1);
    sint2(n,m);
    bool done=0;
    memset(a,0,sizeof(a));
    if(n<=500)
    {
        while(m--)
        {
            sint(T);
            if(T==1) //query
            {
                sint3(x,y,l);
                int ans=0;
                for(int i=0;i<l;i++)
                {
                    ans-=(a[x-i][y-l+i+1]/2);
                    ans+=(sum(x-i,y)-sum(x-i,y-l+i));
                    // debug(sum(x-i,y)-sum(x-i,y-l+i));
                    //
                    // debug(ans);
                }
                Wl(ans);
            }
            if(T==2) //edit
            {
                sint3(x,y,val);
                add(x,y,val-a[x][y]);
                a[x][y]=val;
            }
            // for(int i=1;i<=n;i++)
            // {
            //     for(int j=1;j<=n;j++)
            //     {
            //         printf("%d ",sum(i,j));
            //     }
            //     endl;
            // }
            // endl;
        }
        return 0;
    }
    while(m--)
    {
        sint(T);
        if(T==1) //query
        {
            sint3(x,y,l);
            if(!done)
            {
                // for(int i=1;i<=n;i++)
                // {
                //     for(int j=1;j<=n;j++)
                //     {
                //         printf("%d ",a[i][j]);
                //     }
                //     endl;
                // }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        qs2d[i][j]=a[i][j]+qs2d[i-1][j]+qs2d[i][j-1]-qs2d[i-1][j-1];
                    }
                }
                // endl;
                // for(int i=1;i<=n;i++)
                // {
                //     for(int j=1;j<=n;j++)
                //     {
                //         printf("%d ",qs2d[i][j]);
                //     }
                //     endl;
                // }
                for(int i=1;i<=n;i++)
                {
                    for(int j=n;j>=1;j--)
                    {
                        qstrir[i][j]=a[i][j]+qstrir[i-1][j+1]+square(i,j+1,i,n);
                    }
                }
                // endl;
                // for(int i=1;i<=n;i++)
                // {
                //     for(int j=1;j<=n;j++)
                //     {
                //         printf("%d ",qstrir[i][j]);
                //     }
                //     endl;
                // }
                done=1;
            }
            int ans=0;
            ans=qstrir[x][y-l+1]-qstrir[x-l][y+1]-square(x-l+1,y+1,x,n);
            // debug(qstrir[x][y-l+1]);
            // debug(qstrir[x-l][y+1]);
            // debug(square(x-l+1,y+1,x,n));
            // debug(ans);
            for(int i=0;i<l;i++)
            {
                ans-=(a[x-i][y-l+i+1]/2);
                // debug(a[x-i][y-l+i+1]);
            }
            Wl(ans);
        }
        if(T==2) //edit
        {
            sint3(x,y,val);
            a[x][y]=val;
        }
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
