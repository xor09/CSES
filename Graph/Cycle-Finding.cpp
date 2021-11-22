#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e17
#define MOD (int)1e9+7
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &x : arr) cout<<x+1<<" ";
#define nextline cout<<"\n"
using namespace std;
 
 
 
int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> edges;
        vector<ll> relaxant(n,-1);
        while(m--){
            ll u,v,wt;
            cin>>u>>v>>wt;
            edges.push_back({u-1,v-1,wt});
        }
 
        vector<ll> dis(n,0);
        dis[0]=0;
 
        ll x=-1;
        for(ll k=1;k<=n;k++){
            x=-1;
            for(auto &e : edges){
                ll u=e[0];
                ll v=e[1];
                ll w=e[2];
                if(dis[u]!=INT_MAX and dis[u]+w < dis[v]){
                    dis[v]=dis[u]+w;
                    relaxant[v]=u;
                    x=v;
                }
            }
        }
 
        if(x==-1) print("NO");
        else{
            vector<ll> cycle;
            for(ll i=1; i<=n; ++i){
                x=relaxant[x];
            }
 
            for(ll v=x; ;v=relaxant[v]){
                cycle.push_back(v);
                if(v==x and cycle.size()>1) break;
            }
            reverse(cycle.begin(),cycle.end());
            print("YES");
            foreach(cycle);
        }
        nextline;
    }
    return 0;
}