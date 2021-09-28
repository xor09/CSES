#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl "\n"
using namespace std;


ll INF = 1e15;
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> graph(n);
        int u,v,wt;
        while(m--){
            cin>>u>>v>>wt;
            graph[u-1].push_back({v-1,wt});
        }
 
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        vector<int> dis(n,INF);
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int cur = pq.top().first;
            int curWt = pq.top().second;
            pq.pop();
            if(curWt > dis[cur]) continue;
            for(auto &child : graph[cur]){
                if(curWt+child.second < dis[child.first]){
                    dis[child.first] = curWt+child.second;
                    pq.push({child.first,dis[child.first]});
                }
            }
        }
        for(auto &v : dis) cout<<v<<" ";
        cout<<endl;
    }
    
    return 0;
}