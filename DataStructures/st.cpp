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
private: vi st, A;
	int n;
	int left(int p) {return p<<1;}
	int right(int p) {return (p<<1) + 1;}
	
	// Definir operaciones aquí RMQ - RSQ
	int op_min(int p1, int p2){ return min(p1,p2) }
	int op_sum(int p1, int p2) { return p1 + p2; }

	void build(int p, int L, int R){
		if(L == R){
			st[p] = A[L];
		}else{
			build(left (p),  L             , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1,  R         );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = op_sum(p1, p2);
		}
	}

	int query(int p, int L, int R, int i, int j){
		if (i >  R || j <  L) return -1;
		if (L >= i && R <= j) return st[p];
		int p1 = query(left(p) , L              , (L+R) / 2, i, j);
		int p2 = query(right(p), (L+R) / 2 + 1, R          , i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1; 
		return op_sum(p1, p2);
	}

	int update(int p, int L, int R, int idx, int new_value) {
		int i = idx, j = idx;

		if (i > R || j < L)
			return st[p];

		if (L == i && R == j) {
			A[i] = new_value;
			return st[p] = A[L];
		}

		int p1, p2;
		p1 = update(left(p) , L              , (L + R) / 2, idx, new_value);
		p2 = update(right(p), (L + R) / 2 + 1, R          , idx, new_value);

		return st[p] = op_sum(p1, p2);
	}

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	int query(int i, int j) { 
		return query(1, 0, n - 1, i, j); 
	}

	int update(int idx, int new_value){
		return update(1, 0, n - 1, idx, new_value); 
	}
};


int main(){
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
	vi A(arr, arr + 7);                      // copy the contents to a vector
	SegmentTree st(A);

	printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
	printf("              A is {18,17,13,19,15, 11,20}\n");
	printf("rsq(1, 3) = %d\n", st.query(1, 3));             // answer = index 2
	printf("rsq(4, 6) = %d\n", st.query(4, 6));             // answer = index 5
	printf("rsq(3, 4) = %d\n", st.query(3, 4));             // answer = index 4
	printf("rsq(0, 0) = %d\n", st.query(0, 0));             // answer = index 0
	printf("rsq(0, 1) = %d\n", st.query(0, 1));             // answer = index 1
	printf("rsq(0, 6) = %d\n", st.query(0, 6));             // answer = index 5

	printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
	printf("Now, modify A into {18,17,13,19,15,100,20}\n");
	st.update(5, 100);                    // update A[5] from 11 to 100
	printf("These values do not change\n");
	printf("rsq(1, 3) = %d\n", st.query(1, 3));                            // 2
	printf("rsq(3, 4) = %d\n", st.query(3, 4));                            // 4
	printf("rsq(0, 0) = %d\n", st.query(0, 0));                            // 0
	printf("rsq(0, 1) = %d\n", st.query(0, 1));                            // 1
	printf("These values change\n");
	printf("rsq(0, 6) = %d\n", st.query(0, 6));                         // 5->2
	printf("rsq(4, 6) = %d\n", st.query(4, 6));                         // 5->4
	printf("rsq(4, 5) = %d\n", st.query(4, 5)); // 5->

	return 0;

}
