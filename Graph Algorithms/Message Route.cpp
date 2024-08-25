#include <bits/stdc++.h>
using namespace std ;
void fast(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
}
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
#define INF 1000000000000000000
#define all(s) s.begin(),s.end()
const int N = 2e5+5 ;
//int edges[N][N];
vector<int> visited(N) ;
vector< int> adj[N] ;
int n , m ;
vector<int> dist ;
vector<int> par ;
int main() {
    fast() ;
    cin>>n>>m ;
    for(int i=0 ; i<m ; i++){
        int u , v ;
        cin>>u>>v ;
        adj[u].emplace_back(v) ;
        adj[v].emplace_back(u) ;
    }
    dist.resize(n+1 , 1e9) ;
    //To store parent of every node .
    //par[i] : contains the parent of node (i) .
    par.resize(n+1 , -1) ;
    queue<int> q ;
    q.push(1) ;
    dist[1] = 1;
    while(!q.empty()){
        int cur = q.front() ;
        q.pop() ;
        for(auto &it : adj[cur]){
            if(dist[it] == 1e9){
                dist[it] = dist[cur] + 1 ;
                par[it] = cur ;
                q.push(it) ;
            }
        }
    }
    if(dist[n]!=1e9){
        cout<<dist[n]<<endl;
        vector<int> path ;
        int x = n ;
        while(par[x] !=-1 ){
            path.push_back(x) ;
            x = par[x] ;
        }
        reverse(all(path)) ;
        cout<<1<<' ';
        for(auto &it : path) cout<<it<<' ' ;
    }else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}
