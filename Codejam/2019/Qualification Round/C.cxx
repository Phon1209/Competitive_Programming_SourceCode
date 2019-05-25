#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
struct bigint{
  static const int LEN = 105;
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
bigint biggcd(bigint a,bigint b) //a>=b
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return biggcd(b,a%b);
}
char a[105];
bigint inp[105];
bigint ans[105];
map<bigint,char> mp;
void _main()
{
    mp.clear();
    cstring(n,105);
    sint(l);
    bigint tmp,x,y,g;
    for(int i=1;i<=l;i++)
    {
        scanf("%s",a);
        inp[i]=bigint(a);
    }
    // debug(5);
    for(int i=1;i<=l+1;i++)ans[i]=bigint(0LL);
    // debug(3);
    for(int i=2;i<=l;i++)
    {
        if(inp[i]==inp[i-1])continue;
        g=biggcd(inp[i],inp[i-1]);
        ans[i]=g;
        ans[i-1]=inp[i-1]/g;
        ans[i+1]=inp[i]/g;
        mp[g];
        mp[inp[i-1]/g];
        mp[inp[i]/g];
    }
    // debug(1);
    auto it=mp.begin();
    int cntt=0;
    while(it!=mp.end())
    {
        mp[(*it).F]='A'+(cntt++);
        it++;
    }
    for(int i=2;i<=l;i++)
    {
        if(ans[i]==0) // mean inp[i]==inp[i-1]
        {
            if(ans[i-1]==0 && ans[i+1]==0)continue;
            if(ans[i-1]==0)
            {
                ans[i]=inp[i]/ans[i+1];
            }
            if(ans[i+1]==0)
            {
                ans[i]=inp[i-1]/ans[i-1];
            }
        }
    }
    for(int i=l;i>=2;i--)
    {
        if(ans[i]==0)
        {
            if(ans[i-1]==0 && ans[i+1]==0)continue;
            if(ans[i-1]==0)
            {
                ans[i]=inp[i]/ans[i+1];
            }
            if(ans[i+1]==0)
            {
                ans[i]=inp[i-1]/ans[i-1];
            }
        }
    }
    ans[1]=inp[1]/ans[2];
    ans[l+1]=inp[l]/ans[l];
    for(int i=1;i<=l+1;i++){
        printf("%c",mp[ans[i]]);
    }
    endl;
}
int main()
{
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
