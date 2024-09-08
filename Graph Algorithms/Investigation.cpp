    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define ll long long
 
    void fast() {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(0);
    }
    #define endl "\n"
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).begin(), (x).end(), greater<int>()
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    char direction[4] = {'D', 'R', 'U', 'L'};
    const int Mod = 1e9 + 7 ;
    priority_queue <pair<int , int >, vector<pair<int , int>>, greater<pair<int , int>>> gq;
    // gq{c , i} --> Cost of the path till node i .
    signed main() {
        int t = 1 ;
        fast() ;
        //cin>>t ;
        while(t--){
            int n , m ; cin>>n>>m ;
            vector<pair<int , int>> adj[n + 1] ;
 
            for(int i = 0 , u , v  , w; i<m ; i++) {
                cin>>u>>v>>w ;
                adj[u].emplace_back(v , w);
                //adj[v].emplace_back(u , w);
            }
            vector<int> cnt_ways(n + 1) ; // No of ways to reach node [i] .
            vector<int> short_path(n+1 , LLONG_MAX) ; // the shortest path to reach node [i] .
            vector<int> longest_path(n+1) ; // the longest path .................. .
            vector<int> mimumC(n+1 , LLONG_MAX) ;
            gq.emplace(0 , 1) ;
            cnt_ways[1] = 1 ;
            mimumC[1] = 0 ;
            short_path[1] = 0 ;
            longest_path[1] = 0 ;
            while (!gq.empty()) {
                auto [cost , node] = gq.top() ;
                gq.pop() ;
                
                for(auto [child , weight] : adj[node]) {
                    if(mimumC[child] > weight + cost) {
                        mimumC[child] = weight + cost ;
                        gq.emplace(weight + cost , child) ;
                        cnt_ways[child] = cnt_ways[node] ;
                        short_path[child] = short_path[node] + 1  ;
                        longest_path[child] = longest_path[node] + 1 ;
                    }// I care about the child which equal to the shortest distance till now .
                    else if(mimumC[child] == cost + weight){
                        cnt_ways[child] += cnt_ways[node] ;
                        cnt_ways[child] %= Mod ;
                        short_path[child] = min(short_path[node] + 1 , short_path[child]) ;
                        longest_path[child] = max(longest_path[node] + 1 , longest_path[child]) ;
                    }
                }
            }
            cout<<mimumC[n]<<' ' << cnt_ways[n] <<' ' << short_path[n] <<' ' << longest_path[n] ;
        }
}
