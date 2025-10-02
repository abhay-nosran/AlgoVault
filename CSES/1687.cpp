#include <bits/stdc++.h>
using namespace std;
vector<int> graph[200100] ;
int par[200100][20] ;

void dfs(int node , int parent){

    par[node][0] = parent ;

    for(int i = 1 ; i < 20 ; i++){
        par[node][i] = par[par[node][i-1]][i-1] ;
    }

    for(auto it : graph[node]){
        if(it != parent){
            dfs(it,node) ;
        }
    }


}

int getPar(int node , int k){

    int parent = node;
    for(int i = 19 ; i >= 0 ; i--){

        if(k & (1<<i)){
            parent = par[parent][i] ;
        }
    }

    return parent ;
}
void solve(){
    int n , q ; cin >> n >> q ;

    // tree making
    for(int i = 2 ; i <= n ; i++){
        int u ; cin >> u ;
        // v is i 
        graph[u].push_back(i) ;
        graph[i].push_back(u) ;
    }

    memset(par,0,sizeof(par));

    dfs(1,0) ;

    while (q--)
    {
        int x , k ; cin >> x >> k ;
        int ans = getPar(x,k) ;
        if(ans == 0) cout << -1 << '\n' ;
        else cout << ans << '\n' ;
    }
    
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}