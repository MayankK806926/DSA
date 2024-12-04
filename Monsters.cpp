/*Monocarp's character has an ability that deals k damage to the monster with the highest current health. If there are several of them, the one with the smaller index is chosen.
If a monster's health becomes less than or equal to 0 after Monocarp uses his ability, then it dies.
Monocarp uses his ability until all monsters die. Your task is to determine the order in which monsters will die.*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            pair<int, int> &x = arr[i];
            cin >> x.first;
            x.first %= k;
            if(x.first) x.first = k-x.first;
            x.second = i+1 ;
        }
        sort(arr.begin(), arr.end());
        for(const pair<int, int> &x:arr){
            cout << x.second << " ";
        }
        cout << endl;
    }
}
