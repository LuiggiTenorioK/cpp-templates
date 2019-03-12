#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back((x))
#define REP(i,x,y) for(long long (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp(mp((x),(y)),z)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); 
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

typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;

// SIEVE

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1; // add 1 to include upperbound
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
}

// FACTORS

vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (N != 1 && (PF * PF <= N)) {
		while (N % PF == 0) { N /= PF; factors.push_back(PF); }
		PF = primes[++PF_idx]; 
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

int main(){
	sieve(10000000);
	

	return 0;
}

