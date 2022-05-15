#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int ele=nums[0],cnt=1,n=nums.size();
    
    for(int i=1 ; i<n ; i++){
        if(nums[i]==ele)
            cnt++;
        else
            cnt--;
        if(cnt<=0){
            ele = nums[i];
            cnt = 1;
        }
    }
    return ele;
}

int main(){
    
}