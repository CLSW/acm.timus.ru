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

ll n;

main(){
    scanf("%lld", &n);
    if(Prime(n)){
        printf("%lld", n - 1);
        return 0;
    }
    for(ll i = 3; i <= n; ++i){
        if(n % i == 0){
            printf("%lld", i - 1);
            return 0;
        }
    }
    return 0;
}
