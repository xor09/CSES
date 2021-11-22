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
using namespace std;
const int N = 1e5+2;
 
int dp[1000005];
int solve(int n){
   if(n==0) return 1;
   if(n<0) return 0;
   if(dp[n]!=-1) return dp[n];
   int count = 0;
   for(int i=1; i<=6 and i<=n; ++i){
      count=(count+solve(n-i))%MOD;
   }
   return dp[n] = count%MOD;
}
 
int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n;
      cin>>n;
      mem(dp,-1);
      int x = solve(n);
      print(x);
   }//while
   return 0;
}