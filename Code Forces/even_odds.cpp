#include <iostream>
using namespace std;

int main(){
    long long n,k ; cin >> n >> k ; 
    long long even = n/2 ;
    long long odd = n - even ;
    long long ans ;
    if (k <= odd){
       // kth odd number  
       ans = 1 + (k-1)*2 ;
    }
    else {
        //k-odd th even number 
        ans = 2 + (k-odd-1)*2 ;
        
    }
    cout << ans ;
    return 0 ;
}