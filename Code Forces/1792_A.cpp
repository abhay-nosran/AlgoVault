#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }

    sort(arr,arr+n) ;
    int ans = 0 ;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0){

            if(arr[i] == 1 && i+1 < n){
                arr[i] = 0 ;
                arr[i+1]-- ;
            }else{
                arr[i] = 0 ;
            }

            ans++ ;
        }
    }
    
    cout << ans << '\n' ;
}
int main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}