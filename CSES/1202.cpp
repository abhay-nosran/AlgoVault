#include <bits/stdc++.h>
using namespace std ;
int mod = 1e9 + 7 ;
#define int long long 
signed main(){
     int n , m ; cin >> n >> m ; 
    vector<vector<pair<int,int>>> graph(n+1) ;
    vector<int> distance(n+1,1e18) ;
    vector<int> routes(n+1,0) ;
    vector<int> maxFlights(n+1,0) ;
    vector<int> minFlights(n+1,0) ;
    vector<int> visited(n+1,0) ;
     for(int i = 0 ; i < m ; i++){
        int u , v , w ; cin >> u >> v >> w ;
        graph[u].push_back({v,w}) ;
     }

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq ;
     distance[1] = 0 ;
     routes[1] = 1 ;
     minFlights[1] = 0 ;
     maxFlights[1] = 0 ;
     pq.push({0,1}) ;

    while (!pq.empty())
    {
       auto state = pq.top() ;
       pq.pop() ;
       int node = state.second ;
       
       int previousDistance = state.first ;

       if(visited[node] == 1) continue; 
       visited[node] = 1 ;

       for(auto it : graph[node]){
        int neigh = it.first ;
        int w = it.second ;
        if(distance[neigh] > previousDistance + w){
            distance[neigh] = previousDistance + w ;
            routes[neigh] = routes[node] ;
            maxFlights[neigh] = maxFlights[node] + 1 ;
            minFlights[neigh] = minFlights[node] + 1 ;
            pq.push({distance[neigh],neigh}) ;
        }

        else if(distance[neigh] == previousDistance + w){
            routes[neigh] = (routes[neigh] + routes[node])%mod ;
            maxFlights[neigh] = max(maxFlights[neigh],maxFlights[node]+1);
            minFlights[neigh] = min(minFlights[neigh],minFlights[node]+1) ;
        }
       }
    }
    
    cout << distance[n] << ' ' << routes[n] << ' ' << minFlights[n] << ' ' << maxFlights[n] ;
}