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
const int N = 1e5 ;
const int inf = 1e18  ;
signed main() {
    int t = 1 ;
    fast() ;
    int n , m , k;  cin>>n>>m>>k ;
    vector<vector<pair<int , int>>> adj(n+1) ;

    for(int i = 0 , u , v , c ; i < m ; i++) {
        cin>>u>>v>>c ;
        adj[u].emplace_back(v , c) ;
    }
    priority_queue<pair<int , int > , vector<pair<int , int>> , greater<pair<int , int >>> pq ;
    pq.emplace(0 , 1) ; // Cost Till the current node .
    vector<vector<int>> Distance(n + 1 , vector<int>(k , inf)) ; // Distance[node][i] --> stores the kth best distance for node i .
    while (!pq.empty()) {
        auto[cost , curr] = pq.top() ;
        pq.pop() ;

        if(Distance[curr][k - 1] < cost ) continue;

        for(auto[nxt , w] : adj[curr]) {
            int total = w + cost ;
            if(Distance[nxt][k - 1] > total) {
                pq.emplace(total , nxt) ;
                Distance[nxt][k - 1] = total ;
                sort(all(Distance[nxt])) ;
            }
        }
    }

    for(int i = 0 ; i<k ; i++) cout<<Distance[n][i] <<' ' ;

}
