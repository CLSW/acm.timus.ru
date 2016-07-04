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

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

int k, p;
int d[(int)1e7 + 2];

main(){
    scanf("%d %d", &k, &p);
    if(k < 2){
        printf("0");
        return 0;
    }
    d[1] = 1 % p;
    for(int i = 2; i <= k; ++i){
        d[i] = d[i - 1] % p;
        if(i % 2 == 0 && i / 2 != i - 1)
            d[i] += d[i / 2], d[i] %= p;
    }
    printf("%d", d[k] % p);
    return 0;
}
