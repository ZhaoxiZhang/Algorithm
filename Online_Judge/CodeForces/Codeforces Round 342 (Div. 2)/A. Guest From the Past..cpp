#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll judge(ll n, ll a, ll b, const ll c) {
	ll ans = 0;
	if (b - c < a && n >= b) {
		ans = (n - b) / (b - c) + 1;
		n -= (b - c) * ans;
	}
	ans += n / a;
	return ans;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	ll ans = judge(n, a, b, c);
	cout << ans << endl;
	return 0;
}
