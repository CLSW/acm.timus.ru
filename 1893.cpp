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
const int maxn = (int)1e5 + 7;
const int lmaxn = (int)2e7 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll n;
char s[123];

main(){
    scanf("%lld%s", &n, s);
    if(n <= 2){
        if(s[0] == 'A' || s[0] == 'D')
            printf("window");
        else
            printf("aisle");
    }
    else if(n <= 20){
        if(s[0] == 'A' || s[0] == 'F')
            printf("window");
        else if(s[0] == 'B' || s[0] == 'C' || s[0] == 'D' || s[0] == 'E')
            printf("aisle");
        else
            printf("neither");
    }
    else{
        if(s[0] == 'A' || s[0] == 'K')
            printf("window");
        else if(s[0] == 'C' || s[0] == 'D' ||  s[0] == 'G' || s[0] == 'H')
            printf("aisle");
        else
            printf("neither");
    }
    return 0;
}
