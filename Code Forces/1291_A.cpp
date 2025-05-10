#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n  ; cin >> n ;
    string num ; cin >> num ;
    if(num[n-1] % 2 == 0){
        num.pop_back();
        n--;
    }
    while (n > 0 && num[n-1]%2 == 0)
    {
        num.pop_back();
        n--;
    }
    

    if(n == 0){
         cout << -1 << '\n' ;
         return ;
    }

    int oddIndex = -1 ;
    int evenCnt = 0 , oddCnt = 0 ;
    for (int i = 0; i < n-1; i++)
    {
        if(num[i]%2 == 0){
            evenCnt++;
        }else{
            oddCnt++;
            oddIndex = i ;
        }
    }
    
    if(oddCnt == 0 ){
        cout << -1 << '\n' ;
        return ;
    }
    if(oddCnt%2 == 0){
        num.erase(oddIndex,1) ;
    }

    cout << num << '\n' ;

}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}