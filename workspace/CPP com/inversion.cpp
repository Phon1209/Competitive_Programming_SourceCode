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
int n,tmp[100005],a[100005];
long long inv=0;
void mergesort(int st,int ed)
{
	if(st==ed)
		return;
	int md=(st+ed)/2;
	mergesort(st,md);
	mergesort(md+1,ed);
	int i,j,cnt=st;
//	printf("%d %d\n",st,ed);
	for(i=st,j=md+1;i<=md && j<=ed;)
	{
		if(a[i]>a[j])
		{
			tmp[cnt]=a[j];
			j++;
			inv+=(md-i+1);
		}
		else
		{
			tmp[cnt]=a[i];
			i++;
		}
		cnt++;
	}
	for(;i<=md;i++)
	{
		tmp[cnt++]=a[i];
	}
	for(;j<=ed;j++)
	{
		tmp[cnt++]=a[j];
	}
	for(i=st;i<=ed;i++)
	{
		a[i]=tmp[i];
	}
//	printf("%d\n",inv);
//	system("pause");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(0,n-1);
	printf("%lld\n",inv);
}

