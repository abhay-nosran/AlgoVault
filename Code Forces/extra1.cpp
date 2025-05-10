#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g ;
    vector<int> parent ;
    vector<int> visited ;
    set<pair<int,int>> st ;
vector<vector<int>> edges ;
bool isCycle = 0 ;

    void getEdges(int startNode , int endNode){
        st.insert({startNode,endNode});
        st.insert({endNode,startNode});

        int node = endNode ;
        int par = parent[endNode] ;
        while(node != startNode && par != -1){
            st.insert({node,par});
            st.insert({par,node});

            node = par ;
            par = parent[node];
        }

    }

    void dfs(int node,int par){
        visited[node] = 1 ;
        parent[node] = par ;

        for(auto neigh : g[node]){
            if(isCycle) return ;
            if(visited[neigh] == 0){
                dfs(neigh,node);
            }
            else if(parent[node] != neigh) {
                isCycle = 1;
                getEdges(neigh,node);
            }
        }
    }
    vector<int> findRedundantConnection() {
        int n = edges.size() ;
        g.resize(n+1);
        parent.resize(n+1,-1);
        visited.resize(n+1,0);

        for(int i = 0 ; i < n  ; i++){
            int u = edges[i][0] , v = edges[i][1] ; 
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        dfs(1,0) ;

        for(int i = n-1 ; i >= 0 ; i--){
            int u = edges[i][0] , v = edges[i][1] ; 
            if(st.find({u,v}) != st.end()){
                return {u,v};
            }
        }

        return {};

        
    }

int main(){
    int n  ; cin >> n ;
    edges.resize(n) ;
    for (int i = 0; i < n; i++)
    {
        int u , v ; cin >> u >> v ;
        edges[i] = {u,v} ;
    }
    
    vector<int> a = findRedundantConnection() ;

    for(auto it : a) cout << it << ' ';
}   



