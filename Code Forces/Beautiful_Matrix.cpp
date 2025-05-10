#include <bits/stdc++.h>
using namespace std ;

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0) ;

    int n = 5 ; 

    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
          int element ; cin >> element ;
          if(element == 1){
            cout << abs(i-2) + abs(j-2) << '\n';
            break; 
          }
       }g
    }
    
}