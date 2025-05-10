#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n  ; cin >> n ;
    int arr[n] ;
    for (int i = 0; i < n ; i++)
    {
        cin >> arr[i] ;
    }   

    int diff = INT_MAX ;

    for(int i = 1 ; i < n ; i++){
        diff = min(diff,arr[i]-arr[i-1]) ;
    }

    if(diff < 0){
        cout << 0 << '\n' ;
    }else{
        if(diff%2 == 0) cout << (diff/2)+1 << '\n' ;
        else cout << (diff+1)/2 << '\n';
    }
    
}

int main(){
    int t ; cin  >> t ;
    while (t--)
    {
        solve() ;
    }
    
}