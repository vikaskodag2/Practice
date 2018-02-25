//https://www.codechef.com/FEB18/problems/POINPOLY/

	#include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ld long double 
    #define vi vector<int>
    #define vl vector<ll>
    #define vb vector<bool>
    #define vpi vector<pair <int, int> >
    #define vpl vector<pair<ll, ll> >
    #define pb push_back
    #define mp make_pair
    #define all(p) (p).begin(), (p).end()
    #define ms(s, n) memset(&s, n, sizeof(s))
    #define sp fixed << setprecision
    #define f first
    #define s second
    #define MOD 1e9 + 7
    #define INF 1e12 + 7
    #define N 100005
    #define pii pair<int, int>
 
	struct _point {
  	ll x, y;
  	_point() : x(0), y(0) { }
  	_point( ll a, ll b ) : x(a), y(b) { }
	};
	
	_point hull[N];
	ll n;
	
	ll cross_product( _point a, _point b, _point c ) {
  		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}
 
	bool inside_polygon( _point p ) {
  		ll a = 1, b = n - 1;
  		if( cross_product( hull[0], hull[a], hull[b] ) > 0 ) swap(a, b);
  		if( cross_product( hull[0], hull[a], p ) >= 0 || cross_product( hull[0], hull[b], p ) <= 0 ) return false;
 
  		while( abs(a - b) > 1 ) {
    		ll mid = (a + b)/2;
    		if( cross_product( hull[0], hull[mid], p ) >= 0 ) b = mid;
    		else a = mid;
  		}
  		return cross_product( hull[a], hull[b], p ) < 0;
	}
     
    int main() {
        ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
        clock_t tStart = clock();
     
        ll t;
        cin >> t;
        while(t--) {           
            cin >> n;			
            for(ll i = 0; i < n; i++) {
                cin >> hull[i].x >> hull[i].y;
            }
            ll cnt = n / 10;
            set<pii> pts;
            for(ll i = 1; i < n; i++) {
                _point p1, p2, p3, p4;
                p1.x = hull[i].x, p1.y = hull[i].y + 1;
                p2.x = hull[i].x, p2.y = hull[i].y - 1;
                p3.x = hull[i].x + 1, p3.y = hull[i].y;
                p4.x = hull[i].x - 1, p4.y = hull[i].y;
                if(inside_polygon( p1 ))
                    pts.insert(mp(p1.x, p1.y));
                if(inside_polygon( p2 ))
                    pts.insert(mp(p2.x, p2.y));
                if(inside_polygon( p3 ))
                    pts.insert(mp(p3.x, p3.y));
                if(inside_polygon( p4 ))
                    pts.insert(mp(p4.x, p4.y));
            }
            if(pts.size() < cnt) {
                cout << "-1\n";
            }
            else {
                for(auto i : pts) {
                    cout << i.f << " " << i.s << "\n";
                    cnt--;
                    if(!cnt)
                        break;
                }
            }
        }
     
        cerr << "Execution time : " << sp(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "\n";
        return 0;
    }
