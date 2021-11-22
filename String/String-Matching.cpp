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
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
const int N = 1e5+2;
 
ull binaryExponential(ull x, ull n){
   if(n==0) return 1;
   ull res = binaryExponential(x,n/2)%MOD;
   res = (res*res)%MOD;
   if(n&1) return (res*x)%MOD;
   else return res;
}
 
int hashing(string &s, string &t){
   int tlen = t.size(), slen = s.size();
 
   ull sHash=0, tHash=0, count=0;
   vector<int> ans;
   for(int i=0; i<tlen; ++i){
      char ch = t[i];
      tHash = (tHash*131 + ch)%MOD;
      char ch2 = s[i];
      sHash = (sHash*131 + ch2)%MOD;
   }
   if(sHash == tHash) count++;
 
   for(int j=tlen; j<slen; ++j){
      char ch2 = s[j];
      sHash = (ull)(sHash%MOD - (s[j-tlen]*binaryExponential(131,tlen-1))%MOD + MOD)%MOD;
      sHash = (sHash*131 + ch2)%MOD;
      if(sHash == tHash) count++;
   }
   return count;
}
 
 
 
int32_t main(){
   fastio;
   const clock_t begin_time = clock();
   ll t=1;
   //cin>>t;
   while(t--){
      string s="",t="";
      cin>>s;
      cin>>t;
      int ans = hashing(s,t);
      cout<<ans<<endl;
   }//while
   //timeTaken;
   return 0;
}