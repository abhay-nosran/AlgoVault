#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1} ;
void solve(){
    int n , m ; cin >> n >> m ;

    vector<vector<int>> matrix(n,vector<int>(m));
    vector<int> type(n*m+1,0) ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j] ;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            int node = matrix[i][j] ;
            if(type[node] == 2) continue; 
            type[node] = 1 ;
           for(int k = 0 ; k < 4 ; k++){
                int nrow = i + dx[k] ;
                int ncol = j + dy[k] ;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && node == matrix[nrow][ncol]){
                    type[node] = 2 ;
                }
           }
        }
        
    }

    int maxi = *max_element(type.begin(),type.end());
    int sum = 0 ; 
    for(auto it : type) sum += it ;

    cout << sum - maxi << '\n' ;

    
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int t ; cin >> t; while(t--)
    solve();
}