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

    vector<int> ans = kahn() ;

    if(ans.size() == 0){
        cout << "IMPOSSIBLE" ;
    }else{
        for(auto it : ans ) cout << it << ' ' ;
    }
}