#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define MOD (int)1e9+7
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;

set<int> mapp;
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        ll n;
        cin>>n;
        ll counter = 0;
        while(n--){
            ll x;
            cin>>x;
            if(mapp.count(x)==0) counter++;
            mapp.insert(x);
        }
        print(counter);
    }
    return 0;
}