#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
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

int arr[200005];
int32_t main(){
    fastio;
    ll t=1;
    //cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      arr[0]=0;
      for(int i=1;i<=n;++i){
         cin>>arr[i];
         arr[i]=arr[i]^arr[i-1];
      }
      int l,r;
      while(q--){
          cin>>l>>r;
          int x = arr[r]^arr[l-1];
          print(x);
      }
   }//while
   return 0;
}