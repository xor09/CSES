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
 
 
int solve(vector<int>&arr, int &n, int &target){
   vector<int> dp(target+1,1e9);
   dp[0]=0;
   for(int i=1;i<=target;++i){
      for(int j=0; j<n; ++j){
         if(i-arr[j]>=0){
            dp[i] = min(dp[i],1+dp[i-arr[j]]);
         }
      }
   }
   return  dp[target] == 1e9 ? -1 : dp[target];
}
 
int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   //cin>>t;
   while(t--){
      int n,target;
      cin>>n>>target;
      vector<int> arr(n);
      for(int i=0;i<n;++i) cin>>arr[i];
      int ans = solve(arr,n,target);
      print(ans);
   
   }//while
   //std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   return 0;
}