#include <bits/stdc++.h>
using namespace std ;
#define int long long 
signed main(){
    int n , m ; cin >> n >> m ;
    vector<vector<pair<int,int>>> graph(n+1) ;
    for(int i = 0  ; i < m ; i++){
        int u , v, w ; cin >> u >> v >> w ;
        graph[u].push_back({v,w}) ;
    }
    
    vector<vector<int>> distance(n+1,vector<int>(2,1e18)) ;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;
    vector<vector<int>> visited(n+1,vector<int>(2,0)) ;
    distance[1][0] = 0 ; 
    distance[1][1] = 0 ;
    
    pq.push({0,{1,0}}) ;
    
    while(!pq.empty()){
        
        auto state = pq.top() ;
        pq.pop() ;
        int node = state.second.first ;
        int couponUsed = state.second.second ;
        int previousDistance = state.first ;
        
        if(visited[node][couponUsed]) continue ;
        visited[node][couponUsed] = 1 ;
        
        for(auto it : graph[node]){
            int neigh = it.first ;
            int w = it.second ;
            // use coupon 
            if(couponUsed == 0 && distance[neigh][1] > previousDistance + (w)/2){
                distance[neigh][1] = previousDistance + (w)/2 ;
                pq.push({distance[neigh][1],{neigh,1}}) ;
            }
        
            // do not use coupon
            // case 1 : couponUsed previously 
            if(couponUsed == 1 && distance[neigh][1] > previousDistance + w){
                distance[neigh][1] =  previousDistance + w ;
                pq.push({distance[neigh][1],{neigh,1}}) ;
            }
            //case 2 : coupon not Used previously 
            if(couponUsed == 0 && distance[neigh][0] > previousDistance + w){
                distance[neigh][0] = previousDistance + w ;
                pq.push({distance[neigh][0],{neigh,0}});
            }
        }
    }
    
    cout << distance[n][1] << '\n' ;
} 