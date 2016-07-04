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

#define f first
#define s second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int linf = (int)1e16 + 7;
const int maxn = (int)4e5 + 7;

const ld eps = ld(1e-11);

ll a, b, c, cnt;
vector < ll > vv;

main(){
    scanf("%lld %lld %lld", &a, &b, &c);
    vv.pb(a);
    vv.pb(b);
    vv.pb(c);
    while(true){
        ++cnt;
        sort(vv.begin(), vv.end());
        ll ans = LLONG_MAX;
        for(int i = 0; i + 1 < (int)vv.size(); ++i)
            ans = min(ans, vv[i + 1] - vv[i]);
        if(!ans){
            break;
        }
        vv.pb(ans);
    }
    printf("%lld", cnt);
    return 0;
}
