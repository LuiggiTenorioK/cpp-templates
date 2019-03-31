#include <bits/stdc++.h>
using namespace std;

int p[100000];
 
int find(int u){
    return (p[u] == u) ? u:(p[u]=find(p[u]));
}
 
void unionFind(int u, int v){
    int pu=find(u), pv=find(v);
    if(pu!=pv) p[pu]=pv;
}
 
int main(){
	
    return 0;
}