#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
char c[205][105];
int main()
{
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	sint2(n,m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=n;i<2*n;i++)
	{
		scanf("%s",c[i]);
	}
	bool chk[5],ok=false;
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		ok=true;
		for(int j=0;j<n;j++)
		{
			if(c[j][i]=='A') chk[0]=1;
			if(c[j][i]=='G') chk[1]=1;
			if(c[j][i]=='T') chk[2]=1;
			if(c[j][i]=='C') chk[3]=1;
		}
		for(int j=n;j<2*n;j++)
		{
			if(c[j][i]=='A')if(chk[0])ok=false;
			if(c[j][i]=='G')if(chk[1])ok=false;
			if(c[j][i]=='T')if(chk[2])ok=false;
			if(c[j][i]=='C')if(chk[3])ok=false;
		}
		for(int j=0;j<4;j++)
		{
			chk[j]=0;
		}
		if(ok)
		{
//			printf("A\n");
			cnt++;
		}
//		printf("\n");
	}
	printf("%d\n",cnt);
}

