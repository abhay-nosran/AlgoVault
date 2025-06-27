#include <bits/stdc++.h>
#define int long long 
using namespace std ;

signed main(){
    int n , m ; cin >> n >> m ;
    
    vector<vector<int>> edges; ;
    vector<int> distance(n+1,1e18) ;
    
    for(int i = 0 ; i < m  ; i++){
        int u , v , w ; cin >> u >> v >> w ;
        edges.push_back({u,v,-w}) ;
    }
    
    distance[1] = 0 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int u = edges[j][0] , v = edges[j][1] , w = edges[j][2] ;
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w ;
            }
        }   
    }
    
    int isCycle = 0 ; 
    for(int j = 0 ; j < m ; j++){
            int u = edges[j][0] , v = edges[j][1] , w = edges[j][2] ;
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w ;
                isCycle = 1 ;
            }
    }
    
    if(isCycle){
        cout << -1 << '\n' ;
    }else{
        cout << -1*distance[n] << '\n' ;
    }
}