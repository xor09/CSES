#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF (long long)1e15
#define pb push_back
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
const int N = 1e5+2;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char dz[4] ={'R','D','L','U'};
int prevStep[1001][1001];

struct Node{
   int x, y;
   Node(int u, int v){
      x=u;
      y=v;
   }
};

bool bfs(vector<vector<char>> &grid, pair<int,int>& start, pair<int,int>& end){
   int r = grid.size(), c = grid[0].size();
   int u = start.first, v = start.second;
   Node* e = new Node(u,v);
   prevStep[u][v]=-1;
   queue<Node*> q;
   q.push(e);
   grid[u][v]='#';

   while(!q.empty()){
      auto cur = q.front(); q.pop();
      int x = cur->x;
      int y = cur->y;

      for(int i=0; i<4; ++i){
         int x1 = x+dx[i], y1 = y+dy[i];
         if(x1<0 || x1>=r || y1<0 || y1>=c || grid[x1][y1]=='#') continue;
         grid[x1][y1]='#';
         Node* e1 = new Node(x1,y1);
         prevStep[x1][y1]=i;
         q.push(e1);
         if(x1==end.first && y1==end.second) return true;
      }
   }
   return false;
}

int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   //cin>>t;
   while(t--){
      int r,c;
      cin>>r>>c;
      vector<vector<char>> grid(r,vector<char>(c));
      pair<int,int> start,end;
      for(int i=0; i<r; ++i){
         for(int j=0; j<c; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start={i,j};
            if(grid[i][j]=='B') end={i,j};
         }
      }
      auto n = bfs(grid,start,end);
      if(n==false){
         cout<<"NO"<<endl;
      }else{
         string ans="";
         while(end!=start){
            int idx = prevStep[end.first][end.second];
            ans.push_back(dz[idx]);
            end={(end.first-dx[idx]),(end.second-dy[idx])};
         }
         reverse(ans.begin(),ans.end());
         cout<<"YES"<<endl;
         cout<<ans.size()<<endl;
         cout<<ans<<endl;
      }
   }//while
   //timeTaken;
   return 0;
}
