// Problem #2: MIT(IT)+

// Written by Eugene Hwang

// Score: 100/100

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        char prev = '_';
        string result = "YES";

        for (int i = 0; i < n; i++) {
            if (s[i] != 'M' && s[i] != 'I' && s[i] != 'T'){
                result = "NO";
                break;
            }

            if (i == 0){
                if(s[i] != 'M'){
                    result = "NO";
                    break;
                }
            }

            if (i != 0){
                if(prev == 'M' && s[i] != 'I'){
                    result = "NO";
                    break;
                }
                else if(prev == 'I' && s[i] != 'T'){
                    result = "NO";
                    break;
                }
                else if(prev == 'T' && s[i] == 'T'){
                    result = "NO";
                    break;
                }
            }

            prev = s[i];
        }
        if (s[n - 1] != 'T'){
            result = "NO";
        }

        cout << result << '\n';
    }

    return 0;
}