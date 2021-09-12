#include <bits/stdc++.h>
using namespace std;
#define int long long

int T;
int x, y;
int idx[2001];
const int MOD = 1e9;
string global_s;

// Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc

struct Coor {
    int e = 0, w = 0, n = 0, s = 0;
};

/*
    get the E,W,N,S count in the substring global_s.substr(start, len)
*/
Coor solve(int start, int len) {
    string s = global_s.substr(start, len);
    Coor cur;
    int mul = 1;
    int i = 0;
    while(i < s.size()) {
        if (isdigit(s[i])) {
            mul = s[i] - '0';
            // local start (i + 2) + start
            int s_start = start + i + 2;
            // index of closing brace - local start(i + 2) - start to get the length
            int s_len = idx[s_start - 1] - i - 2 - start;
            Coor temp = solve(s_start, s_len);
            cur.e += (mul * temp.e) % MOD;
            cur.w += (mul * temp.w) % MOD;
            cur.n += (mul * temp.n) % MOD;
            cur.s += (mul * temp.s) % MOD;
            // place i where the brace closes. i.e local end = global end - start
            i = idx[s_start - 1] - start;
        } else {
            if (s[i] == 'S') cur.s++;
            else if(s[i] == 'E') cur.e++;
            else if(s[i] == 'N') cur.n++;
            else if(s[i] == 'W') cur.w++;
        }
        i++;
    }
    
    return cur;
}

void pre() {
    stack<int> st;
    for (int i = 0; i < global_s.size(); i++) {
        idx[i] = -1;
        if (global_s[i] == '(') {
            st.push(i);
        }
        else if (global_s[i] == ')') {
            int t = st.top();
            st.pop();
            idx[t] = i;
        }
    }
}

int32_t main() {

    cin >> T;
    for (int t = 1; t <= T; t++) {
        x = 1, y = 1;

        cin >> global_s;
        pre();
        Coor ft = solve(0, global_s.size());

        x = (x + ft.e) % MOD;
        x = ((x - ft.w) % MOD + MOD) % MOD;
        y = (y + ft.s) % MOD;
        y = ((y - ft.n) % MOD + MOD) % MOD;
        x == 0 ? x = MOD : x;
        y == 0 ? y = MOD : y;

        cout << "Case #" << t << ": " << x << " " << y << "\n";
    }
}