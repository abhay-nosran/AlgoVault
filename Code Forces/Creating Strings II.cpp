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

signed main(){

    precompute() ;
    string s ; cin >> s ;
    int n = s.size() ;

    // frequency calculation
    int freq[26] = {0} ;

    for(int i = 0 ; i < n ; i++){
        freq[s[i]-'a']++ ;
    }

    int num = fact[n] ;
    int deno_inverse = 1 ;

    for(int i= 0 ; i < 26 ; i++){
        deno_inverse = (deno_inverse * invfact[freq[i]])%mod ;
    }

    cout << (num*deno_inverse)%mod ;

}