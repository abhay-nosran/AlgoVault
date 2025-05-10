#include <bits/stdc++.h>
using namespace std ; 
#define int long long 
int arr[1001][1001];
int mod = 1e9 + 7; 
int binpow(int a , int b){ if(b == 0) return 1 ; if(b%2 == 0){ int x = binpow(a,b/2); return (x*x) % mod; } else{ return (a*binpow(a,b-1))%mod; } }
int inverse(int a){ return binpow(a,mod-2); } 
int ncr_random_modulo(int n, int r) { for (int i = 0; i <= n; i++) { for (int j = 0; j <= r; j++) { if(j==0) { arr[i][j] = 1; } else if(j > i) arr[i][j] = 0 ; else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%mod; } } return arr[n][r]; } 
int ncr_basics(int n, int r) { int ans = 1 ; for(int i = 1 ; i <= r ; i++) { ans *= (n - i + 1) ; ans /= i; } return ans ; }
int fact[1000001] ; 
int invfact[1000001] ; 
void precompute(){ fact[0] = 1 ; for(int i = 1 ; i <= 1000000 ; i++){ fact[i] = (fact[i-1] * i) % mod ; } invfact[1000000] = inverse(fact[1000000]); for(int i = 1000000 ; i > 0 ; i--){ invfact[i-1] = (invfact[i] * i)%mod ; } } 
int ncr_fact_faster(int n , int r){ int num = fact[n] ; int deno_inverse = (invfact[n-r] * invfact[r])%mod ; return (num * deno_inverse) % mod ; } int gcd(int a , int b){ if(b == 0) return a ; return gcd(b,a%b) ; }

signed main(){
    int n ; cin >> n ; 
    int arr[n] ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    sort(arr,arr+n) ;
    int ans = 1;

    for(int i = 1 ; i < n ; i++){
        if(arr[i-1] != arr[i]) ans++ ;
    }
    cout << ans ;
}