#include<iostream>
#include<vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int n=board.size(),m=board[0].size();
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int cnt=0;
            
            if(i>0 && j>0)cnt += (board[i-1][j-1]==1 || board[i-1][j-1]==3);
            if(i>0) cnt += (board[i-1][j]==1 || board[i-1][j]==3);
            if(i>0 && j<m-1)cnt += (board[i-1][j+1]==1 || board[i-1][j+1]==3);
            if(j>0)cnt += (board[i][j-1]==1 || board[i][j-1]==3);
            if(j<m-1)cnt += (board[i][j+1]==1 || board[i][j+1]==3);
            if(i<n-1 && j>0)cnt += (board[i+1][j-1]==1 || board[i+1][j-1]==3);
            if(i<n-1)cnt += (board[i+1][j]==1 || board[i+1][j]==3);
            if(i<n-1 && j<m-1)cnt += (board[i+1][j+1]==1 || board[i+1][j+1]==3);

            if(board[i][j]==0){
                if(cnt==3)board[i][j] = 2;
            }
            else{
                if(cnt<2 || cnt>3)board[i][j] = 3;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(board[i][j]==2)board[i][j] = 1;
            else if(board[i][j]==3) board[i][j] = 0;
        }
    }
}

int main(){
    

}