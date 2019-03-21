#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastExp(int base, int e){
	//Usando exponentes de 2
	ll ans = 1;
	while(e){
		if (e & 1) ans *= base;
		base *= base;
		e >>= 1;
	}
	return ans;
}

int main(){
	int a, b;
	cin >> a >> b;
	ll ans = fastExp(a, b);
	cout << ans << endl;
	return 0;
}
