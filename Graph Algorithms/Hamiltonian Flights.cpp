#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Yasser() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
}
 
const int N = 21 ;
const int Mod = 1e9 + 7 ;
vector<int> adj[N] ;
int visited[N] ; 
int dp[N][(1<<N)] ;
// dp[i][mask] -- > current cite and , mask for previos visited city .
int n ;
int calc(int i , int mask) {
    if(i == n-1){
        if(mask == ((1<<n) - 1)) return 1 ; // visited all cities .
        else return 0 ;
    }
 
    int &ret =dp[i][mask] ; 
 
    if(~ret ) return ret ; 
 
    ret = 0 ;
    for(auto &it : adj[i]) {
        if(!((1<<it) & mask)) {
            ret +=  calc(it , ((1<<it) | mask) ) ;
            ret %=Mod ;
        }
    }
    return ret ;
}
signed main() {
    Yasser();
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int  m ; cin>>n >> m ; 
        memset(dp , -1 , sizeof(dp)) ;
        for(int i = 0 ; i<m ; i++) {
            int u , v; cin>>u>>v ;
            u-- , v-- ;
            adj[u].emplace_back(v) ;
        }
        cout<<calc(0 , 1) ;
    }
}
