#include<iostream>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int>ans;
    int n=nums.size();
    
    for(int i=0 ; i<n ; i++){
        int x = nums[i]%(n+1);
        if(nums[x-1]>n)
            ans.push_back(x);
        else
            nums[x-1] += n+1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    vector<int>ans = findDuplicates(nums);

    for(auto i:ans)cout<<i<<" ";

    return 0;
}