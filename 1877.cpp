
string a, b;

ll toll(string x){
    return atoi(x.c_str());
}

main(){
    cin >> a >> b;
    while(!a.empty() && *a.begin() == '0') a.erase(a.begin());
    while(!b.empty() && *b.begin() == '0') b.erase(b.begin());
    if(toll(a) % 2 == 0 || toll(b) % 2 == 1)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
