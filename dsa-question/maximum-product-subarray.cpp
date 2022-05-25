#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int ans = nums[0],curr=1;
    int n = nums.size();
    
    int maxNeg=0,maxPos=0;
    
    for(int i=0 ; i<n ; i++){
        if(nums[i]==0){
            ans = max(ans,0);
            maxNeg = 0,maxPos = 0,curr=1;
            continue;
        }
        curr *= nums[i];
        if(curr>0){
            ans = max(ans,curr);
        }
        else{
            if(maxNeg<0)
                ans = max(ans,curr/maxNeg);
            else if(maxPos>0)
                ans = max(ans,curr/maxPos);
        }
        if(curr>0)maxPos = max(maxPos,curr);
        else if(curr<0){
            if(maxNeg==0)maxNeg = curr;
            else maxNeg = max(maxNeg,curr);
        }
    }
    return ans;
}

int main(){
    
}