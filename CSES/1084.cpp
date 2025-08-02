#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n , m , k; cin >> n >> m >> k;
    int arr[n] ;
    int brr[m] ;

    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    for(int j = 0  ; j < m ; j++) cin >> brr[j] ;


    sort(arr,arr+n) ;
    sort(brr,brr+m) ;
    int i = 0 , j = 0 ;
    int ans = 0 ;
    while(i != n && j != m){
        // cout << i << ' ' << j << endl;
        if(brr[j] < arr[i] - k) j++ ;
        else if(arr[i]+k < brr[j]) i++ ;
        else{
            ans++;
            i++;j++;
        }
    }

    cout << ans ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}