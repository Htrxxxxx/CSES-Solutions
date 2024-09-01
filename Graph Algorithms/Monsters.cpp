#include <bits/stdc++.h>
using namespace std ;
void fast(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
}
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
char di[] = {'D', 'U', 'R', 'L'};
#define INF 1000000000000000000
#define all(s) s.begin(),s.end()
const int N = 2e3+5 ;
//int edges[N][N];
vector<int> visited(N) ;
vector< int> adj[N] ;
int n , m ;
vector<int> dist ;
int parent[N][N];
int main() {
    fast() ;
    cin>>n>>m ;
    vector<vector<char>> grid(n , vector<char> (m)) ;
    queue<pair<int , int>> qm , q ;
    vector<vector<int>> dism(n , vector<int>(m , 1e9)) , dis(n , vector<int>(m , 1e9)) ;
    //vector<int> px(n ,-1) , py(m , -1) ;
    //vector<vector<int>> par(n , vector<int> (m , -1)) ;
    //map<pair<int , int> , int> par ;
    memset(parent ,-1 , sizeof parent) ;
    for(int i=0 ; i<n ; i++) {
        for (int j = 0; j < m; j++) {
             cin>>grid[i][j] ;
             if(grid[i][j]=='A') q.emplace(i , j) ;
             if(grid[i][j]=='M') qm.emplace(i , j) ;
        }
    }
    queue<pair<int , int>> q2 , q3;
    while(!q.empty()){
        int x =q.front().first , y = q.front().second ;
        dis[x][y] = 0 ;
        q2.emplace(x,y) ;
        q.pop() ;
    }
    q = q2 ;
    while(!qm.empty()){
        int x =qm.front().first , y = qm.front().second ;
        dism[x][y] = 0 ;
        q3.emplace(x,y) ;
        qm.pop() ;
    }
    qm = q3 ;
    while(!q.empty()){
        int x =q.front().first ;
        int y =q.front().second ;
        q.pop() ;
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#'){
                if(dis[nx][ny]>dis[x][y]+1){
                    dis[nx][ny]=dis[x][y]+1 ;
                    q.emplace(nx ,ny) ;
                    parent[nx][ny] = i;
                }
            }
        }
    }
    while(!qm.empty()){
        int x =qm.front().first ;
        int y =qm.front().second ;
        qm.pop() ;
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#'){
                if(dism[nx][ny]>dism[x][y]+1){
                    dism[nx][ny]=dism[x][y]+1 ;
                    qm.emplace(nx ,ny) ;
                }
            }
        }
    }
    bool f = false ;
    int xx  , yy ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]!='#'){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(dis[i][j] < dism[i][j]){
                         xx = i , yy = j ;
                        f = true ;
                    }
                }
            }
        }
    }
    if(f){
        cout<<"YES"<<endl;
        vector<char> path ;
        int i = xx , j =yy ;
        if(grid[i][j]=='A'){
            cout<<0<<endl ;
            return  0 ;
        }
        while (true) {
            path.emplace_back(di[parent[i][j]]);
            int x = i;
            i = i - dx[parent[i][j]];
            j = j - dy[parent[x][j]];
            if (parent[i][j] == -1) break;
        }
        reverse(all(path)) ;
        int sz = (int)path.size() ;
        if(path.empty()) cout<<1<<endl ;
        else cout<<sz <<endl;
        for(auto c : path) cout<<c ;
    }
    else {
        cout << "NO" << endl;
    }
 
}
