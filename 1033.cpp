# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)6e5 + 7;
const int lmaxn = (int)1e7 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

int n, ans, u[44][44], w[44][44], cnt;
char a[44][44];

ll valid(ll x, ll y){
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void dfs(int i, int j){
    u[i][j] = 1;
    for(ll c = 0; c < 4; ++c){
        ll cx = i + dx[c];
        ll cy = j + dy[c];
        if(valid(cx, cy) && !u[cx][cy] && a[cx][cy] == '.')
            dfs(cx, cy);
    }
    for(ll c = 0; c < 4; ++c){
        ll cx = i + dx[c];
        ll cy = j + dy[c];
        if(valid(cx, cy) && a[cx][cy] == '#')
            ans += 9;
    }
    for(ll c = 0; c < 4; ++c){
        ll cx = i + dx[c];
        ll cy = j + dy[c];
        if(!valid(cx, cy))
            ++cnt;
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf(" %c", &a[i][j]);

    dfs(1, 1);
    if(!u[n][n])
        dfs(n, n);
    ans += (cnt - 4) * 9;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            ans += w[i][j] * 9;

    printf("%d", ans);

    return 0;
}
