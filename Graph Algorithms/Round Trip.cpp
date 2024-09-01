#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Yasser() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end(), greater<int>()
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char direction[4] = {'D', 'R', 'U', 'L'};
const int N = 2e5 + 5 ;
int n , m;
vector<int> Visited(N) ;
vector<vector<int>> adj ;
vector<int> parent ;
// Dfs that returns the  start and the end of the cycle .
pair<int , int> dfs(int node , int paren) {
    Visited[node] = 1 ;
    parent[node] = paren ;
 
    for(auto &child : adj[node]) {
        if(child != paren){
            if(!Visited[child]){
                auto res = dfs(child , node) ;
                if(res.first != -1) return res ;
            }
            else {
                // close the cycle .
                parent[child] = node ;
                return {node , child} ;
            }  
        }
    }
    pair<int , int> p ;
    p.first = -1 , p.second = -1 ;
    return p;
}
signed main() {
    Yasser();
    int t = 1 ;
    //cin>>t ;
    while(t--){
        cin>>n>>m; 
        // assign with Default value ({}) .
        adj.assign(n+1 , {}) ;
        Visited.assign(n+1 , {}) ;
        parent.assign(n+1 , {}) ;
        for(int i = 0 , u , v ; i<m ; i++) {
            cin>>u>>v ;
            adj[u].emplace_back(v) ; 
            adj[v].emplace_back(u) ; 
        }
        pair<int , int> ans ;
        for(int i = 1 ; i<=n ; i++){
            if(!Visited[i]) {
                ans = dfs(i , i) ;
                if(ans.first!=-1) break ;
            }
        }
        //If there is no any cycle .
        if(ans.first == -1){
            cout<<"IMPOSSIBLE" ;
            return 0 ;
        }
 
        vector<int> path ;
        int start = ans.first , end = ans.second ;
        path.push_back(end) ;
        while(start != end){
            path.push_back(start) ;
            start = parent[start] ;
        }
        path.push_back(end) ;
        cout<<path.size() <<endl;
        for(auto &it : path) cout<<it <<' ' ;
        
    }
}
