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
int a[100005];
int n,m;
bool chk=false;
void quickselect(int st,int ed)
{
	if(chk)
		return;
	if(st>=ed)
	{
		if(st==m)
		{
			printf("%d\n",a[st]);
		}
		return;
	}
	int k,pivot;
	k=rand()%(ed-st);
	swap(a[st],a[st+k]);
	pivot=a[st];
	int cnt=st+1;
	for(int i=st+1;i<=ed;i++)
	{
		if(a[i]<pivot)
		{
			swap(a[i],a[cnt]);
			cnt++;
		}
	}
	swap(a[cnt-1],a[st]);
	if(cnt-1==m)
	{
		printf("%d\n",a[cnt-1]);
		chk=true;
		return;
	}
	if(cnt-1<m)
	{
//		printf("A\n");
		quickselect(cnt,ed);
	}
	else if(cnt-1>m)
	{
//		printf("B\n");
		quickselect(st,cnt-2);
	}
}
int main()
{
	srand(time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	quickselect(1,n);
}

