#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size(),low=0,mid=0,high=n-1;
    
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++,low++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
        else
            mid++;
    }
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0; i<n ; i++)cin>>nums[i];

    sortColors(nums);

    for(int i=0 ; i<n ; i++)cout<<nums[i]<<" ";

}