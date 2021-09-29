/*
    Using prefix sum
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7; 
 
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
       ll n,q;
       cin>>n>>q;
       vector<ll> arr(n+1,0);
       for(ll i=1;i<=n;++i){
        cin>>arr[i];
        //prefix sum store in same array of input
        arr[i]+=arr[i-1];
       }
       ll l,r;
       while(q--){
        cin>>l>>r;
        print(arr[r]-arr[l-1]);
       }
    }
    return 0;
}