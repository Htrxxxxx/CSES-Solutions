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
const int N = 1e3 + 5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char direction[4] = {'D', 'R', 'U', 'L'};
int n , m ;
bool isvalid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
char grid[N][N] ;
int bfs(int si, int sj, int ei, int ej, vector<vector<int>> &distance, vector<vector<pair<int, int>>> &parent) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    distance[si][sj] = 0;
    parent[si][sj] = {-1, -1};  // Parent of the start 
 
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
 
        if (x == ei && y == ej) {
            return distance[ei][ej];
        }
 
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isvalid(nx, ny, n, m) && grid[nx][ny] != '#' && distance[nx][ny] == 1e8) {
                distance[nx][ny] = distance[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return 1e8;
}
 
signed main() {
    Yasser();
    cin >> n >> m;
    // start and end points . 
    int si, sj, ei, ej;
 
    vector<vector<int>> distance(n, vector<int>(m, 1e8));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') si = i, sj = j;
            if (grid[i][j] == 'B') ei = i, ej = j;
        }
    }
 
    int ans = bfs(si, sj, ei, ej, distance, parent);
 
    if (ans < 1e8) {
        cout << "YES" << endl;
        cout << ans << endl;
 
        // Trace the path from end to start
        string path = "";
        int x = ei, y = ej;
 
        while (!(x == si && y == sj)) {
            auto p = parent[x][y];
            // The position i came from .
            int px = p.first, py = p.second;
 
            for (int k = 0; k < 4; k++) {
                if (px + dx[k] == x && py + dy[k] == y) {
                    path += direction[k];
                    break;
                }
            }
            //
            x = px;
            y = py;
        }
 
        reverse(path.begin(), path.end());
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}
