//digit DP

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define int long long
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5+2;

//20 = length of the number
//2 = boolean
//10 = previous value [0...9].
//160 = approx. sum of all digit 1e18.
ll dp[20][2][10][160];
ll solve(vector<int> &arr, int pos, bool strictly, int sum, int prev){
   if(pos==(signed)arr.size()) return 1;
   if(dp[pos][strictly][prev][sum]!=-1) return dp[pos][strictly][prev][sum];
   ll cur=0;
   if(strictly){
      for(int i=0;i<=arr[pos];++i){
         if(i==0 and sum==0) cur+=solve(arr,pos+1,false,sum+i,i); //leading zero (allowed)
         else if(prev==i) continue; //continue, if we found adjucent digit (not allowed)
         else if(i==arr[pos]) cur+=solve(arr,pos+1,true,sum+i,i);
         else cur+=solve(arr,pos+1,false,sum+i,i);
      }
   }else{
      for(int i=0;i<=9;++i){
         if(i==0 and sum==0) cur+=solve(arr,pos+1,false,sum+i,i); //leading zero (allowed)
         else if(prev==i) continue; //continue, if we found adjucent digit (not allowed)
         else cur+=solve(arr,pos+1,false,sum+i,i);
      }
   }
   return dp[pos][strictly][prev][sum]=cur;
}

int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
         int a, b;
         cin>>a>>b;

         //0...b
         memset(dp,-1,sizeof(dp));
         int x=b;
         vector<int> B;
         while(x){
            B.push_back(x%10);
            x=x/10;
         }
         reverse(B.begin(), B.end());
         ll total = solve(B,0,true,0,0);

         //0...a-1
         memset(dp,-1,sizeof(dp));
         x=a-1;
         vector<int> A;
         while(x){
            A.push_back(x%10);
            x=x/10;
         }
         reverse(A.begin(), A.end());
         ll diff = solve(A,0,true,0,0);

         //ans(b)-ans(a-1);
         cout<<total-diff<<endl;
   }//while
   return 0;
}