#include<iostream>
#include<vector>
using namespace std;

int ans;

void merge(vector<int>&nums,int l,int mid,int r){
    vector<int>temp;
    int p1=l,p2=mid+1;
    
    int i=l,j=mid+1;
    while(i<=mid){
        while(j<=r && nums[i]>2ll*nums[j])j++;
        ans += j-mid-1;
        i++;
    }

    while(p1<=mid && p2<=r){
        
        if(nums[p1]<nums[p2]){
            temp.push_back(nums[p1]);
            p1++;
        }
        else{
            temp.push_back(nums[p2]);
            p2++;
        }
    }
    while(p1<=mid){
        temp.push_back(nums[p1]);
        p1++;
    }
    while(p2<=r){
        temp.push_back(nums[p2]);
        p2++;
    }
    for(int i=l,j=0 ; i<=r ; i++,j++)nums[i] = temp[j];
}

void mergeSort(vector<int>&nums,int l,int r){
    if(l>=r)return;

    int mid = l+(r-l)/2;
    mergeSort(nums,l,mid);
    mergeSort(nums,mid+1,r);
    merge(nums,l,mid,r);
}

int reversePairs(vector<int>& nums) {
    ans =0;
    mergeSort(nums,0,nums.size()-1);
    return ans;
}

int main(){
    
}