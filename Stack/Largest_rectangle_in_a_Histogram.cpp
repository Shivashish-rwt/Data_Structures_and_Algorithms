#include<bits/stdc++.h>
using namespace std;

#define int long long
#define line "\n"
#define pb push_back
#define fi first
#define se second
#define print(v) for(auto it:v) cout << it << " "; cout << line;
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;
const int INF = 1e18;

void Rawat26() {
    int n;
    cin >> n;
    vector<int> a(n), temp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    vector<int> next_smaller_right(n), next_smaller_left(n);
    for (int i = n - 1; i >= 0; i--) {
        if (!st.empty()) {
            while (!st.empty() and a[st.top()] >= a[i]) {
                st.pop();
            }
        }
        next_smaller_right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = 0; i < n; i++) {
        if (!st.empty()) {
            while (!st.empty() and a[st.top()] >= a[i]) {
                st.pop();
            }
        }
        next_smaller_left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (next_smaller_right[i] - next_smaller_left[i] - 1) * a[i]);
    }
    cout << ans << line;
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