#include <bits/stdc++.h>
using namespace std ;

#define n 9


int arr[n][n] ;

void printMatrix(){
    cout << '\n' ;
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ' ;
        }
        cout << '\n' ;
    }

    
}

void girdCreation(){

    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j] ;
        }
        
    }
}

void getUnassigned(int & row , int & col){
    row = -1 ; col = -1 ; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0) {
                row = i ; col = j ;
                return ;
            }
        }
        
    }
    
}

bool checkRow(int row , int x){

    for (int i = 0; i < n; i++)
    {
        if(arr[row][i] == x){
             return false ;
            }
    }

    return true ;
    
}
bool checkColumn(int col , int x){

    for (int i = 0; i < n; i++)
    {
        if(arr[i][col] == x) return false ;
    }

    return true ;
    
}

bool checkGrid(int row , int col , int x){

    int baseRow = row - row%3 ;
    int baseColumn = col - col%3 ;

    for (int i = 0; i < n/3; i++)
    {
        for (int j = 0; j < n/3; j++)
        {
            if(arr[baseRow+i][baseColumn+j] == x) return false ;
        }
        
    }
    return true ;
    
}
void solveSudoku(){

    int row , col ; 

    getUnassigned(row,col) ;

   

    //(i,j) unassigned/empty place (-1,-1) if every place is assigned
    if(row == -1 && col == -1){
        printMatrix();
        return ;
    }

    for (int i = 1 ; i <= n; i++)
    { 
        //check if i can be put inside matrix at (row,col) position
        if(checkRow(row,i) && checkColumn(col,i) && checkGrid(row,col,i)){
            arr[row][col] = i ;
            solveSudoku();
            arr[row][col] = 0 ;
        }
    }
    
    return ;
}

signed main(){
    girdCreation();
    solveSudoku();
}