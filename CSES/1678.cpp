#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph ;
vector<int> parent ;
vector<int> color ;
bool isCycle ;
vector<int> cycleNodes ;

void dfs(int node , int par){
    
    color[node] = 2 ;
    parent[node] = par ;

    for(auto v : graph[node]){

        if(color[v] == 1){
            dfs(v,node) ;
        }

        else if(color[v] == 2){
            // cycle is detected

            if(isCycle == 0){
                int temp = node ;

                while (temp != v)
                {
                    cycleNodes.push_back(temp) ;
                    temp = parent[temp] ;
                }
                cycleNodes.push_back(temp) ;
                reverse(cycleNodes.begin(),cycleNodes.end()) ;
                cycleNodes.push_back(temp) ;
                isCycle = 1;
            }
        }

        // color 3 is of no use in undirected graph
        else if(color[v] == 3){
            // do nothing
        }
    }

    color[node] = 3 ;
}
int main(){
    int n , m ; cin >> n >> m ;

    graph.resize(n+1);
    parent.resize(n+1);
    color.resize(n+1,1); 

    for(int i = 0 ; i < m ; i++ ){
        int u , v ; cin >> u >> v ; 
        graph[u].push_back(v) ;
    }


    for(int i = 1 ; i <= n ; i++){

        if(color[i] == 1){
            dfs(i,0);
        }
    }

    if(isCycle){
        cout << cycleNodes.size() << '\n' ;
        for(auto it : cycleNodes) cout << it << ' ';
        cout << '\n' ;
    }else{
        cout << "IMPOSSIBLE\n" ;
    }
}