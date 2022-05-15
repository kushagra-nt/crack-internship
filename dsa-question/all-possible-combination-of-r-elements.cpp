#include<iostream>
#include<vector>
using namespace std;

vector<int>v;
int r;
vector<vector<int>>ans;

void fun(vector<int>&nums,int index){
    if(v.size()==r){
        ans.push_back(v);
        return;
    }
    if(index==nums.size()){
        ans.push_back(v);
        return;
    }
    if(nums.size()-index==r-v.size()){
        v.push_back(nums[index]);
        fun(nums,index+1);
        v.pop_back();
        return;
    }
    fun(nums,index+1);
    v.push_back(nums[index]);
    fun(nums,index+1);
    v.pop_back();
}

int main(){

}