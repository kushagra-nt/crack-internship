#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int n = matrix.size(),m=matrix[0].size();
    
    int rl=0,rr=m-1,cu=0,cd=n-1,i;
    
    while(cu<=cd && rl<=rr){
        for(i=rl ; i<=rr ; i++)
            ans.push_back(matrix[cu][i]);
        cu++;
        
        if(cu>cd)
            break;
        
        for(i=cu ; i<=cd ; i++)
            ans.push_back(matrix[i][rr]);
        rr--;
        
        if(rl>rr)
            break;
        
        for(i=rr ; i>=rl ; i--)
            ans.push_back(matrix[cd][i]);
        cd--;
        
        if(cu>cd)
            break;
        
        for(i=cd ; i>=cu ; i--)
            ans.push_back(matrix[i][rl]);
        rl++;
    }
    return ans;
}

int main(){
    

}