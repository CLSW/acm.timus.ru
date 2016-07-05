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

# define int ll

# define f first
# define s second

typedef long long ll;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll llinf = (ll)1e16 + 7;
const ll maxn = (ll)2e5 + 7;

int n, m;
int dp[maxn][3];
vector < pair < pii, int > > g[maxn];

int Status(string x){
    return x == "Licensed" ? 1 : x == "Cracked" ? 2 : 3;
}

main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        dp[i][0] = dp[i][1] = llinf;
    for(int i = 1; i <= m; ++i){
        int x, y, d;
        string s;
        cin >> x >> y >> d >> s;
        g[y].pb(mp(mp(x, d), Status(s)));
    }
    dp[1][1] = 0;
    for(int i = 1; i <= n; ++i){
        for(auto j : g[i]){
            int t = j.s;
            if(t == 1){
                dp[i][1] = min(dp[i][1], dp[j.f.f][1] + j.f.s);
            }
            else if(t == 2){
                dp[i][1] = min(dp[i][1], dp[j.f.f][1] + j.f.s);
                dp[i][0] = min(dp[i][0], min(dp[j.f.f][0], dp[j.f.f][1]) + j.f.s);
            }
            else{
                dp[i][0] = min(dp[i][0], min(dp[j.f.f][1], dp[j.f.f][0]) + j.f.s);
            }
        }
    }
    if(dp[n][1] == llinf && dp[n][0] == llinf){
        cout << "Offline\n";
        return 0;
    }
    cout << "Online\n";
    cout << min(dp[n][1], dp[n][0]);
    return 0;
}
