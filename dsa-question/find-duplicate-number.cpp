#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>&nums) {
    int n = nums.size();
    int ans;
    
    for(int i=0 ; i<n ; i++){
        int x = nums[i]%n;
        if(nums[x]>n){
            ans = x;
            break;
        }
        nums[x] += n;
    }
    
    for(int i=0 ; i<n ; i++)nums[i] = nums[i]%n;
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    cout<<findDuplicate(nums);

    return 0;
}