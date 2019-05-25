#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n,c,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c);
		v.push_back(c);
	}
	sort(v.begin(),v.end());
	c=v.size();
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<c-1)
		{
			c-=(v[i]+1);
			ans+=v[i];
		}
	}
	if(c>0)
	{
		ans+=(c-1);
	}
	printf("%d\n",ans);
}
