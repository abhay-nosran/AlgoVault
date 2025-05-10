#include<bits/stdc++.h>
// #define int long long   --> this is is a trick to convert every int to long long
using namespace std;
int n ;
int arr[100000];

int check(int mid){
    if(arr[mid] < arr[0]) return 1 ;
    else return 0 ;
}

int bs(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;

    int lo = 0 , hi = n-1 , ans = 0 ;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2 ;
        if(check(mid)==1){
            ans = mid ;
            hi = mid - 1 ;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
void solve(){
    int ans = bs();
    cout << ans << '\n';
   
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}