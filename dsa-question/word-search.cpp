#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<char>>& board, string &word,int x,int y,int index){
    if(index==word.length())return true;
    
    
    bool found=false;
    char c = board[x][y];
    board[x][y] = '#';
    
    if(x+1<board.size() && board[x+1][y]==word[index])
        found = found | (dfs(board,word,x+1,y,index+1));
    
    if(x-1>=0 && board[x-1][y]==word[index])
        found = found | (dfs(board,word,x-1,y,index+1));
    
    if(y+1<board[0].size() && board[x][y+1]==word[index])
        found = found | (dfs(board,word,x,y+1,index+1));
    
    if(y-1>=0 && board[x][y-1]==word[index])
        found = found | (dfs(board,word,x,y-1,index+1));
    
    board[x][y] = c;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    
    bool found = false;
    
    for(int i=0 ; i<board.size() ; i++){
        for(int j=0 ; j<board[0].size() ; j++){
            if(word[0]==board[i][j])
                found = found | (dfs(board,word,i,j,1));
        }
    }
    return found;
}

int main(){
    
}