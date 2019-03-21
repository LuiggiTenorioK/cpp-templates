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
#define MAX 1000000009
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii,ull> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;

class SegmentTree {
private: vi st, A, laz;
	int n;
	int left(int p) {return p<<1;}
	int right(int p) {return (p<<1) + 1;}
	
	int op_min(int p1, int p2){ return min(p1,p2); }

	void build(int p, int L, int R){
		if(L == R){
			st[p] = A[L];
		}else{
			build(left (p),  L             , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1,  R         );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = op_min(p1, p2);
		}
	}

	int push(int p, int L, int R){
		st[p] = min(st[p], laz[p]);
		if(L != R){
			laz[left(p)] = min(laz[p],laz[left(p)]);
			laz[right(p)] = min(laz[p],laz[right(p)]);
		}
		laz[p] = 1e9;
	}

	int query(int p, int L, int R, int i, int j){
		if (laz[p]!=1e9) push(p,L,R);
		if (i >  R || j <  L) return 1e9;
		if (L >= i && R <= j) return st[p];
		int p1 = query(left(p) , L              , (L+R) / 2, i, j);
		int p2 = query(right(p), (L+R) / 2 + 1, R          , i, j);
		if (p1 == 1e9) return p2;
		if (p2 == 1e9) return p1; 
		return op_min(p1, p2);
	}

	
	int update(int p, int L, int R, int i, int j, int new_value) {
		if (laz[p]!=1e9) push(p,L,R);

		if (i > R || j < L)
			return st[p];
		
		if( i <= L && R <= j){
			laz[p] = new_value;
			push(p,L,R);
			return st[p];
		}

		
		int p1, p2;
		p1 = update(left(p) , L              , (L + R) / 2, i, j, new_value);
		p2 = update(right(p), (L + R) / 2 + 1, R          , i, j, new_value);
		
		
		return st[p] = op_min(p1, p2);
	}

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 1e9);
		laz.assign(4 * n,1e9);
		build(1, 0, n - 1);
	}

	int query(int i, int j) { 
		return query(1, 0, n - 1, i, j); 
	}

	int update(int i, int j, int new_value){
		return update(1, 0, n - 1, i, j, new_value); 
	}
};



int main(){
	
	return 0;

}
