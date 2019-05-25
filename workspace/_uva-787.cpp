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
struct bigint{
  static const int LEN = 150;
  static const int BIGMOD = 10000;
  int s;			// sign of big integer
  int vl, v[LEN];	// vl is length of v array
  bigint() : s(1) { vl = 0; }   // eg. bigint x;

  bigint(long long a) {			// eg. bigint x(a);
	s = 1; vl = 0;
	if (a < 0) { s = -1; a = -a; }
	while (a) {
	  push_back(a % BIGMOD);
	  a /= BIGMOD;
	}
  }

  bigint(string str) {			// eg. bigint x(str);
	s = 1; vl = 0;
	int stPos = 0, num = 0;
	if (!str.empty() && str[0] == '-') {
	  stPos = 1;
	  s = -1;
	}
	for (int i=str.length()-1, q=1; i>=stPos; i--) {
	  num += (str[i] - '0') * q;
	  if ((q *= 10) >= BIGMOD) {
		push_back(num);
		num = 0; q = 1;
	  }
	}
	if (num) push_back(num);
  }
  int len() const {
	return vl;
  }

  bool empty() const { return len() == 0; }

  void push_back(int x) {
	v[vl++] = x;
  }

  void pop_back() {
	vl--;
  }

  int back() const {
	return v[vl-1];
  }

  void n() {
	while (!empty() && !back()) pop_back();
  }

  void resize(int nl) {
	vl = nl;
	memset(v,0,sizeof(int)*vl);
  }
  void print() const {
	if (empty()) { putchar('0'); return; }
	if (s == -1) putchar('-');
	printf("%d", back());
	for (int i=len()-2; i>=0; i--) printf("%.4d",v[i]);
  }

  friend std::ostream& operator << (std::ostream& out, const bigint &a) {
	if (a.empty()) { out << "0"; return out; }
	if (a.s == -1) out << "-";
	out << a.back();
	for (int i=a.len()-2; i>=0; i--) {
	  char str[10];
	  snprintf(str, 5, "%.4d", a.v[i]);
	  out << str;
	}
	return out;
  }
  int compare(const bigint &b)const {
	if (s != b.s) return s - b.s;
	if (s == -1) return -(-*this).compare(-b);
	if (len() != b.len()) return len()-b.len();//int
	for (int i=len()-1; i>=0; i--)
	  if (v[i]!=b.v[i]) return v[i]-b.v[i];
	return 0;
  }
  bool operator < (const bigint &b)const{ return compare(b)<0; }
  bool operator <= (const bigint &b)const{ return compare(b)<=0; }
  bool operator == (const bigint &b)const{ return compare(b)==0; }
  bool operator != (const bigint &b)const{ return compare(b)!=0; }
  bool operator > (const bigint &b)const{ return compare(b)>0; }
  bool operator >= (const bigint &b)const{ return compare(b)>=0; }
  bigint operator - () const {
	bigint r = (*this);
	r.s = -r.s;
	return r;
  }
  bigint operator + (const bigint &b) const {
	if (s == -1) return -(-(*this)+(-b));
	if (b.s == -1) return (*this)-(-b);
	bigint r;
	int nl = max(len(), b.len());
	r.resize(nl + 1);
	for (int i=0; i<nl; i++) {
	  if (i < len()) r.v[i] += v[i];
	  if (i < b.len()) r.v[i] += b.v[i];
	  if(r.v[i] >= BIGMOD) {
		r.v[i+1] += r.v[i] / BIGMOD;
		r.v[i] %= BIGMOD;
	  }
	}
	r.n();
	return r;
  }
  bigint operator - (const bigint &b) const {
	if (s == -1) return -(-(*this)-(-b));
	if (b.s == -1) return (*this)+(-b);
	if ((*this) < b) return -(b-(*this));
	bigint r;
	r.resize(len());
	for (int i=0; i<len(); i++) {
	  r.v[i] += v[i];
	  if (i < b.len()) r.v[i] -= b.v[i];
	  if (r.v[i] < 0) {
		r.v[i] += BIGMOD;
		r.v[i+1]--;
	  }
	}
	r.n();
	return r;
  }
  bigint operator * (const bigint &b) {
	bigint r;
	r.resize(len() + b.len() + 1);
	r.s = s * b.s;
	for (int i=0; i<len(); i++) {
	  for (int j=0; j<b.len(); j++) {
		r.v[i+j] += v[i] * b.v[j];
		if(r.v[i+j] >= BIGMOD) {
		  r.v[i+j+1] += r.v[i+j] / BIGMOD;
		  r.v[i+j] %= BIGMOD;
		}
	  }
	}
	r.n();
	return r;
  }
  bigint operator / (const bigint &b) {
	bigint r;
	r.resize(max(1, len()-b.len()+1));
	int oriS = s;
	bigint b2 = b; // b2 = abs(b)
	s = b2.s = r.s = 1;
	for (int i=r.len()-1; i>=0; i--) {
	  int d=0, u=BIGMOD-1;
	  while(d<u) {
		int m = (d+u+1)>>1;
		r.v[i] = m;
		if((r*b2) > (*this)) u = m-1;
		else d = m;
	  }
	  r.v[i] = d;
	}
	s = oriS;
	r.s = s * b.s;
	r.n();
	return r;
  }
  bigint operator % (const bigint &b) {
	return (*this)-(*this)/b*b;
  }
};
bigint a[105];
bigint dp[105][5];
int main()
{
//    freopen("test.txt","w",stdout);
    char s[10];
    while(scanf("%s",s)!=EOF)
    {
        int p=1;
        a[0]=bigint(s);
        while(1)
        {
            sstring(q,10);
            a[p]=bigint(q);
            if(a[p]==-999999)break;
            p++;
        }
        bigint ans=bigint(0);
        bool ok=true;
        for(int i=0;i<p;i++)
        {
//            if(i==0)
            {
                if(a[i]<0)
                {
                    dp[i][0]=0;
                    dp[i][1]=a[i];
                }
                else if(a[i]>0)
                {
                    dp[i][0]=a[i];
                    dp[i][1]=0;
                }
                else
                {
                    dp[i][0]=dp[i][1]=0;
                }
            }
            if(a[i]<0)
            {
                dp[i][0]=max(dp[i-1][1]*a[i],dp[i][0]);
                dp[i][1]=min(dp[i-1][0]*a[i],dp[i][1]);
            }
            else if(a[i]==0)
            {
                ok=false;
                dp[i][0]=0;
                dp[i][1]=0;
            }
            else
            {
                dp[i][0]=max(dp[i-1][0]*a[i],dp[i][0]);
                dp[i][1]=min(dp[i-1][1]*a[i],dp[i][1]);
            }
            ans=max(ans,dp[i][0]);
//            printf("%lld %lld\n",dp[i][0],dp[i][1]);
        }
        if(ok && ans==0)
        {
            ans=-inf;
            for(int i=0;i<p;i++)
            {
                ans=max(ans,a[i]);
            }
        }
        ans.print();
        endl;
//        printf("%lld\n",ans);
    }
}
/*
1 2 3 -999999
-5 -2 2 -30 -999999
-8 -999999
-1 0 -2 -999999
*/
