#include <bits/stdc++.h>
using namespace std ;
int mod = 998244353 ;
int binpow(int a , int b){ if(b == 0) return 1 ; if(b%2 == 0){ int x = binpow(a,b/2); return (x*x) % mod; } else{ return (a*binpow(a,b-1))%mod; } }
int inverse(int a){
    return binpow(a,mod-2) ;
}
void solve(){
    int n ; cin >> n ;

    int arr[n+1] ;
    int prefixSum[n+1] ;
    memset(prefixSum, 0, sizeof(prefixSum)) ;

    

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
        prefixSum[i] = prefixSum[i-1] ;
        if(arr[i] == 2) prefixSum[i] += 1 ;
    }

    int ans = 0 ; int sum = 0 ;  int cnt = 0 ;
    int p1 = 1 ;
    while(p1 < n-1 && arr[p1] != 1){
        p1++ ;
    }

    cout << p1 << ' ' ;
    if(p1 == n-1){
        cout << 0 << '\n' ;
        return ;
    }

    for (int i = p1; i <= n; i++)
    {
        if(arr[i] == 3){
            cnt++;
            sum += binpow(2,prefixSum[i]) ;
        }
    }

    cout << cnt << ' ' << sum << ' ';
    
    for (int i = p1; i <= n; i++)
    {
        if(arr[i] == 1){
            ans = ans + (sum)*(inverse(binpow(2,prefixSum[i ]))) - cnt ;
        }else if(arr[i] == 3){
            sum -= binpow(2,prefixSum[i]) ;
            cnt-- ;
        }
    }

    cout << ans << '\n'; 
    
}
int main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}