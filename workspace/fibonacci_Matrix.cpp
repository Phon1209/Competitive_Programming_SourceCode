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
#define inf INT_MAX
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
struct Matrix
{
    int mat[5][5];
};
int getfi(Matrix a,Matrix b)
{
    int ans=0;
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<2;k++)
            {
                ans+=(a.mat[i][k]*b.mat[k][j]);
            }
        }
    }
    return ans;
}
Matrix mul2(Matrix d,Matrix b)
{
  
}
Matrix mul(Matrix d,Matrix b)
{
    Matrix c;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c.mat[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c.mat[i][j]+=(d.mat[i][k]*b.mat[k][j]);
            }
        }
    }
    /*
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",c.mat[i][j]);
        }
        endl;
    }
    endl;
    */
    return c;
}
Matrix powmt(Matrix a,int b)
{
    if(b==1)return a;
    Matrix tmp=powmt(a,b/2);
    tmp=mul(tmp,tmp);
    if(b%2==1) tmp=mul(tmp,a);
    return tmp;
}
int main()
{
    sint(n);
    n--;
    Matrix a,id,fi;
    a.mat[0][0]=1;
    a.mat[0][1]=1;
    a.mat[1][0]=1;
    a.mat[1][1]=0;
    id.mat[0][0]=1;
    id.mat[0][1]=1;
    id.mat[1][0]=1;
    id.mat[1][1]=0;
    fi.mat[0][0]=1;
    fi.mat[1][0]=0;
    /*
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",a.mat[i][j]);
        }
        endl;
    }
    endl;
    */
    if(n>0)
        a=powmt(a,n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",a.mat[i][j]);
        }
        endl;
    }
    printf("%d\n",getfi(a,fi));
}
