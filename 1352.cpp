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

# define pii pair<int, int>

# define pb push_back
# define eb emplace_back
# define mp make_pair

# define f first
# define s second

typedef long long ll;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld EPS = ld(1e-11);

vector < ll > ans = {
2
,3
,5
,7
,13
,17
,19
,31
,61
,89
,107
,127
,521
,607
,1279
,2203
,2281
,3217
,4253
,4423
,9689
,9941
,11213
,19937
,21701
,23209
,44497
,86243
,110503
,132049
,216091
,756839
,859433
,1257787
,1398269
,2976221
,3021377
,6972593
};

int t;

void Solve(){
    int n;
    scanf("%d", &n);
    printf("%lld\n", ans[n - 1]);
}

int main(){
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
