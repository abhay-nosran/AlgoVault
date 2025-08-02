#include <bits/stdc++.h>
using namespace std ; 
void solve(){
    int n ; cin >> n ;
    int matrix[n][n] ;
    int flag = 0 ;
    int l = 1 , r = n*n ;
    int t = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            
            if(t) matrix[i][j] = r--;
            else matrix[i][j] = l++ ;
            t = 1 - t ; 
        }
        if(flag) reverse(matrix[i],matrix[i]+n) ;
        flag = 1 - flag ;
    }

    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n' ;
    }
}
signed main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}