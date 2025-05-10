#include <bits/stdc++.h>
#define F first
#define S second 
using namespace std;
using ii = pair<int,int> ;
int INF = 1e9 ;

void solve(){
    int n , m ; cin >> n >> m ; // n x m matrix 
    string arr[n] ;
    int dist[n][m] ;
    ii parent[n][m] ;

    queue<ii> q ;
    //input 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;

        for (int j = 0; j < m; j++)
        {   
            parent[i][j] = {i,j} ;
            if(arr[i][j] == 'M' || arr[i][j] == 'A'){
                q.push({i,j}) ;
                dist[i][j] = 0 ;
            }else{
                dist[i][j] = INF ;
            }
        }
        
    }

    int dy[4] = {0,1,0,-1} ;
    int dx[4] = {1,0,-1,0} ;

    while(!q.empty())
    {
        ii node = q.front() ; q.pop() ;
        int row = node.F , col = node.S ;
        char type = arr[row][col] ;

        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + dx[i], ncol = col + dy[i]; 

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] != '#' && dist[nrow][ncol] > dist[row][col] + 1){
                dist[nrow][ncol] = dist[row][col] + 1 ;
                if(type != 'M') parent[nrow][ncol] = {row,col} ;
                q.push({nrow,ncol});
                
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << '(' << parent[i][j].F << ',' << parent[i][j].S << ") " ;
        }
        cout << endl ;
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << endl ;
        
    }
    
    


    
}

int main(){
    solve();
}