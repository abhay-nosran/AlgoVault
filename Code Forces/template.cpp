#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define F first 
#define S second 
using ii = pair<int,int> ;

int mod = 1e9+7 ;

int binPow(int a , int b){
    if(b==0) return 1 ;

    if(b%2){
        return a*binPow(a,b-1)%mod;
    }else{
        int x = binPow(a,b/2);
        return (x*x)%mod;
    }
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

vector<int> input0(int n){
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    return a ;
}
vector<int> input1(int n){
    vector<int> a(n+1);
    a[0] = -1 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
    }
    return a ;
}