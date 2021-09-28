//recursive + memoization
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long
#define endl "\n"
#define INF (long long)1e15
#define debug(x) cout<<#x<<" "<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &ele : arr) cout<<ele<<" "
#define nextline cout<<"\n"
using namespace std;
const int MOD = 1e9+7; 


char grid[1002][1002];
int dp[1002][1002];
int dfs(int n, int x, int y){
    if(x<0 or x>=n or y<0 or y>=n or grid[x][y]=='*') return 0;
    if(x==n-1 and y==n-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    int down = dfs(n,x+1,y);
    int right = dfs(n,x,y+1);
    return dp[x][y]=(down+right)%MOD;
} 

int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>grid[i][j];
            }
        }
        print(dfs(n,0,0));
    }
    return 0;
}