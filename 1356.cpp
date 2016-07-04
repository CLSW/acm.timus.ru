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

inline bool Prime(int x){
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}

int t, n;

main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(Prime(n)){
            printf("%d\n", n);
            continue;
        }
        if(n % 2 == 0){
            int ans = 0;
            for(int i = 2; i <= n; ++i){
                if(Prime(i) && Prime(n - i)){
                    ans = i;
                    break;
                }
            }
            printf("%d %d\n", ans, n - ans);
        }
        else{
            if(Prime(n - 2)){
                printf("%d %d\n", n - 2, 2);
                continue;
            }
            printf("%d ", 3);
            n -= 3;
            int ans = 0;
            for(int i = 2; i <= n; ++i){
                if(Prime(i) && Prime(n - i)){
                    ans = i;
                    break;
                }
            }
            printf("%d %d\n", ans, n - ans);
        }
    }
    return 0;
}
