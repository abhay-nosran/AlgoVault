#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fun(vector<int> & arr){
    int n = arr.size() ;
    int index =  max_element(arr.begin(),arr.end()) - arr.begin(); 
    if(n-1 == index) {
        int second = max_element(arr.begin(),arr.begin() + index) - arr.begin() ;
        cout << arr[index] + arr[second] << endl ;
    }
    else{
        cout << arr[index] + arr[n-1] << endl ;
    }

}
int main(){
    int t ; cin>>  t ;

for(int i = 0 ; i < t ; i++){

        int n ; cin >> n ; 
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            int element ; cin >> element ;
            arr[i] = element ;
        }
        fun(arr);
    }
    return 0 ;
}