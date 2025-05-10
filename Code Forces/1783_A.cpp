#include <iostream>
using namespace std;

void solve(){
    int n ; cin >> n ;
    int arr[n] ;
    int sum = 0 ; 

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }

    bool isPossible = 1 ;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == sum){
            //need to swap with just bda
           for (int j = i+1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {   
                    if(j == n-1)
                    continue; 
                }else{
                    swap(arr[i],arr[j]);
                } 
            }
        }

        sum += arr[i] ;

    }
    
}

int main(){
    int t ; 
    cin >> t ;

    while (t--)
    {
        solve();
    }
    
}