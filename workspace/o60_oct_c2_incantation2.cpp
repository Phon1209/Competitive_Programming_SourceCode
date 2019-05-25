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
ll mx=0;
int n,k;
int sc[500];
int a[500];
int lim;
// /*
void find(int lv,ll score,int bit)
{
    if(lv==n)
    {
        mx=max(score,mx);
        return ;
    }
    bit=bit<<1;
    bit=bit&lim;
    if(sc[bit+1]>sc[bit])
    {
        a[lv]=1;
        find(lv+1,score+sc[bit+1],bit+1);
    }
    else if(sc[bit+1]<sc[bit])
    {
        a[lv]=0;
        find(lv+1,score+sc[bit],bit);
    }
    else
    {
        a[lv]=0;
        find(lv+1,score+sc[bit],bit);
        a[lv]=1;
        find(lv+1,score+sc[bit+1],bit+1);
    }
}
// */
int main()
{
    // /*
    int2(n,k);
    lim=(1<<k)-1;
    for(int i=0;i<(1<<k);i++)
    {
        int1(sc[i]);
    }
    // */
    // /*
    for(int i=0;i<(1<<k);i++)
    {
        int tmp=i;
        for(int j=k-1;j>=0;j--)
        {
            if(tmp%2)a[j]=1;
            else a[j]=0;
            tmp/=2;
        }
        ll ot=sc[i];
        find(k,ot,i);
    }
    // */
    printf("%lld\n",mx);
    // */
}
/*

*/
