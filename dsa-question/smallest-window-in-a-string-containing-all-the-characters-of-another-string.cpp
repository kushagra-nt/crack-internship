#include<iostream>
#include<vector>
using namespace std;

string smallestWindow (string s, string p)
{
    int p1=0;
    vector<int>v(26,0);
    
    for(int i=0 ; i<p.length() ; i++)v[p[i]-'a']++;
    int count = p.length();
    
    int ans=1e5+2,start=0;
    
    for(int i; i<s.length() ; i++){
        if(v[s[i]-'a']>0)count--;
        v[s[i]-'a']--;
        
        if(count==0){
            while(p1<i){
                if(v[s[p1]-'a']==0)break;
                v[s[p1]-'a']++;
                p1++;
            }
            if(i-p1+1<ans){
                ans = i-p1+1;
                start = p1;
            }
        }
    }
    if(ans==1e5+2)return "-1";
    return s.substr(start,ans);
}

int main(){

}