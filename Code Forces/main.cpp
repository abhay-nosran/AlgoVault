#include <iostream>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char c ;

    if( 0 <= c -'0' && c -'0' <= 10) {
        cout << "IS DIGIT" << '\n' ;
    }
    else if( 0 <= c -'A' && c -'A' <= 26) {
        cout << "ALPHA" << '\n' << "IS CAPITAL";
        
    }
    else if( 0 <= c -'a' && c -'a' <= 10) {
        cout << "ALPHA" << '\n' << "IS SMALL";
    }
}