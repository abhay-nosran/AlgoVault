#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    sort(arr.begin(),arr.end());

    int ans = 0 ;
    for (int i = 1; i < n; i++)
    {  
       ans += arr[i] - arr[i-1] ;
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