#include <bits/stdc++.h>
using namespace std ;
#define int long long
int mod = 1e9 + 7 ;

int binpow(int a , int b){

    if(b == 0) return 1 ;

    if(b%2 == 0){ // even power
        int x = binpow(a,b/2);
        return (x*x) % mod;
    }
    else{
        return (a*binpow(a,b-1))%mod;
    }

}

int inverse(int a){
    return binpow(a,mod-2);
}

int fact[1000001] ;
int invfact[1000001] ;

void precompute(){
    
    fact[0] = 1 ;
    
    for(int i = 1 ; i <= 1000000 ; i++){
        fact[i] = (fact[i-1] * i) % mod ;
    }
    
    invfact[1000000] = inverse(fact[1000000]);
    for(int i = 1000000 ; i > 0 ; i--){
        invfact[i-1] = (invfact[i] * i)%mod ;
    }
    
}

int ncr_fact_faster(int n , int r){
    int num = fact[n] ;
    int deno_inverse = (invfact[n-r] * invfact[r])%mod ;
    return (num * deno_inverse) % mod ;
}

signed main() {

    precompute() ;
	int n ;  cin >> n ;
    while (n--) 
    {
        int a , b ; cin >> a >> b;
        cout << ncr_fact_faster(a,b) << '\n' ;
    }
    
	
}