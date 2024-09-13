// Simple Dijkstra problem .
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
//priority_queue <int, vector<int>, greater<int>> gq;
const int N = 1e5 + 5 ;
vector<int> visited(N) ;
int n , m;
vector<pair<int , int>> adj[N] ;
void Dijkstra (vector<int> &Distace) {
    priority_queue <pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> gq;
    gq.push({0 , 1}) ;
    Distace[1] = 0 ;
    while(!gq.empty()) {
        int curr = gq.top().second ;
        int w = gq.top().first ;
        gq.pop() ;
        // Very important to check if you calculate this node before , in Dense Gragh u may push this node more than once .
        if(visited[curr]) continue ;
        visited[curr] = 1;
        for(auto &it : adj[curr]){
            int u = it.first , cost =  it.second ;
            if(Distace[u] > cost + w) {
                Distace[u] = cost + w ;
                gq.push({Distace[u] , u}) ;
            }else {
                continue ;
            }
        }
    }
}
signed main() {
    Yasser();
    int t = 1 ;
    //cin>>t ;
    while(t--){
        cin>>n>>m; 

        for(int i = 0 , u , v , cost ; i<m ; i++) {
            cin>>u>>v>>cost ;
            adj[u].emplace_back(v , cost) ; 
        }
        
        vector<int> Distace(n+1 , 1e18) ;

        Dijkstra(Distace) ;

        for(int i = 1 ; i<=n ; i++) cout<<Distace[i]<<' ' ;
        
    }
}
