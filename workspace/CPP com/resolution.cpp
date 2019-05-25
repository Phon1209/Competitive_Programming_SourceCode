#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define d second
using namespace std;
vector<pair<pair<int,int>,int> > v;
void gen(int,int,int,int);
int GS,GA,GI,n;
bool chk=false;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&GS,&GA,&GI);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int S,A,I;
			scanf("%d %d %d",&S,&A,&I);
			v.push_back(mp(mp(S,A),I));
		}
		chk=false;
//		printf("A\n");
		gen(0,0,0,0);
//		printf("B\n");
		if(chk)
			printf("yes\n");
		else
			printf("no\n");
			
		v.clear();
	}
}

void gen(int s,int a,int i,int lv)
{
//	printf("C %d %d %d %d\n",s,a,i,lv);
	if(s==GS && a==GA && i==GI)
	{
		chk=true;
	}
	if(lv==n)
		return;
	if(chk)
		return;
	gen(s+v[lv].f.f,a+v[lv].f.d,i+v[lv].d,lv+1);
	gen(s,a,i,lv+1);
}
