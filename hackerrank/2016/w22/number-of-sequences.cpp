#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
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
#define prnp() {cout<<0<<endl;return 0;}
bool prime[maxr], power[maxr];
vector<int> fac[maxr];
int main()
{
  for(int i=2;i<maxr;i++)prime[i] = 1;
  for(int i=2;i<=sqrt(maxr);i++)
  {
    if(!prime[i])continue;
    for(int j=i*2;j<maxr;j+=i)
      prime[j] = 0;
  }
  //for(int i=1;i<maxr;i++)cout<<prime[i]<<endl;
  for(int i=2;i<maxr;i++)
  {
    int k = i*2;
    while(k<maxr)
    {
      fac[k].pb(i);
      k+=i;
    }
  }
  /*for(int i=1;i<maxr;i++)
  {
    for(int j=0;j<fac[i].size();j++)
      cout<<fac[i][j]<<" ";
    cout<<endl;
  }*/
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=n;i>=1;i--)
  {
    if(a[i]==-1)continue;
    for(int j=0;j<fac[i].size();j++)
    {
      int f = fac[i][j];
      if(a[f]==-1)a[f] = a[i]%f;
      else if(a[f]!=a[i]%f)prnp();
    }
  }
  for(int i=2;i<=min(n,1000);i++)
  {
    if(!prime[i])continue;
    int k = i;
    while(k*i<=n)
      k = k*i;
    if(k!=i)
    {
      power[k] = 1;
      prime[i] = 0;
    }
  }
  //for(int i=1;i<=n;i++)cout<<prime[i]<<" "<<power[i]<<endl;
  ll ans = 1;
  for(int i=n;i>=2;i--)
  {
    if(a[i]!=-1)continue;
    if(prime[i])
    {
      ans = (ans*i)%mod;
      continue;
    }
    int valid = 0;
    if(power[i])
    {
      for(int j=0;j<i;j++)
      {
        int flag = 1;
        for(int k=0;k<fac[i].size();k++)
        {
          int f = fac[i][k];
          if(a[f]==-1)continue;
          if(j%f!=a[f]){flag = 0;break;}
        }
        if(flag)valid++;
      }
      ans = (ans*valid)%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}
