#include <iostream>
using namespace std;

bool fun(int & n){
    // for(int i = 1 ; i <= n/2 ; i++){
    //     if(i%2 == 0 && (n-i)%2 == 0 ) return true ;
    // }
    // return false ;
    if (n == 2)
    {
        return 0 ;
    }
    if(n%2 == 0) return 1 ;
    return 0 ;
    
}

int main(){
    int n ; cin >> n ;
    if(fun(n)) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}
