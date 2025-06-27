#include <bits/stdc++.h>
using namespace std ;
#define int long long 
signed main(){
    int n , m ; cin >> n >> m ;
    vector<vector<int>> edges(m,vector<int>(3)) ;
    vector<int> distance(n+1,1e18) ;
    vector<int> relaxent(n+1) ;
    for(int i = 0 ; i < m ; i++){
        int u , v , w ; cin >> u >> v >> w ;
        edges[i] = {u,v,w} ;
    }
    
    
    int x ;
    for(int i = 1 ; i <= n ; i++){
        x = -1 ; 
        for(auto edge : edges){
            int u = edge[0] , v = edge[1] , w = edge[2] ;
            
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w ;
                relaxent[v] = u ;
                x = v ;
            }
        }
    }
    
    if(x == -1){
        cout << "NO" ;
    }else{
        
        for(int i = 0 ; i < n ; i++){
            x = relaxent[x] ;
        }
        
        // x is any node in -ve cycle 
        
        vector<int> ans ; 
        ans.push_back(x) ;
        int temp = relaxent[x] ;
        while(temp != x){
            ans.push_back(temp) ;
            temp = relaxent[temp] ;
        }
        ans.push_back(temp) ;
        reverse(ans.begin(),ans.end()) ;
        cout << "YES\n" ;
        for(auto it : ans) cout << it << ' ' ;
    }
    
    
}