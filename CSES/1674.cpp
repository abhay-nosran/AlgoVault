#include <bits/stdc++.h>
using namespace std ;
int n ; 
vector<int> graph[200011] ;
int subOrdinate[200011] ;

void dfs(int node){
    for(auto neigh : graph[node]){
            dfs(neigh) ;
            subOrdinate[node] += subOrdinate[neigh] + 1;
    }
}
signed main(){
    cin >> n ;

    for(int i = 1 ; i < n ; i++){
        int u , v = i+1; cin >> u ; 
        graph[u].push_back(v) ;
    }

    dfs(1) ;
    
    for(int i = 1 ; i <= n ; i++){
        cout << subOrdinate[i] << ' ';
    }
}