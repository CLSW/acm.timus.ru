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
const ll linf = (int)1e16 + 7;
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;

const int mod = (int)1e9;

const ld eps = ld(1e-11);

ll n, k;
char f;
ll d[31][31];

main(){
    scanf("%lld", &n);
    for(ll i = 0; i <= 30; ++i)
        for(ll j = 0; j <= 30; ++j)
            d[i][j] = inf;
    d[0][1] = 0;
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &k);
        for(ll j = 1; j <= k; ++j){
            ll x, y;
            scanf("%lld", &x);
            while(x){
                scanf("%lld", &y);
                d[i][j] = min(d[i - 1][x] + y, d[i][j]);
                scanf("%lld", &x);
            }
        }
        if(i != n)
            scanf(" %c", &f);
    }
    printf("%lld", *min_element(d[n], d[n] + 31));
    return 0;
}
