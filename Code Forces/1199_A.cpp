#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ,x , y; cin >> n >> x >> y;
    int arr[n] ; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }

    for (int i = 0; i < n; i++)
    {
        //checking for ith element 
        int flag = 1 ;

        for (int j = max(0,i-x) ; j <= min(n-1,i+y) ; j++)
        {
            if(arr[j] < arr[i]){
                flag = 0 ;
                break ;
            } 
        }

        if(flag){
            cout << i+1 << '\n' ;
            return ;
        }
        
    }
    

    
}

int main(){
    // int t ; cin >> t; while(t--)
    solve();
}