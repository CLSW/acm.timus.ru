

ll n, s, x[maxN], s2;

int main(){
    scanf("%lld %lld", &n, &s);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &x[i]);
        s2 += x[i] - 1;
        if(s2 < 0){
            printf("NO");
            return 0;
        }
    }
    s2 = 0;
    for(ll i = n; i >= 1; --i){
        s2 += x[i] - 1;
        if(s2 < 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
