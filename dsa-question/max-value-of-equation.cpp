#include<iostream>
#include<vector>
using namespace std;

int size = 1e5;
vector<int>seg(size*4);

// Solution() : seg(size*4){}

void set(int i,int l,int r,int index,int value){
    if(index<l || index>r)return;

    if(l==r){
        seg[i] = value;
        return;
    }

    int mid = l+(r-l)/2;
    set(2*i+1,l,mid,index,value);
    set(2*i+2,mid+1,r,index,value);

    seg[i] = max(seg[2*i+1],seg[2*i+2]);
}

int get(int i,int l,int r,int lw,int rw){
    if(rw<l || lw>r)return INT32_MIN;

    if(lw<=l && r<=rw)return seg[i];

    int mid = l+(r-l)/2;
    return max(get(2*i+1,l,mid,lw,rw),get(2*i+2,mid+1,r,lw,rw));
}

int binarySearch(vector<vector<int>>& points,int i,int k){
    int low=i+1,high=points.size()-1,ans=-1,mid;
    
    while(low<=high){
        mid = (low+high)/2;
        if(points[mid][0]-points[i][0]<=k){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}

int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int n=points.size();
    
    for(int i=0 ; i<n ; i++){
        set(0,0,size-1,i,points[i][1]+points[i][0]-points[0][0]);
    }
    
    int ans=INT32_MIN;
    
    for(int i=0 ; i<n ; i++){
        int index = binarySearch(points,i,k);
        if(index!=-1){
            int curr = 0ll+get(0,0,size-1,i+1,index)-(0ll+points[i][0]-points[0][0])+points[i][1];
            ans = max(ans,curr);
        }
    }
    return ans;
}

int main(){
    
}