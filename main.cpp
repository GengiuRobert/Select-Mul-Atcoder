#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k);
    for(int i=0; i < n; i++){
        int x;
        cin >> x;
        v[i%k].push_back(x);
    }
    for(int i=0; i < k; i++)
        sort(v[i].begin(), v[i].end());
    vector<int> v2(n);
    for(int i=0; i < k; i++){
        int pos = i;
        for(auto it : v[i]){
            v2[pos] = it;
            pos += k;
        }
    }
    bool sol = 1;
    for(int i=0; i < n-1; i++)
        sol &= v2[i] <= v2[i+1];
    cout << (sol ? "Yes" : "No") << endl;
    return 0;
}
