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
vi v; 
bool chk=0;
void find(int msk,int sm)
{
	if(__builtin_popcount(msk)==7)
	{
		if(sm==100)
		{
			for(int i=0;i<9;i++)
			{
				if(msk&(1<<i))
				{
					printf("%d\n",v[i]);
				}
			}
			chk=1;
			return;
		}
		return;
	}
	for(int i=0;i<9;i++)
	{
		if(!(msk&(1<<i)))
		{
			if(chk)	return;
			find(msk|(1<<i),sm+v[i]);
		}
	}
}
int main()
{
	for(int i=0;i<9;i++)
	{
		sint(tmp);
		v.pb(tmp);
	}
	find(0,0);
}

