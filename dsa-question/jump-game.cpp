#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size(),i,j;
    
    i=0;
    
    while(true){
        int maxIndex = nums[i]+i;
        int index=i;
        
        for(j=i+1 ; j<=min(n-1,i+nums[i]) ; j++){
            if(nums[j]+j > maxIndex){
                maxIndex = nums[j]+j;
                index = j;
            }
        }
        
        if(maxIndex>=n-1)return true;
        
        if(maxIndex==i)
            break;
        if(index==i)i = maxIndex;
        else
        i = index;
    }
    return false;
}

int main(){

}