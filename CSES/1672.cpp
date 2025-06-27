#include <bits/stdc++.h>
#define int long long 
using namespace std ;
int matrix[501][501] ;
signed main(){
    int n , m ,q  ; cin >> n >> m >> q ;

    for(int i = 0 ; i < 501 ; i++){
        for(int j  = 0 ;  j < 501 ; j++){
            if(i == j)  matrix[i][j] = 0 ;
            else matrix[i][j] = 1e18 ;
        }
    }

    for(int i = 0 ; i < m ; i++){
        int u,v,w ; cin >> u >> v >> w ;
        matrix[u][v] = min(matrix[u][v],w) ;
        matrix[v][u] = min(matrix[v][u],w) ;
    }


    // floyd-warshall 
    for(int k = 1 ; k <= n ; k++){

        for(int i = 1 ; i <= n ; i++){
            for (int j = 1; j <= n; j++)
            {
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j] ;
                }
            }
            
        }
    }

    while (q--)
    {
        int u , v ; cin >> u >> v ;

        if(matrix[u][v] >= 1e18){
            cout << -1 << '\n' ;
        }else{
            cout << matrix[u][v] << '\n' ;
        }
    }
    
}