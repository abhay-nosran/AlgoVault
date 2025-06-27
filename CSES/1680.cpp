// #include <bits/stdc++.h>
// using namespace std ;

// signed main(){
//     int n, m ; cin >> n >> m ;
//     std::vector<vector<int>> graph(n+1);
//     vector<int> visited(n+1) ;
//     vector<int> parent(n+1) ;
//     vector<int> distance(n+1,1e9) ;
    
//     for(int i = 0 ; i < m ; i++){
//         int u , v ; cin >> u >> v ;
//         graph[u].push_back(v) ;
//     }
    
//     distance[1] = 0 ;
//     parent[1] = 0 ;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
//     pq.push({0,1}) ;
    
//     while(!pq.empty()){
        
//         auto state = pq.top() ;
//         pq.pop() ;
//         int node = state.second ;
//         int previousDistance = state.first ;
        
//         if(visited[node] == 1) continue ;
//         visited[node] = 1 ;
        
//         for(auto neigh : graph[node]){
//             if(distance[neigh] > previousDistance - 1){
//                 distance[neigh] = previousDistance - 1 ;
//                 parent[neigh] = node ;
//                 pq.push({distance[neigh],neigh}) ;
//             }
//         }
//     }
        
//     if(distance[n] == 1e9){
//         cout << "IMPOSSIBLE" ;
//     }else{
//         // cout << -1*distance[n] + 1 << '\n' ;
//         int temp = n ;
//         vector<int> ans ; 
//         while(temp != 0){
//             ans.push_back(temp) ;
//             temp = parent[temp] ;
//         }
//         cout << ans.size() << '\n' ;
//         reverse(ans.begin(),ans.end());
//         for(auto it : ans ) cout << it << ' ' ;
//     }
// }


// #include <bits/stdc++.h>
// using namespace std ;

// signed main(){
//     int n, m ; cin >> n >> m ;
//     vector<int> parent(n+1) ;
//     vector<int> distance(n+1,1e9) ;
//     vector<pair<int,int>> edges(m) ;
    
//     for(int i = 0 ; i < m ; i++){
//         int u , v ; cin >> u >> v ;
//         edges[i] = {u,v} ;
//     }
    
//     distance[1] = 0 ;
//     for(int i = 1 ; i < n ; i++){
        
//         for(auto edge : edges){
//             int u = edge.first , v = edge.second , w = -1 ;
            
//             if(distance[v] > distance[u] + w){
//                 distance[v] = distance[u] + w ;
//                 parent[v] = u ;
//             }
//         }
//     }
    
//     if(distance[n] == 1e9){
//         cout << "IMPOSSIBLE" ;
//     }else{
//         // cout << -1*distance[n] + 1 << '\n' ;
//         int temp = n ;
//         vector<int> ans ; 
//         while(temp != 0){
//             ans.push_back(temp) ;
//             temp = parent[temp] ;
//         }
        
//         reverse(ans.begin(),ans.end());
//         cout << ans.size() << '\n' ;
//         for(auto it : ans ) cout << it << ' ' ;
//     }
    
// }  


#include <bits/stdc++.h>
using namespace std ;
int n , m ; 
vector<vector<int>> graph ;
vector<int> inDegree ;

vector<int> kahn(){
    vector<int> ans ;
    priority_queue<int> pq ;
    for(int i = 1 ; i<= n ; i++){
        if(inDegree[i] == 0) pq.push(-i) ;
    }

    while (!pq.empty())
    {
        int node = -pq.top() ;
        pq.pop() ;
        ans.push_back(node) ;
        for(auto neigh : graph[node]){
            inDegree[neigh]-- ;
            if(inDegree[neigh] == 0) pq.push(-neigh) ;
        }
    }
    
    bool isTopologicalOrdered = 1 ;

    for(int i = 1 ; i <= n ; i++){
        if(inDegree[i] > 0){
            isTopologicalOrdered = 0 ;
            break; 
        }
    }
    vector<int> temp ;
    return isTopologicalOrdered ? ans : temp;
}
signed main(){
    cin >> n >> m ;
    graph.resize(n+1) ;
    inDegree.resize(n+1,0) ; 

    for(int i = 0 ; i < m ; i++){
        int a , b ; cin >> a >> b ;

        graph[a].push_back(b) ;
        inDegree[b]++ ;
    }

    vector<int> topo = kahn() ;
    vector<int> distance(n+1,-1e9);
    vector<int> parent(n+1,-1) ;
    parent[1] = 0 ;
    distance[1] = 0 ;

    // for(auto it : topo) cout << it << ' ' ;
    // cout << '\n' ;
    for(auto u : topo){

        if(distance[u] == -1e9) continue; // unreachble from 1

        for(auto v : graph[u]){

            if(distance[v] < distance[u] + 1){
                distance[v] = distance[u] + 1 ;
                parent[v] = u ;
            }
        }
    }

    if(distance[n] == -1e9){
        cout << "IMPOSSIBLE" ;
    }else{
        // cout << -1*distance[n] + 1 << '\n' ;
        int temp = n ;
        vector<int> ans ; 
        while(temp != 0){
            ans.push_back(temp) ;
            temp = parent[temp] ;
        }
        
        reverse(ans.begin(),ans.end());
        cout << ans.size() << '\n' ;
        for(auto it : ans ) cout << it << ' ' ;
    }


}