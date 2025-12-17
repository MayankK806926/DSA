#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;cin>>n;
        ll cnt = 1;
        while(n > 0){
            ll d = n % 10;
            n /= 10;
            ll mul = 0;
            for(ll i=0;i<=d;++i){
                for(ll j=0;j<=d;++j){
                    if(d-i-j >= 0) mul++;
                }
            }
            cnt *= mul;
        }
        cout<<cnt<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}


// OR 


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll cnt = 1;
        while(n > 0){
            ll d = n % 10;
            n /= 10;
            ll combinations = (d + 1) * (d + 2) / 2;
            cnt *= combinations;
        }
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
