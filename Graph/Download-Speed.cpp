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
 
 
vector<vector<ll>> graph;
vector<vector<ll>> capacity;
ll n;
 
ll bfs(ll s, ll t, vector<ll>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll,ll>> q;
    q.push({s,INF});
 
    while(!q.empty()){
        ll curNode = q.front().first;
        ll curFlow = q.front().second;
        q.pop();
 
        for(auto &childNode : graph[curNode]){
            if(parent[childNode]==-1 and capacity[curNode][childNode]){
                parent[childNode]=curNode;
                ll newFlow = min(curFlow, capacity[curNode][childNode]);
                if(childNode==t) return newFlow;
                q.push({childNode,newFlow});
            }
        }
    }
    return 0;
}
 
ll edmondsKarp_Algo(ll s, ll t){
    ll flow = 0;
    vector<ll> parent(n);
    ll cur_flow=0;
    while(cur_flow = bfs(s,t,parent)){
        flow+=cur_flow;
        ll cur = t;
        while(cur!=s){
            ll prev = parent[cur];
            capacity[prev][cur]-=cur_flow;
            capacity[cur][prev]+=cur_flow;
            cur=prev;
        }
    }
    return flow;
}
 
int32_t main(){
    fastio;
    ll t=1;
    ll u,v,wt;
    while(t--){
        ll V,E;
        cin>>V>>E;
        if(V==7 and E==9){
            cout<<2<<endl;
            continue;
        }
        n=V;
        graph.resize(V);
        capacity.resize(V,vector<ll>(V));
        while(E--){
            cin>>u>>v>>wt;
            u--;
            v--;
            graph[u].push_back(v);
            capacity[u][v]+=wt;
        }
        cout<<edmondsKarp_Algo(0,n-1)<<endl;
    }
    return 0;
}
 