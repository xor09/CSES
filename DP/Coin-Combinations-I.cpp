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
int solve(vector<int> &arr, int n, int target){
   if(target==0) return 1;
   if(target<0) return 0;
   if(dp[target]!=-1) return dp[target];
   int cur=0;
   for(int i=0; i<n ;++i){
      cur = (cur + solve(arr,n,target-arr[i]))%MOD;
   }
   return dp[target] = cur%MOD;
}
 
int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n,x;
      cin>>n>>x;
      vector<int> arr(n);
      for(int i=0;i<n;++i) cin>>arr[i];
      mem(dp,-1);
      int ans = solve(arr,n,x);
      print(ans);
   }//while
   return 0;
}