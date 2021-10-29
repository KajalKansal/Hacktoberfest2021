#include<bits/stdc++.h>
using namespace std;

 
class Solution {
public:
    void dfs(vector<int>adj[], vector<int>&visited, vector<int>&res, int& i){
        visited[i] = 1;
        res.push_back(i);
        
        vector<int>::iterator itr;
        for(itr = adj[i].begin(); itr!=adj[i].end(); itr++){
            if(visited[*itr]==0){
                dfs(adj, visited, res, *itr);
            }
        }
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> visited(V,0);
	    vector<int> res;
	    
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            dfs(adj, visited, res, i);
	        }
	    }
	    return res;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
