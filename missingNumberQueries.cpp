// Problem #5: Missing Number Queries

// Written by Eugene Hwang

// Score: 100/100

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

bool cmp(const pii& a, const pii& b) { 
    return a.second < b.second; 
} 

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n), cts(n + 1, 0);
    // priority_queue<pii> cnts;
    set<pii> cnts;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        cts[arr[i]]++;
    }

    for (int i = 1; i < n + 1; i++){
        cnts.insert({cts[i], i});
    }

    for (int i = 0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1){
            int prev = arr[b - 1];
            arr[b - 1] = c;
            set<pii>::iterator it;
            it = cnts.find({cts[prev], prev});
            cnts.erase(it);
            cnts.insert({cts[prev] - 1, prev});
            cts[prev]--;
            it = cnts.find({cts[c], c});
            cnts.erase(it);
            cnts.insert({cts[c] + 1, c});
            cts[c]++;
        }
        else {
            pii start = *(cnts.begin());
            if (start.first == 1){
                if (c != n){
                    cout << arr[n - 1] << '\n';
                } else {
                    cout << arr[0] << '\n';
                }
            } else {
                cout << start.second << '\n';
            }
        }
    }

    return 0;
}