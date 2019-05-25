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
char s[1005];
int a[1005][1005];
int main()
{
	sint(n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s+i);
	}
//	printf("%s\n",s);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(s[j]==s[j+i])
			{
				a[j][j+i]=a[j+1][i+j-1]+1;
			}
			else
			{
				int tmp=0;
				for(int k=j;k<i+j;k++)
				{
					if(a[j][k]+a[k+1][i+j]>tmp)
						tmp=a[j][k]+a[k+1][i+j];
				}
				a[j][j+i]=tmp;
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",a[0][n-1]);
}


