#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int p1=0,p2=1,n=nums.size();
    
    while(p1<n){
        if(nums[p1]==0)
            break;
        p1++;
    }
    p2 = p1+1;
    while(p2<n){
        if(nums[p2]!=0)
            break;
        p2++;
    }
    
    while(p2<n){
        swap(nums[p1],nums[p2]);
        while(p2<n){
            if(nums[p2]!=0)
                break;
            p2++;
        }
        while(p1<n){
            if(nums[p1]==0)
                break;
            p1++;
        }
    }
    
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    moveZeroes(nums);

    for(int i=0 ; i<n ; i++)cout<<nums[i]<<" ";

    return 0;
}