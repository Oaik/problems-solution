#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void Bezo() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 2e5 + 5, OO = 0x3f3f3f3f;
int arr[N], cnt = 1;
vector<int> incr;
vector<int> decr;

int main() {
    Bezo();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    for (int k = 1; k < n; ++k) {
        if (arr[k] == arr[k - 1]) cnt++;
        else cnt = 1;
        if (cnt > 2) {
            cout << "NO";
            return 0;
        }
    }
    // first half in ascending
    // order
    for (int i = 0; i < n; i++) {
        if (i>0&&arr[i - 1] == arr[i]) decr.push_back(arr[i]);
        else incr.push_back(arr[i]);
    }


    sort(incr.begin(), incr.end());
    sort(decr.begin(), decr.end(), greater<int>());
    cout << "YES" << endl;
    cout << incr.size() << endl;
    for (auto num : incr) cout << num << " ";
    cout << endl << decr.size() << endl;
    for (auto num : decr) cout << num << " ";

    return 0;
}