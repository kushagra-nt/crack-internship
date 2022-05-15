#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int p1=n-1,p2=m-1,curr=n+m-1;
    
    while(p1>=0 || p2>=0){
        if(p1>=0 && p2>=0){
            if(nums1[p1]>=nums2[p2]){
                nums1[curr] = nums1[p1];
                p1--;
            }
            else{
                nums1[curr] = nums2[p2];
                p2--;
            }
        }
        else if(p1>=0){
            nums1[curr] = nums1[p1];
            p1--;
        }
        else{
            nums1[curr] = nums2[p2];
            p2--;
        }
        curr--;
    }
}

int main(){
    
}