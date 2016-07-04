#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

#if __cplusplus >= 201103
    #include <unordered_map>
    #include <future>
    #include <atomic>
    #include <chrono>
    #include <unordered_set>
    #include <array>
    #include <random>
    #include <mutex>
#endif

#define pii pair<int, int>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

inline bool Prime(ll x){
	if(x < 2) return 0;
	for(ll i = 2; i * i <= x; ++i)
		if(x % i == 0) return 0;
	return 1;
}

ll d[(1LL << 21)];
vector < pair < ll, ll > > all;
ll n, m, c, cnt, x;

main(){
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &c), all.pb({(1LL << i), c});
    scanf("%lld", &m);
    for(ll i = 1; i <= m; ++i){
        scanf("%lld %lld", &c, &cnt);
        ll mask = 0;
        for(ll i = 0; i < cnt; ++i){
            scanf("%lld", &x);
            mask |= (1LL << (x - 1));
        }
        all.pb({mask, c});
    }
    ll k, my = 0;
    scanf("%lld", &k);
    for(ll i = 1; i <= k; ++i){
        scanf("%lld", &x);
        my |= (1LL << (x - 1));
    }
    fill(d, d + (1LL << 21), linf);
    d[0] = 0;
    for(ll i = 0; i < (1LL << n); ++i){
        for(auto j : all){
            d[i | j.first] = min(d[i | j.first], d[i] + j.second);
        }
    }
    ll ans = linf;
    for(ll i = 0; i < (1LL << n); ++i){
        if((i & my) >= my)
            ans = min(ans, d[i]);
    }
    printf("%lld", ans);
    return 0;
}
