#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g ;
vector<int> dist ;
vector<int> visited ;
vector<int> parent ;
int INF = 1e9 ;

vector<int> getPath(int last){
    int par = last ;
    vector<int> ans ;
    while (par != 0)
    {
        ans.push_back(par) ;
        par = parent[par] ;
    }
    
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}
void solve(){
    int n , m  ; cin >> n >> m ;
    g.resize(n+1) ;
    dist.resize(n+1,INF) ;
    visited.resize(n+1,0) ;
    parent.resize(n+1,0) ;

    for (int i = 0 ; i < m ; i++)
    {
        int a , b  ;
        cin >> a >> b ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }

    dist[1] = 0 ;
    parent[1] = 0 ;
    queue<int> q ;
    q.push(1) ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;

        visited[node] = 1 ;

        for(auto neigh : g[node]){
            if(visited[neigh] == 0 && dist[neigh] > dist[node] + 1){
                dist[neigh] = dist[node] + 1 ;
                parent[neigh] = node ;
                q.push(neigh) ;
            }
        }
    }

    if(dist[n] == INF){ cout << "IMPOSSIBLE" ; return ;}
    cout << dist[n] + 1 << '\n'; 
    vector<int> path = getPath(n) ;
    for(auto it : path) cout << it << ' ' ;

    
}

int main(){
    // int t ; cin >> t; while(t--)
    solve();
}