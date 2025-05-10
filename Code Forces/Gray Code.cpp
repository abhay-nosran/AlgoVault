#include <bits/stdc++.h>
using namespace std;

int main(){

    int n ; cin >> n ;

    int num = 1 << n ;

    for(int i = 0 ; i < num ; i++){
        int x = (i ^ ( i >> 1 )) ;
        bitset<20> bits(x) ;

        string s = bits.to_string();
        cout << s.substr(20-n) << '\n' ;
    }
}