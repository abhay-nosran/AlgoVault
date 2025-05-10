#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ;
    int arr[n] ;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    
    int maxi = max(arr[0],arr[n-1]) ;

    if(maxi == n){
        cout << "NO\n" ;
        return;
    }

    int k ; 

    for(int i = 1; i < n-1 ; i++){
        if(arr[i] > maxi) k = i ;
    }
    cout << "YES\n";
    cout << 1 << ' ' <<k<<' ' << n << '\n';

}

int main(){
    int t ; cin >> t ; 
    while(t--){
        solve() ;
    }
}