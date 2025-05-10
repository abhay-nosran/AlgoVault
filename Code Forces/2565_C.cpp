#include <bits/stdc++.h>
using namespace std ;

void solve(){
   int n , m ; cin  >> n >> m ;
   vector<int> arr(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    int till = -1 ;
    int change ; cin >> change ;
    
    bool ans = 1 ;
    for (int i = 1; i < n; i++)
    {
        if(arr[i-1] > arr[i]){
           if(arr[i-1] <= change - arr[i] ){
                till == i ;
                arr[i] = change - arr[i] ;
           }
           else if(till != i-1){
                arr[i-1] = change - arr[i-1] ;
                if(i != 1 && arr[i-2] > arr[i-1]){
                    ans = 0 ;
                    break; 
                }
           }
        }
    }

    // for(auto it : arr) cout << it << ' ';

    if(ans) cout << "YES\n";
    else cout << "NO\n";
    
}
int main(){
    int t ; cin >>t ;
    while (t--)
    {
        solve() ;
    }
    
}