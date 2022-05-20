#include<bits/stdc++.h>
using namespace std;

#define int long long
#define line "\n"
#define pb push_back
#define fi first
#define se second
#define print(v) for(auto it:v) cout << it << " "; cout << line;
#define all(x) (x).begin(), (x).end()

const int mod = 32768;
const int INF = 1e18;

void Rawat26() {
    string str;
    cin >> str;
    int n = str.length();
    vector<pair<int, int>> temp;
    for (int i = 0; i < n - 1; i++) {
        int left = -1, right = -1;
        if (str[i] == str[i + 1]) {
            left = i;
            char ch = str[i];
            while (i < n and str[i] == ch) {
                i++;
            }
            right = i-1;
            temp.push_back({left,right});
        }
    }
    for(auto it : temp){
        str.erase(it.fi,it.se-it.fi+1);
    }
    cout << str << line;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        Rawat26();
    }
}