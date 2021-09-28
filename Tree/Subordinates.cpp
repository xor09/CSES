#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e17
#define MOD (int)1e9+7
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;
 
vector<ll> dp;
ll dfs(vector<vector<ll>>& graph, ll cur){
    if(dp[cur]!=-1) return dp[cur];
    ll count=0;
    for(auto &child : graph[cur]){
        count+=1+dfs(graph,child);
    }
    return dp[cur]=count;
}
 
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> graph(n+1);
        dp.resize(n+1,-1);
        for(ll i=2;i<=n;++i){
            ll x;
            cin>>x;
            graph[x].push_back(i);
        }
        dfs(graph,1);
        for(auto i=1;i<=n;++i) printc(dp[i]);
        nextline;
    }
    return 0;
}