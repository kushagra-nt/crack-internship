#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size(),p1=1,p2=1,ans=1;
    
    while(p2<n){
        if(nums[p1-1]==nums[p2])
            p2++;
        else{
            nums[p1] = nums[p2];
            p1++,p2++,ans++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    int ans = removeDuplicates(nums);

    cout<<ans<<endl;
    for(int i=0 ; i<ans ; i++)cout<<nums[i]<<" ";

}