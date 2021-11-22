#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl "\n"
using namespace std;
ll INF = 1e15;
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        ll n, m, test;
        cin>>n>>m>>test;
        vector<vector<ll>> dp(n,vector<ll>(n,INF));
        while(m--){
            ll u,v,wt;
            cin>>u>>v>>wt;
            u--;
            v--;
            dp[u][v]=min(dp[u][v], wt);
            dp[v][u]=min(dp[v][u], wt);
        }
 
        for(ll i=0;i<n;++i) dp[i][i]=0;
 
        for(ll bet=0;bet<n;++bet){
            for(ll u=0;u<n;++u){
                for(ll v=0;v<n;++v){
                    dp[u][v]=min(dp[u][v], dp[u][bet]+dp[bet][v]);
                }
            }
        }
 
        while(test--){
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            if(dp[u][v]==INF) cout<<-1<<endl;
            else cout<<abs(dp[u][v])<<endl;
            
        }
    }
    
    return 0;
}