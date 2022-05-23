#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>m;
    int k=0;
    
    for(int i=0 ; i<strs.size() ; i++){
        string j = strs[i];
        sort(strs[i].begin(),strs[i].end());
        
        m[strs[i]].push_back(j);
    }
    
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    
}