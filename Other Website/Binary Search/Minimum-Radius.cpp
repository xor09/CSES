//HackerEarth 
//Question:- Minimun Radius
//Approch:- Binary Search + Basic Circle concept
//link:- https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/minimum-radius-2-29df5cb3/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
const int N = 1e5+2;
//(x-x1)^2 + (y-y1)^2 <= r^2  , then point(x1,y1) lies inside/onEdge of circle with radius(r);
ll helper(ll x[], ll y[], ll p[], ll n, ll r){
   ll sum = 0;
   for(ll i=0; i<n; ++i){
      ll cur = x[i]*x[i];
      cur+=y[i]*y[i];
      if(cur<=(r*r)) sum+=p[i];
   }
   return sum;
}

int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   cin>>t;
   while(t--){
      ll n,q;
      cin>>n>>q;
      ll x[n],y[n],p[n];
      ll l=0,r=1000000000;
      for(ll i=0; i<n; ++i) cin>>x[i];
      for(ll i=0; i<n; ++i) cin>>y[i];
      for(ll i=0; i<n; ++i) cin>>p[i];
         
      ll ans=-1;
      while(l<r){
         ll mid = l + (r-l)/2;
         if(helper(x,y,p,n,mid) < q){
            l=mid+1;
         }else{
            r=mid;
            ans=mid;
         }
      }
      cout<<ans<<endl;
   }//while
   return 0;
}
