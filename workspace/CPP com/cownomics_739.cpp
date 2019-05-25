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
char c[1005][55];
bool ok[200];
int f(char a)
{
	if(a=='A')return 1;
	if(a=='T')return 2;
	if(a=='G')return 3;
	if(a=='C')return 4;
}
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
	int cnt=0;
	for(int i=0;i<m-2;i++)
	{
		for(int j=i+1;j<m-1;j++)
		{
			for(int k=j+1;k<m;k++)
			{
//				printf("%d%d%d\n",i,j,k);
				bool chk=true;
				int tmp=0;
				for(int l=0;l<n;l++)
				{
					tmp=0;
					tmp*=5;
					tmp+=f(c[l][i]);
					tmp*=5;
					tmp+=f(c[l][j]);
					tmp*=5;
					tmp+=f(c[l][k]);
					ok[tmp]=1;
				}
				for(int l=n;l<2*n;l++)
				{
					tmp=0;
					tmp*=5;
					tmp+=f(c[l][i]);
					tmp*=5;
					tmp+=f(c[l][j]);
					tmp*=5;
					tmp+=f(c[l][k]);
					if(ok[tmp])
					{
						chk=false;
						break;
					}
				}
				if(chk)
				{
//					printf("A\n");
					cnt++;
				}
				for(int l=0;l<150;l++)
				{
					ok[l]=0;
				}
			}
		}
	}
	printf("%d\n",cnt);
}

