#include<iostream>
#include<vector>
using namespace std;

int index(char c){
    if(c<='Z')return c-'A';
    return 26+(c-'a');
}

string minWindow(string s, string t) {
    vector<int>v(52,0);
    
    for(int i=0 ; i<t.length() ; i++)v[index(t[i])]++;
    int count=t.length();
    
    int p1=0,ans=s.length()+1,start=0;
    
    for(int i=0 ; i<s.length() ; i++){
        if(v[index(s[i])]>0)count--;
        v[index(s[i])]--;
        
        if(count==0){
            while(p1<i){
                if(v[index(s[p1])]==0)
                    break;
                v[index(s[p1])]++;
                p1++;
            }
            if(i-p1+1<ans){
                ans = i-p1+1;
                start = p1;
            }
        }
        
    }
    if(ans==s.length()+1)return "";
    return s.substr(start,ans);
    
}

int main(){
    
}