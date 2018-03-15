
#include <bits/stdc++.h>
using namespace std;
 
int cnt[110000][31];
 
int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		for (int j = 0; j < 31; j++) cnt[i][j] = cnt[i-1][j] + (x >> j & 1);
	}
	for(int i = 0; i < n; i++) {
    	for(int j = 0; j < 31; j++)
    		cout << cnt[i][j];
    	cout << "\n";
    }

	// while (q--) {
	// 	int l, r, ans = 0; scanf("%d%d", &l, &r);
	// 	for (int j = 30; j >= 0; j--) ans = ans * 2 + ((cnt[j][r] - cnt[j][l-1]) * 2 < r - l + 1);
	// 	printf("%d\n", ans);
	// }
	return 0;
}