#include <bits/stdc++.h>
using namespace std ;
vector<vector<char>> grid ;
vector<vector<int>> visited ;
int n , m ;
int dx[4] = {0,+1,0,-1} ;
int dy[4] = {-1,0,+1,0} ;

int cnt = 0 ;

void dfs(int i, int j){

    visited[i][j] = 1 ;

    for(int k = 0 ; k < 4  ; k++){
        int nrow = i + dy[k] ;
        int ncol = j + dx[k] ;

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != '#' && !visited[nrow][ncol]){
            dfs(nrow,ncol) ;
        }
    }
    
}

void solve(){
    cin >> n >> m ;
    grid.resize(n,vector<char>(m)) ;
    visited.resize(n,vector<int>(m,0)) ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] != '#' && !visited[i][j]){
                cnt++ ;
                dfs(i,j) ;
            }
        }
    }

    
    cout << cnt ;

    
    
}
int main(){
    solve() ;

}