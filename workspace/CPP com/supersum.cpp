#include<stdio.h>
long long s[20][20];
long long ss(int,int);
int main()
{
    int a,b;
    while(scanf("%d %d",&b,&a)!=EOF)
    {
        long long ans=ss(b,a);
        printf("%lld\n",ans);                                               
    }
}
long long ss(int b,int a)
{
    long long ans=0;
    if(s[b][a]!=0)
    {
        return s[b][a];
    }
    if(b==0)
    {
		s[b][a]=a;
        return a;
    }
    for(int i=1;i<=a;i++)
    {
        ans+=ss(b-1,i);
    }
    s[b][a]=ans;
    return ans;
}
