#include<iostream>
#include<vector>
using namespace std;

/*
Question) Given an array of strings, find if the given strings can be chained to form a circle.
          a string x can be put before another string y in a circle if the last character of x
          is same as the first character of y.

    Example-  ["aaa", "bbb" , "baa" , "aab"]
    output - > YES 
    explanation -> cycle 0 -> 3 -> 1 -> 2
*/

int n;

vector<int>ans;

bool dfs(vector<vector<int>>&graph,vector<bool>&visited,int x,int count){
    count--;
    visited[x] = true;
    if(count==0){
        if(graph[x].size() && graph[x][0]==0){
            ans.push_back(x);
            return true;
        }
        return false;
    }

    for(int i=0 ; i<graph[x].size() ; i++){
        if(visited[graph[x][i]])continue;

        if(dfs(graph,visited,graph[x][i],count)){
            ans.push_back(x);
            return true;
        }
    }
    visited[x] = false;

    return false;
}

int main(){
    
    cin>>n;

    vector<string>v(n);

    for(int i=0 ; i<n ; i++)cin>>v[i];

    vector<vector<int>>graph(n,vector<int>());
    vector<bool>visited(n,false);

    vector<vector<int>>nodes(26,vector<int>());

    for(int i=0 ; i<n ; i++)nodes[v[i][0]-'a'].push_back(i);

    for(int i=0 ; i<n ; i++){
        int index = v[i][v[i].length()-1]-'a';
        for(int j=0 ; j<nodes[index].size() ; j++){
            if(i!=nodes[index][j])
            graph[i].push_back(nodes[index][j]);
        }
    }

    if(dfs(graph,visited,0,n)){
        cout<<"YES\n";

        for(int i=ans.size()-1 ; i>=0 ; i--)cout<<ans[i]<<" ";
    }
    else
    cout<<"NO";
    
    return 0;
}