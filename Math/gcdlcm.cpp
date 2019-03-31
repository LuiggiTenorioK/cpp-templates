#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)  
 {  
    if(b==0) return a;
   a%=b;
   return gcd(b,a);  
 } 
 
ll lcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }

int main(){
	
	return 0;
}
