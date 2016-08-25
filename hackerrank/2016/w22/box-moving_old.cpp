#include <iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
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
 
int main()
{
  int n;
  cin>>n;
  vector<int> x(n), y(n);
  ll sx = 0, sy = 0;
  for(int i=0;i<n;i++){cin>>x[i];sx+=x[i];}
  for(int i=0;i<n;i++){cin>>y[i];sy+=y[i];}
  if(sx!=sy){cout<<-1<<endl;return 0;}
  if(n==1){cout<<0<<endl;return 0;}
  sort(all(x));
  sort(all(y));
  ll ans = 0;
  for(int st=0, end=1;st<n;st++)
  {
    end = max(end,st+1);
    if(x[st]<y[st]){cout<<-1<<endl;return 0;}
    if(x[st]==y[st])continue;
    while(end<n)
    {
      if(x[end]>=y[end]){end++;continue;}
      ll amount = min(x[st]-y[st],y[end]-x[end]);
      x[st]-=amount;
      x[end]+=amount;
      ans+=amount;
      if(x[st]==y[st])break;
      end++;
    }
    if(x[st]!=y[st]){cout<<-1<<endl;return 0;}
  }
  cout<<ans<<endl;
  return 0;
}
