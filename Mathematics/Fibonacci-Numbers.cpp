//using matrix-exponential T.C. = O(logN)
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

vector<vector<ll>> matrixMutiplication(vector<vector<ll>> &A,vector<vector<ll>> &B){
   ll n = A.size();
   vector<vector<ll>> C(n,vector<ll>(n,0));
   for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
         for(int k=0;k<n;++k){
            C[i][j]+=(A[i][k]*B[k][j])%MOD;
         }
      }
   }
   return C;
}

vector<vector<ll>> matrixExpo(vector<vector<ll>> &A, ll y){
   if(y==1) return A;
   vector<vector<ll>> resby2 = matrixExpo(A,y/2);
   vector<vector<ll>> res = matrixMutiplication(resby2,resby2);
   if(y&1) return matrixMutiplication(res,A);
   return res;
}

int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
         ll n;
         cin>>n;
         if(n==0) print(0);
         else if(n==1) print(1);
         else{
            vector<vector<ll>> A={{1,1},{1,0}};
            vector<vector<ll>> ans=matrixExpo(A,n);
            print((ans[0][1])%MOD);
         }
         
   }//while
   return 0;
}