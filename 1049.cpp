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

ll x;
map < ll, ll > cnt;

void Factor(ll x){
    for(ll i = 2; i * i <= x; ++i){
        while(x % i == 0)
            x /= i, ++cnt[i];
    }
    if(x > 1)
        ++cnt[x];
}

main(){
    ll ans = 1;
    for(ll i = 1; i <= 10; ++i){
        scanf("%lld", &x);
        Factor(x);
    }
    for(auto i : cnt)
        ans *= (i.second + 1), ans %= 10;
    printf("%lld", ans);
    return 0;
}
