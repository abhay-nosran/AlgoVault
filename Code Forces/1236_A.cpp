#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a , b , c ; cin >> a >> b >> c ;

    int operations =  min((c/2),b);

    b = b - operations ;
    
    operations +=  min((b/2),a) ;

    cout << (3*operations) << '\n' ;
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}