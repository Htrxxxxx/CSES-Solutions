// This problems needs to count the number of connected component .
#include<bits/stdc++.h>
using namespace std;
#define tc int t; cin >> t; while(t--)
#define endl "\n"
#define ll long long
#define ld long double
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end(), greater<int>()
void fast(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

const int N = 1e6+5 ;

int n ,m , k ;
vector<vector<char>> arr ;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool isvalid (int x , int y){
    if(x>=0 && x<n && y>=0 && y<m){
        return true ;
    }
    return false ;
}
vector<vector<int>> visited ;
void dfs(int i , int j ){
    visited[i][j]= 1 ;
    for(int o=0 ; o<4 ; o++){
        int nx = i + dx[o] , ny = j + dy[o] ;
        if(isvalid(nx , ny) && !visited[nx][ny] && arr[nx][ny]=='.'){
            dfs(nx , ny) ;
        }
    }
}
 
signed main(){
 
    cin>>n>>m ;
    arr.resize(n , vector<char>(m)) ;
    visited.resize(n , vector<int> (m)) ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>arr[i][j] ;
        }
    }
    int ans = 0 ;
   for(int i=0 ; i<n ; i++){
       for(int j=0 ; j<m ; j++){
           if(arr[i][j]=='.' && !visited[i][j]){
               ans++ ;
               dfs(i , j ) ;
           }
       }
   }
cout<<ans<<endl;

}
