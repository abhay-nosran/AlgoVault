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
signed main(){
    int n , q ; cin >> n >> q ;

    // tree input
    for(int i = 2 ; i <= n ; i++){
        int u ; cin >> u ; // v is i

        graph[u].push_back(i) ;
        graph[i].push_back(u) ;
    }

    // 0 is  the top most node before 1 ;
    memset(parent,0,sizeof(parent)) ;
    depth[0] = 0 ;// 1 node depth is 1 ;

    // establish parent linkage 
    dfs(1,0,1) ;

    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 0 ; j < 20 ; ++j){
            
    //         cout << parent[i][j] << ' ' ;
    //     }
    //     cout << '\n' ;
    // }
    while (q--)
    {
        int a , b ; cin >> a >> b ;
        cout << getLca(a,b) << '\n' ;
    }
    
}   