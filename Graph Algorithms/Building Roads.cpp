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
const int N = 1e5 + 5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char direction[4] = {'D', 'R', 'U', 'L'};
int n , m ;
bool isvalid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int visited[N] ;
vector<int> adj[N];
void dfs(int node){
    visited[node] = 1 ; 
    for(auto &child : adj[node]){
        if(!visited[child]) dfs(child) ;
    }
}
signed main() {
    Yasser();
    cin >> n >> m;

    for(int i = 0 ; i<m ; i++) {
        int u , v ; cin>>u>>v ;
        adj[u].emplace_back(v) ;
        adj[v].emplace_back(u) ;
    }

    //Contains one point of every connected component 
    vector<int> component ;

    for(int i = 1 ; i<=n ; i++) {
        if(!visited[i]) {
            component.push_back(i) ;
            // Reach all your neighbours .
            dfs(i) ;
        }
    }

    cout<<component.size() - 1 << endl;

    for(int i = 1 ; i < component.size() ; i++) cout<<component[i - 1] <<' ' << component[i] << endl;
}
