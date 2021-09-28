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
vector<bool> sett;
ll dfs(vector<vector<ll>>& graph, ll cur, ll par=-1){
    if(dp[cur]!=-1) return dp[cur];
    ll ans = 0;
    for(auto &child : graph[cur]){
        if(child==par) continue;
        ll exe = dfs(graph,child,cur);
        ll inc = 0;
        if(!sett[cur] and !sett[child]){
            sett[cur] = sett[child] = true; 
            inc = 1+dfs(graph,child,cur);
        }
        ans+=max({exe,inc});
    }
    return dp[cur]=ans;
}
 
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> graph(n);
        dp.resize(n,-1);
        sett.resize(n,false);
        for(ll i=1;i<n;++i){
            ll u,v;
            cin>>u>>v;
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout<<dfs(graph,0);
        nextline;
    }
    return 0;
}