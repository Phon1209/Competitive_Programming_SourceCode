#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
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
struct pnt
{
    double x,y;
    pnt(int x,int y):x(x),y(y){}
    bool operator == (const pnt &a)
    {
        if(x==a.x && y==a.y)return 1;
        return 0;
    }
};
bool cross(pnt o,pnt a,pnt b){ // 0 = turn left 1 = turn right
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x) <= 0.0;
}
double area(pnt a,pnt b,pnt c)
{
    // debug(a.x);
    // debug(a.y);
    // debug(b.x);
    // debug(b.y);
    // debug(c.x);
    // debug(c.y);
    double ret=0;
    ret+=((a.x*b.y)+(b.x*c.y)+(c.x*a.y));
    ret-=((a.y*b.x)+(b.y*c.x)+(c.y*a.x));
    ret=(ret<0)? -ret:ret;
    return ret/2;
}
int main()
{
    sint2(n,m);
    vector<pnt> v,v2,use,use2;
    pnt low={1,1},low2={1,1};
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        v.pb(x,y);
        if(i==0 || y<low.y)low=v[i];
    }
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        v2.pb(x,y);
        if(i==0 || y<low.y)low2=v2[i];
        // W(low2.x);
        // Wl(low2.y);
    }
    vector<pair<double,int> > p,p2;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==low)continue;
        if(v[i].x==low.x)
        {
            if(v[i].y-low.y>=0)p.pb(1.570796,i);
            continue;
        }
        else
        {
            if(v[i].x>low.x)
            {
                p.pb(atan((v[i].y-low.y)/(v[i].x-low.x)),i);
            }
            else
            {
                p.pb(3.141592+atan((v[i].y-low.y)/(v[i].x-low.x)),i);
            }
        }
        // debug(atan((v[i].y-low.y)/(v[i].x-low.x)));
        // p.pb(atan((v[i].y-low.y)/abs(v[i].x-low.x)),i);
    }
    for(int i=0;i<v2.size();i++)
    {
        // debug(i);
        if(v2[i]==low2)continue;
        if(v2[i].x==low2.x)
        {
            if(v2[i].y-low2.y>=0)p2.pb(1.570796,i);
            continue;
        }
        else
        {
            if(v2[i].x>low2.x)
            {
                p2.pb(atan((v2[i].y-low2.y)/(v2[i].x-low2.x)),i);
            }
            else
            {
                p2.pb(3.141592+atan((v2[i].y-low2.y)/(v2[i].x-low2.x)),i);
            }
        }
    }
    // debug(1);
    sort(all(p));
    sort(all(p2));
    use.pb(low);
    use2.pb(low2);
    for(int i=0;i<p.size();i++)
    {
        use.pb(v[p[i].S]);
    }
    for(int i=0;i<p2.size();i++)
    {
        // W(v2[p2[i].S].x);
        // Wl(v2[p2[i].S].y);
        use2.pb(v2[p2[i].S]);
    }
    debug((44));
    vector<pnt> cvx,cvx2;
    for(int i=0;i<use.size();i++)
    {
        while(cvx.size()>=2 && cross(cvx[cvx.size()-2],cvx[cvx.size()-1],use[i]))
        {
            cvx.pop_back();
        }
        cvx.pb(use[i]);
    }
    cvx.pb(low);
    for(int i=0;i<use2.size();i++)
    {
        while(cvx2.size()>=2 && cross(cvx2[cvx2.size()-2],cvx2[cvx2.size()-1],use2[i]))
        {
            cvx2.pop_back();
        }
        cvx2.pb(use2[i]);
    }
    cvx2.pb(low2);

    double expect=0,expect2=0;
    for(int i=0;i<cvx.size()-1;i++)
    {
        // W(cvx[i].x);
        // Wl(cvx[i].y);
        expect+=(cvx[i].x*cvx[i+1].y);
        expect-=(cvx[i].y*cvx[i+1].x);
    }
    expect/=2;
    for(int i=0;i<cvx2.size()-1;i++)
    {
        // W(cvx2[i].x);
        // Wl(cvx2[i].y);
        expect2+=(cvx2[i].x*cvx2[i+1].y);
        expect2-=(cvx2[i].y*cvx2[i+1].x);
    }
    expect2/=2;
    debug(expect);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        double got=0;
        for(int j=0;j<cvx.size()-1;j++)
        {
            debug(area(v2[i],cvx[j],cvx[j+1]));
            got+=area(v2[i],cvx[j],cvx[j+1]);
        }
        debug(got);
        if(got==expect)ans++;
    }
    debug(ans);
    debug(expect2);
    for(int i=0;i<n;i++)
    {
        double got=0;
        for(int j=0;j<cvx2.size()-1;j++)
        {
            debug(area(v[i],cvx2[j],cvx2[j+1]));
            got+=area(v[i],cvx2[j],cvx2[j+1]);
        }
        debug(got);
        if(got==expect2)ans++;
    }
    Wl(ans);
    // debug(ans);
    // Wl(atan(1));
    // Wl(cross({0,0},{1,1},{3,4})? 1:0);
}
/*
4 4
0 1
1 1
0 0
1 0
-1 2
2 2
-1 -1
2 -1


5 5
-3 3
-2 -7
10 -6
4 10
4 -1

3 3
6 3
3 -1
6 -7
4 -10


3 3
0 0
0 2
1 4

1 1
1 3
3 1
*/
