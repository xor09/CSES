//Google KickStart -> Round H 2020 
//Question:- Boring Numbers
//Approch:- Digit DP
//link:- https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

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
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5+2;

ll dp[20][2][160][2];
ll solve(vector<int>& arr, int pos, int sum, bool strictly, bool isEven){
   if(pos==(signed)arr.size()) return 1;

   if(dp[pos][strictly][sum][isEven]!=-1) return dp[pos][strictly][sum][isEven];

   ll cur=0;
   if(strictly){
      for(int i=0;i<=arr[pos];++i){
         if(sum==0 and i==0) cur+=solve(arr,pos+1,sum+i,false,false); //leading zero
         else if(!isEven){ //current position is odd
            if(i&1){ //odd
               if(i==arr[pos]) cur+=solve(arr,pos+1,sum+i,true,true);
               else cur+=solve(arr,pos+1,sum+i,false,true);
            }
         }else{ //current position is even
            if(!(i&1)){ //even
               if(i==arr[pos]) cur+=solve(arr,pos+1,sum+i,true,false);
               else cur+=solve(arr,pos+1,sum+i,false,false);
            }
         }
      }
   }else{
      for(int i=0;i<=9;++i){
         if(sum==0 and i==0) cur+=solve(arr,pos+1,sum+i,false,false); //leading zero
         else if(!isEven){ //current position is odd
            if(i&1){ //odd
               cur+=solve(arr,pos+1,sum+i,false,true);
            }
         }else{ //current position is even
            if(!(i&1)){ //even
               cur+=solve(arr,pos+1,sum+i,false,true);
            }
         }
      }
   }
   return dp[pos][strictly][sum][isEven]=cur;
}

int32_t main(){
    fastio;
    ll t=1;
    cin>>t;
    ll case_num=0;
    while(t--){
         case_num++;
         ll a,b;
         cin>>a>>b;
         ll x;

         //for b
         x=b;
         vector<int> B;
         while(x){
            B.push_back(x%10);
            x=x/10;
         }
         reverse(B.begin(), B.end());
         memset(dp,-1,sizeof(dp));
         ll ansB = solve(B,0,0,true,false);

         //for a
         x=a-1;
         vector<int> A;
         while(x){
            A.push_back(x%10);
            x=x/10;
         }
         reverse(A.begin(),A.end());
         memset(dp,-1,sizeof(dp));
         ll ansA = solve(A,0,0,true,false);

         cout << "Case #" << case_num << ": ";
         cout<<ansB-ansA<<endl;
         
   }//while
   return 0;
}