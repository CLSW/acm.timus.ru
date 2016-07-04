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
#include <complex>

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

#define pii pair<ll, ll>

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

bool Intersect(pair < ll, ll >  a, pair < ll, ll > b){
    return (min(a.second, b.second) - max(a.first, b.first)) > 0;
}

ll n, last, ans;
pair < ll, ll > rl[maxn];
vector < pair < ll, ll > > vv;

main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld %lld", &rl[i].fi, &rl[i].se);
        if(rl[i].fi > rl[i].se)
            swap(rl[i].fi, rl[i].se);
        swap(rl[i].fi, rl[i].se);
    }
    sort(rl + 1, rl + 1 + n);
    for(ll i = 1; i <= n; ++i)
        swap(rl[i].fi, rl[i].se);
    last = 1;
    vv.pb(rl[1]);
    for(ll i = 2; i <= n; ++i){
        if(!Intersect(rl[i], rl[last]))
            vv.pb(rl[i]), last = i;
    }
    printf("%lld\n", (ll)vv.size());
    for(pair < ll, ll > i : vv)
        printf("%lld %lld\n", i.fi, i.se);
    return 0;
}
