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


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool isvalid(vector<vector<char>>& matrix, int x, int y){
    if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size()) return false;
    if(matrix[x][y]=='#') return false;
    return true;
}
void dfs(vector<vector<char>>& matrix, int x, int y){
    matrix[x][y] = '#';
    for(int i=0;i<4;++i){
        if(isvalid(matrix, x+dx[i], y+dy[i])){
            dfs(matrix,x+dx[i],y+dy[i]);
        }
    }
    return;
}

int32_t main(){
    fastio;
    ll t=1;
    while(t--){
        int row,col;
        cin>>row>>col;
        vector<vector<char>> matrix(row,vector<char>(col));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                cin>>matrix[i][j];
            }
        }
     
        int count=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(matrix[i][j]=='.'){
                    ++count;
                    dfs(matrix,i,j);
                }
            }
        }
        print(count);
    }
    return 0;
}

