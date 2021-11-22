#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
using namespace std;
const int N = 1e5+2;
 
// find LCA in log(N) time
vector<int> tree[200001];
int up[200001][20];
void binaryLifting(int src, int par){
   up[src][0] = par;
   for(int i=1;i<20;++i){
      if(up[src][i-1]!=-1) up[src][i] = up[up[src][i-1]][i-1];
      else up[src][i]=-1;
   }
 
   for(auto &child : tree[src]){
      if(child!=par) binaryLifting(child,src);
   }
}
 
int query(int node, int jump_required){
   if(node==-1 or jump_required==0) return node;
   for(int i=19; i>=0; --i){
      if(jump_required&(1<<i)) return query(up[node][i], jump_required-(1<<i));
   }
   return -1;
}
 
int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   //cin>>t;
   while(t--){
      int n,q,par,x,k;
      cin>>n>>q;
      for(int i=2;i<=n;++i){
         cin>>par;
         tree[par].push_back(i);
      }
 
      binaryLifting(1,-1);
 
      while(q--){
         cin>>x>>k;
         int ans = query(x,k);
         print(ans);
      }
   
   }//while
   //std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   return 0;
}