#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<assert.h>
#include<utility>
using namespace std;
#define mod 1000000007
#define test int t;scanf("%d", &t);while(t--)
#define pb push_back
#define all(x) x.begin(),x.end() 
#define mpr make_pair
#define ll long long int 
#define ull unsigned long long int 
#define db double
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define ub upper_bound
#define lb lower_bound

#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)    
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sc4(w,x,y,z) scanf("%d%d%d%d",&w,&x,&y,&z)

#define scll(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scll4(w,x,y,z) scanf("%lld%lld%lld%lld",&w,&x,&y,&z)

#define scdb(x) scanf("%lf",&x)
#define scdb2(x,y) scanf("%lf%lf",&x,&y)    
#define scdb3(x,y,z) scanf("%lf%lf%lf",&x,&y,&z)
#define scdb4(w,x,y,z) scanf("%lf%lf%lf%lf",&w,&x,&y,&z)

#define scs(s) scanf("%s", s)

#define pr(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pr4(w,x,y,z) printf("%d %d %d %d\n",w,x,y,z)

#define prll(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)
#define prll4(w,x,y,z) printf("%lld %lld %lld %lld\n",w,x,y,z)

#define prdb(x) printf("%lf\n",x)
#define prdb2(x,y) printf("%lf %lf\n",x,y)
#define prdb3(x,y,z) printf("%lf %lf %lf\n",x,y,z)
#define prdb4(w,x,y,z) printf("%lf %lf %lf %lf\n",w,x,y,z)

#define prs(s) printf("%s\n", s)
#define prn() printf("\n")
#define prvec(v) for(int i=0;i<v.size();i++) cout << v[i] << " "
#define prpair(p) cout<<p.first<<" "<<p.second<<endl
#define F first
#define S second

#define maxr 100005
vector<int> a;
int n;
ll ans = 1;
ll fac[maxr];
bool valid()
{
  stack<int> s;
  s.push(n);
  for(int i=0;i<n;i++)
  {
    //if(s.empty()){s.push(i+a[i]+1);continue;}
    int top = s.top();
    if(top==i)s.pop();
    top = s.top();
    if(a[i]+i+1>top)return 0;
    if(a[i]+i+1!=top)s.push(a[i]+1+i);
  }
  return 1;
}
ll power(ll a, ll n)
{
  if(n==1)return a;
  ll ret = power(a,n/2);
  ret = (ret*ret)%mod;
  if(n%2==1)ret = (ret*a)%mod;
  return ret;
}
ll p[maxr];
ll choose(ll n, ll r)
{
  assert(n>=r);
  if(r==0 || n==0)return 1;
  return (fac[n]*((p[r]*p[n-r])%mod))%mod;
}
stack<pair<int,int> > gst;
void solve()
{
  while(!gst.empty())
  {
    pair<int,int> p = gst.top();
    gst.pop();
    int st = p.F, end = p.S;
    if(st>=end)continue;
    int ind = st;
    ll left = end-st+1;
    stack<ll> s;
    while(ind<=end)
    {
      st = ind;
      ind = min(ind+a[ind]+1,end+1);
      ll bet = ind-st-1;
      s.push(bet);
      //ans = (ans*choose(left,bet))%mod;
      //left -= bet;
      gst.push(mpr(st+1,ind-1));
      //solve(st+1,ind-1);
    }
    while(!s.empty())
    {
      left--;
      ans = (ans*choose(left,s.top()))%mod;
      left -= s.top();
      s.pop();
    }
  }
}
int main()
{
  fac[0] = 1;
  p[0] = 1;
  for(int i=1;i<maxr;i++)fac[i] = (fac[i-1]*i)%mod;
  for(int i=1;i<maxr;i++)p[i] = power(fac[i],mod-2);
  test
  {
    ans = 1;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(!valid()){cout<<0<<endl;continue;}
    gst.push(mpr(0,n-1));
    solve();
    cout<<ans<<endl;
  }
  return 0;
}
