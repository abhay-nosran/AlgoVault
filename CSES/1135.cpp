#include <bits/stdc++.h>
using namespace std ;
vector<int> graph[200100];
int parent[200100][20] ;
int depth[200100] ;

void dfs(int node , int par , int dep){

    depth[node] = dep ;
    parent[node][0] = par ;

    for(int i = 1 ; i < 20 ; i++){
        parent[node][i] = parent[parent[node][i-1]][i-1] ;
    }

    for(auto it : graph[node]){
        if(it != par){
            dfs(it,node,dep+1) ;
        }
    }

}


int getLca(int a , int b){

    // make 'a' lower
    if(depth[b] > depth[a]){
        swap(a,b) ;
    }
    // take both a and b to the same level 

    for(int i = 19 ; i >= 0 ; i--){
        int d = (depth[a] - depth[b]) ;
        if(d&(1<<i)){
           
            a = parent[a][i] ;
        }
    }

    if(a==b) return a ; // case in which a is in b's subtree
   
    for(int i = 19 ; i >= 0 ; i--){

        if(parent[a][i] != parent[b][i]){
            // cout << i << ' ' << parent[a][i] << ' ' << parent[b][i] << ' '; 
            a = parent[a][i] ;
            b = parent[b][i] ;
            
        }
    }

    return parent[a][0] ;
}
int getDistance(int a , int b){

    int lca = getLca(a,b) ;
    int ans = depth[a] - depth[lca] + depth[b] - depth[lca] ;

    return ans ;
}
void solve(){
    int n ,q ; cin >> n >> q ;

    for(int i = 1 ; i < n ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    depth[0] = 0 ; 
    memset(parent,0,sizeof(parent)) ;
    dfs(1,0,1) ;

    while (q--)
    {
        int a , b ;
        cin >> a >> b ;
         cout << getDistance(a,b) << '\n' ;
    }
    
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}