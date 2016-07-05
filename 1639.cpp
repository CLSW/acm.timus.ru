ll n, m;

main(){
    cin >> n >> m;
    if((n * m) % 2 == 0)
        cout << "[:=[first]";
    else
        cout << "[second]=:]";
    return 0;
}
