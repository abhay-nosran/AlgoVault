// #include <bits/stdc++.h>
// #define int long long
// using namespace std ;
// int n , m ; 
// vector<vector<int>> graph ;
// vector<vector<int>> parentGraph ;
// vector<int> reachable ;
// vector<int> dp ;
// int mod = 1e9 + 7 ;
// void dfs(int node){
//     reachable[node] = 1 ;

//     for(auto neigh : graph[node]){
//         if(reachable[neigh] == 0){
//             dfs(neigh) ;
//         }
//     }
// }

// int getNumPaths(int node){

//     if(node == 1) return 1 ;

//     if(dp[node] != -1) return dp[node] ;

//     int ans = 0 ;

//     for(auto neigh : parentGraph[node]){
//         if(reachable[neigh]) ans = (ans + getNumPaths(neigh))%mod  ;
//     }

//     return dp[node] = ans ;
// }
// signed main(){
//     cin >> n >> m ;

//     graph.resize(n+1) ;
//     parentGraph.resize(n+1) ;
//     reachable.resize(n+1,0) ;
//     dp.resize(n+1,-1) ; 

//     for(int i = 0 ; i < m ; i++){
//         int u , v ; cin >> u >> v ;
//         graph[u].push_back(v) ;
//         parentGraph[v].push_back(u) ;
//     }

//     dfs(1) ;

//     int ans = getNumPaths(n) ;

//     ans = (ans + mod)%mod ;

//     cout << ans ;
// }tc n + n 

#include <bits/stdc++.h>
#define int long long 
using namespace std ;
int mod = 1e9 + 7 ;
signed main(){
    int n , m ; cin >> n >> m ;

    vector<vector<int>> graph(n+1) ;
    vector<int> inDegree(n+1,0) ;
    vector<int> cnt(n+1,0) ;
    for(int i = 0 ; i < m ; i++){
        int u ,v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        inDegree[v]++ ;
    }
    queue<int> q ;
    for (int i = 2; i <= n ; i++)
    {
        if(inDegree[i] == 0) q.push(i) ;
    }

    while (!q.empty())
    {
        int node = q.front() ;
        q.pop() ;

        for(auto neigh : graph[node]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0 && neigh != 1) q.push(neigh) ;
        }
    }
    
    q.push(1);
    cnt[1] = 1 ;
    while (!q.empty())
    {
        int node = q.front() ;
        q.pop() ;

        for(auto neigh : graph[node]){

            inDegree[neigh]--;
            cnt[neigh] = (cnt[neigh] + cnt[node])%mod ;
            if(inDegree[neigh] == 0) q.push(neigh) ;

        }

    }
    cnt[n] = (cnt[n] + mod)%mod ;
    cout <<  cnt[n];

} 