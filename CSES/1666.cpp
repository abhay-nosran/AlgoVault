#include <bits/stdc++.h>
using namespace std ;
int component[100010] ;
vector<vector<int>> graph ;
int numComponents ;

void dfs(int x){
    component[x] = numComponents ;

    for(auto it : graph[x]){

        if(component[it] == -1){
            dfs(it) ;
        }
    }
}
int main(){
    int n , m ; cin >> n >> m ;
    graph.resize(n+1) ;
    memset(component,-1,sizeof(component)) ;

    for(int i = 0 ; i < m ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    numComponents = 0 ;
    
    vector<int> arr ;
    for(int i = 1 ; i <= n ; i++){

        if(component[i] == -1){
            arr.push_back(i) ;
            numComponents++;
            dfs(i) ;
        }
    }

    int numRoads = numComponents - 1;
    cout << numRoads << '\n' ;
    for(int i = 1 ; i <= numRoads ; i++){
        cout << arr[i-1] << ' ' << arr[i] << '\n' ;
    }

}