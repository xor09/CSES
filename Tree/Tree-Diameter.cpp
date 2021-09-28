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
 
vector<vector<ll>> graph(200005);
vector<ll> f(200005,0);
vector<ll> g(200005,0);
ll maxD = 0;
 
void dfs(ll cur, ll par=-1){
    vector<ll> childlist;
    for(auto &child : graph[cur]){
        if(child!=par){
            dfs(child,cur);
            f[cur]=max({f[cur],1+f[child]});
            childlist.push_back(f[child]);
        }
    }
    maxD = max({maxD,f[cur]});
    sort(childlist.begin(),childlist.end());
    if(childlist.size()>1){
        reverse(childlist.begin(),childlist.end());
        g[cur] = 2+childlist[0]+childlist[1];
        maxD = max({maxD,g[cur]});
    }
    return;
}
 
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        ll V;
        cin>>V;
        for(int i=1;i<V;++i){
            ll u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1);
        print(maxD);
    }
    return 0;
}