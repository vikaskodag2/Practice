#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll n, d, ans, A[1000];

//Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
/*
4 100
11 10 5 50

x = 50
i = 0 => d = 50 / 11 = 5 => x = 55
i = 1 => d = 55 / 10 = 6 => x = 60
i = 2 => d = 60 / 5 = 12 => 60
*/


bool check(ll x) {
    for (int i = 0; i < n; i++) {
        if (x > d) return false;
        ll divi = ceil(x * 1.0 / A[i]);
        if (!(divi * A[i] >= x && divi * A[i] <= d)) return false;
        
        x = divi * A[i];
    }
    return true;
}

ll binarySearch(ll lo, ll hi) {
    while(lo <= hi) {
        ll mid = (hi - lo) / 2 + lo;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin >> n >> d;
        for (ll i = 0; i < n; i++) 
            cin >> A[i];

        ans = binarySearch(A[0], d);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
