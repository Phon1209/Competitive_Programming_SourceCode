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
char a[50];
#define MOD 1000099
char str[1000005];
bool use[1100000];
pair<int,int> H[1100000];
bool chk[1000005];
int h(int cur)
{
	if(cur>MOD) return cur%MOD;
	return cur;
}
void found(int cur,int x)
{
    int pw=1;
    for(;;cur+=(pw/2))
    {
        if(cur>MOD) cur%=MOD;
        if(!use[cur]) break;
        if(H[cur].F == x) chk[H[cur].S]=true;
        pw*=2;
        if(pw >= MOD) pw%=MOD;
    }
}
int main()
{
	sint2(n,m);
	int lim=(1<<m)-1;
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		int x=0;
		for(int j=0;a[j];j++)
		{
			x*=2;
			x+=(a[j]=='1');
		}
		int cur=h(x);
		int pw=1;
		for(;;cur+=(pw/2))
		{
			if(cur>MOD) cur%=MOD;
			if(!use[cur])
			{
				H[cur]=mkp(x,i);
				use[cur]=1;
				break;
			}
			pw*=2;
			if(pw>=MOD)	pw%=MOD;
		}
	}
	sint(p);
	while(p--)
	{
		sint(d);
		scanf("%s",str);
		int x=0;
		memset(chk,0,sizeof chk);
		for(int j=0;j<m-1;j++)
        {
            x*=2;
            x+=(str[j]=='1');
        }
        for(int j=m-1;j<d;j++)
        {
            x*=2;
            x+=(str[j]=='1');
            x&=lim; //mask cap;
            found(h(x),x);
        }
        bool print=false;
        for(int j=0;j<n;j++)
        {
            if(chk[j])
            {
            	printf("%d ",j+1);
            	print=1;
			}
        }
        if(!print) printf("OK");
        printf("\n");
	}
}


