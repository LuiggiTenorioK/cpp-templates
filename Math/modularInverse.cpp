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
#define MAX 1000000 
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii,ull> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;

const ll MOD=1e9+9;
ll a,b;

ll mo(ll n){
	return (n%MOD + MOD)%MOD;
}

// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll &x, ll &y) 
{ 
    if(!b){
         x=1;
         y=0;
         return a;
     }
     ll gcd=gcdExtended(b,a%b,x,y);
     ll t=x;
     x=y;
     y=t-(a/b)*x;
     return gcd;
}

// return modular 1/num  
ll NY(ll num){
	ll x,y;
	gcdExtended(num,MOD,x,y);
	return mo(x);
}



int main(){
	cin>>a>>b;
	cout<<"Modular "<<a<<"/"<<b<<" = "<<a*NY(b)<<endl;

	return 0;
}
