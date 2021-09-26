#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;

int T;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    #endif

    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, ans, sum, min_sum, a;
        
        cin >> n;
        
        sum = 0;
        ans = 0;
        min_sum = 0;
        unordered_map<int, int> m;
        m[0]++;

        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            min_sum = min(sum, min_sum);

            for (int j = 0; (sum - j * j) >= min_sum; j++) 
                if (m.count(sum - j * j) == 1) ans += m[sum - j * j];
            m[sum]++;
        }

        cout << "Case #" << t + 1 << ": " << ans << "\n";;
    }

    return 0;
}