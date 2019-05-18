#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int visited[100000],son[100000];
int ans;
 
void DFS(int u){
    visited[u]++; son[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!visited[v]){
            DFS(v);
            son[u]+=son[v];
        }
    }
    ans+=son[u]*(n-son[u]);
}

int main(){
	int numVertices, numAristas;
    cin >> numVertices >> numAristas;
    for(int i= 0; i<numAristas; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans=0;
    DFS(1);
    cout<<ans<<endl;

    return 0;
}