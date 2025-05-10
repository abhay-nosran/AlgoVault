#include <bits/stdc++.h>
using namespace std ;   

void solve(){
    int n ; cin >> n ; 
    int arr[n] ;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    
    bool possible = 1 ;
    int left , right ;
    for (int i = 0; i < n; i++)
    {
        left = i ; right = n-1 - i ;
        if(arr[i] - max(2*left,2*right) <= 0){
            possible = 0 ;
            break;
        }
    }

    if(possible) cout << "YES\n" ;
    else cout << "NO\n" ;
    
}

int main(){

    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}