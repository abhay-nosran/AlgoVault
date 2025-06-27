#include <bits/stdc++.h>
using namespace std ;
vector<int> graph[200011] ;
int maxDistance[200011] ;
int depth[200011] ;
int parent[200011] ;
int diameter ;

void dfs(int node , int par , int d){
    depth[node] = d ;
    parent[node] = par ; 

    maxDistance[node] = diameter/2 + d ;
    for(auto neigh : graph[node]){

        if(neigh != par){
            dfs(neigh,node,d+1) ;
        }
    }
}


signed main(){
    int n  ; cin >> n ;

    for(int i = 1 ; i < n ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    
    dfs(1,0,0) ;
    int a = 1 ;

    for(int i = 1 ; i <= n ; i++){

        if(depth[a] < depth[i]){
            a = i ;
        }
    }

    dfs(a,0,0) ;

    for(int i = 1 ; i <= n ; i++){

        if(depth[a] < depth[i]){
            a = i ;
        }
    }
    
    diameter = depth[a] ; 

    int numBackSteps = diameter/2 ;
    int center = a ;
    for(int i = 0 ; i < numBackSteps ; i++){
        center = parent[center] ;
    }
    if(diameter%2 == 0){ // one center
        dfs(center,0,0) ;
    }else{// two center
        int center2 = parent[center] ;

        dfs(center,center2,1) ;
        dfs(center2,center,1) ;
    }

    for(int i = 1 ; i <= n ; i++){
        cout << maxDistance[i] << ' ' ;
    }
}