#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> graph[200100];
int ans[200100] ;
int visited[200100] ;
int treeSize[200100] ;
int n  ; 
void dfs(int node){

    visited[node] = 1 ;
    ans[node] = 0 ;
    treeSize[node] = 1;

    for(auto it : graph[node]){

        if(!visited[it]){
            dfs(it) ;
            treeSize[node] += treeSize[it] ;
            ans[node] +=  ans[it] + treeSize[it] ;
        }
    }

}

void dfs1(int node , int parent){
    visited[node] = 1 ;
    ans[node] = ans[parent] + n - 2*treeSize[node] ;

    for(auto it : graph[node]){

        if(!visited[it]){
            dfs1(it,node) ;
        }
    }
}
void solve(){
   cin >> n ;

    for(int i = 1 ; i <  n ; i++){
        int u , v ; cin >> u >> v ;

        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    memset(visited,0,sizeof(visited)) ;
    dfs(1) ;
    // for(int i = 1 ; i <= n ; i++){
    //     cout << ans[i] << ' ';
    // }
    memset(visited,0,sizeof(visited)) ;
    visited[1] = 1;
    for(auto it : graph[1]){
        dfs1(it,1) ;
    }


    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << ' ';
    }

}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}