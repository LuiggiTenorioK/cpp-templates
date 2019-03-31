#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int visited[100000];
 
void DFS(int u){
    visited[u]++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }
}
 
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]++;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=0;i<adj[s].size();i++){
            int v=adj[s][i];
            if(!visited[v]){
                visited[v]++;
                q.push(v);
            }
        }
    }
}

int main(){
	int numVertices, numAristas;
    cin >> numVertices >> numAristas;
    for(int i= 0; i<numAristas; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited,0,sizeof(visited));
    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            BFS(i);
        }
    }
    memset(visited,0,sizeof(visited));
    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    return 0;
}