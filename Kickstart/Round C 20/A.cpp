#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;

//Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003380d2

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    int T;
    int A[N];
    int n, k, ans = 0, temp;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> k;
        ans = 0;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        temp = 1;
        for (int i = 0; i < n; i++) {
            if (A[i] == k) {
                i++;
                while(i < n) {
                    if (A[i] + 1 == A[i - 1]) 
                        temp++;
                    else {
                        if (temp == k) ans++;
                        temp = 1;
                    }
                    i++;
                }
            }
            
        }
        if (temp == k) ans++;

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}