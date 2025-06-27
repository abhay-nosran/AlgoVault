#include <bits/stdc++.h>
using namespace std ;
int n ; 
vector<int> graph[200011] ;
int depth[200011] ;
int parent[200011] ;

void dfs(int node , int par){
    parent[node] = par ;
    depth[node] = depth[par]+1;

    for(auto neigh : graph[node]){
        if(neigh != par){
            dfs(neigh,node) ;
        }
    }
}
signed main(){
    cin >> n ;


    for(int i = 1 ; i < n ; i++){
        int u , v ; cin >> u >> v ; 
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    dfs(1,0) ;
    int y = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[i] > depth[y]){
            y = i ;
        }
    }

    dfs(y,0) ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[i] > depth[y]){
            y = i ;
        }
    }

    cout << depth[y]-1 ;
    

}