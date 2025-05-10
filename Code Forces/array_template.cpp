#include<bits/stdc++.h>
using namespace std;

void inputArray(int * arr , int n ){

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
}

void printArray(int * arr , int n){

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ' ' ;
    }
    cout << '\n';
}

int * getMinimum(int * arr , int n){

    int * mini = arr;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] < *mini){
            mini = arr + i ;
        }
    }
    return mini ;
}

vector<vector<char>> vectorInput(int & n , int & m){
    vector<vector<char>> v(n,vector<char> (m,0)) ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> v[i][j] ;
        }
    }
    return v ;
}