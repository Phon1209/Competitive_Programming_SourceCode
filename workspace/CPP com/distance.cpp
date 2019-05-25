#include<bits/stdc++.h>
using namespace std;
vector<pair<double,pair<double,double> > > v;
int main()
{
	int n;
	double a,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		v.push_back(make_pair(a,make_pair(b,c)));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		a=v[i].first;
		b=v[i].second.first;
		c=v[i].second.second;
//		printf("%lf %lf %lf\n",a,b,c);
	}
	double min=1000000000,max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;
			}
			a=v[i].first-v[j].first;
			b=v[i].second.first-v[j].second.first;
			c=v[i].second.second-v[j].second.second;
//			printf("%lf %lf %lf\n",a,b,c);
			if(sqrt((a*a)+(b*b)+(c*c))<min)
			{
				min=sqrt((a*a)+(b*b)+(c*c));
//				printf("A %lf\n",min);
			}
			if(sqrt((a*a)+(b*b)+(c*c))>max)
			{
				
				max=sqrt((a*a)+(b*b)+(c*c));
//				printf("B %lf\n",max);
			}
		}
	}
	printf("%.2lf %.2lf\n",min,max);
}
