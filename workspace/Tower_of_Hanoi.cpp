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
int moves=0;
///          want to move  tmp  want to go
void Hanoi(int m, char a, char b, char c){
  moves++;
 // printf("%d %c %c %c\n",m,a,b,c);
  if(m == 1)
  {
    printf("Moves disc %d from %c to %c\n",m,a,c);
  }
  else
  {
    Hanoi(m-1,a,c,b);
    printf("Moves disc %d from %c to %c\n",m,a,c);
    Hanoi(m-1,b,a,c);
  }
}
int main()
{
    sint(n);
    Hanoi(n,'A','B','C');
    printf("Moves = %d\n",moves);
}
