#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF LLONG_MAX
 
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
}
 
int main() {
    fast();
    
    int t = 1;
    // cin >> t; 
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
 
        vector<vector<pair<ll, ll>>> adj(n + 1);
        for (ll i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        }
 
        vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
        dp[1][0] = 0; // Starting node with no coupon used
 
        priority_queue<tuple<ll, ll, bool>, vector<tuple<ll, ll, bool>>, greater<tuple<ll, ll, bool>>> pq;
        pq.emplace(0, 1, false);
 
        while (!pq.empty()) {
            ll cost, u;
            bool used_coupon;
            tie(cost, u, used_coupon) = pq.top();
            pq.pop();
 
            if (cost > dp[u][used_coupon]) continue;
 
            for (auto [v, w] : adj[u]) {
                // Without using coupon
                if (cost + w < dp[v][used_coupon]) {
                    dp[v][used_coupon] = cost + w;
                    pq.emplace(dp[v][used_coupon], v, used_coupon);
                }
 
                // With using coupon (only if not used yet)
                if (!used_coupon && cost + (w / 2) < dp[v][1]) {
                    dp[v][1] = cost + (w / 2);
                    pq.emplace(dp[v][1], v, true);
                }
            }
        }
 
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
 
    return 0;
}
