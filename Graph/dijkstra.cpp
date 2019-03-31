#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back((x))
#define REP(i,x,y) for(long long (i)=(x);(i)<(y);(i)++)
#define PER(i,x,y) for(long long (i)=(x);(i)>=(y);(i)--)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp(mp((x),(y)),z)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); 
#define trace(x) cout << #x << " = " << x << endl
//#define NDEBUG 1
#define fst first
#define snd second
#define sz(v) ((int)v.size())
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define MAX 100000000 
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii,ull> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;

vector<ii> adj[100000];
int visited[100000], dist[100000];
 
int dijkstra(int s, int t){
	priority_queue< ii, vector<ii>, greater<ii> > pq; 
	pq.push(ii(0, s));
	dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		//if(u == t) break; //Early stop
		for (int j = 0; j < adj[u].size(); j++){
			ii v = adj[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
    		}
		}
	}
	return dist[t];
}

int main(){
	int n,m,s; cin>>n>>m>>s;
	REP(i,0,m){
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back(ii(v, w));  
	}

	REP(i,0,100000) dist[i] = INT_MAX;
	dijkstra(s,n);
	REP(i,0,n) 
		cout<<"SSSP("<<s<<","<<i<<") = "<<dist[i]<<endl;
	return 0;
}
