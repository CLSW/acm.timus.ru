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

int n, k;

main(){
    scanf("%d %d", &n, &k);
    if(k == 0){
        for(int i = 1; i <= n; ++i)
            putchar('0');
        return 0;
    }
    int on = 0;
    for(int i = 1; i <= n; i++){
        int l = k * i / 100;
        if(on + 1 <= l + 2){
            ++on;
            putchar('1');
        }
        else{
            putchar('0');
        }
    }
    return 0;
}
