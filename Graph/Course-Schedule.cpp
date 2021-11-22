#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll INF = 1e15;
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<vector<int>> course(n);
        vector<int> indegree(n,0);
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            course[u].push_back(v);
            indegree[v]++;
        }
 
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indegree[i]==0) q.push(i);
        }
 
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
 
            for(auto &child : course[cur]){
                if(--indegree[child]==0){
                    q.push(child);
                }
            }
        }
 
        if((unsigned)ans.size()==n){
            for(auto &c : ans) cout<<c+1<<" ";
        }else{
            cout<<"IMPOSSIBLE";
        }
        cout<<endl;
    }
    
    return 0;
}