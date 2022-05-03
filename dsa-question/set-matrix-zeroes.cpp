#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(),m=matrix[0].size(),i,j;
    
    bool fr=false,fc=false;
    
    for(i=0 ; i<n ; i++){
        if(matrix[i][0]==0){
            fc=true;
            break;
        }
    }
    for(j=0 ; j<m ; j++){
        if(matrix[0][j]==0){
            fr=true;
            break;
        }
    }
    
    for(i=1 ; i<n ; i++){
        for(j=1 ; j<m ; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0,matrix[0][j] = 0;
            }
        }
    }
    
    for(i=1 ; i<n ; i++){
        if(matrix[i][0]==0){
            for(j=0 ; j<m ; j++)
                matrix[i][j] = 0;
        }
    }
    for(j=1 ; j<m ; j++){
        if(matrix[0][j]==0){
            for(i=0 ; i<n ; i++)
                matrix[i][j] = 0;
        }
    }
    if(fr){
        for(j=0 ; j<m ; j++)
            matrix[0][j] = 0;
    }
    if(fc){
        for(i=0 ; i<n ; i++)
            matrix[i][0] = 0;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++)cin>>matrix[i][j];
    }

    setZeroes(matrix);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++)cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}