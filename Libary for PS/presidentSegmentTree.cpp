#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
 
const int N = 8e5 + 9;
 
int arr[N], curIndx = 1;
 
struct seg {
	seg * l, * r;
	ll sum = 0;
	seg() {}
	seg(ll _sum) {
		sum = _sum;
		l = nullptr;
		r = nullptr;
	}
	seg(seg *_l, seg *_r) {
		sum = 0;
		l = _l, r = _r;
		if(_l) sum += _l->sum;
		if(_r) sum += _r->sum;
	}
};
 
seg * root[N];
seg * build(int start, int end) {
	if(start == end)
		return new seg(arr[start]);
	int mid = (start + end) / 2;
	return new seg(build(start, mid), build(mid + 1, end));
}
 
ll query(seg * cur, int start, int end, int l, int r) {
	if(start > r || end < l) return 0;
	if(start >= l && end <= r) return cur->sum;
	int mid = (start + end) / 2;
	ll p1 = query(cur->l, start, mid, l, r);
	ll p2 = query(cur->r, mid + 1, end, l, r);
	return (p1 + p2);
}
 
seg * update(seg * cur, int start, int end, int idx, int val) {
	if(start == end)
		return new seg(val);
	int mid = (start + end) / 2;
	if(idx <= mid)
		return new seg(update(cur->l, start, mid, idx, val), cur->r);
	else
		return new seg(cur->l, update(cur->r,mid + 1, end, idx, val));
}
 
int main() {
#ifdef LOCAL
	freopen("input.in", "rt", stdin);
#endif
	int n, q, t, k, a, x;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	root[curIndx] = build(1, n);
	while(q--) {
		cin >> t >> k;
		if(t == 3) {
			++curIndx;
			root[curIndx] = root[k];
		} else if(t == 2) {
			cin >> a >> x;
			cout << query(root[k], 1, n, a, x) << '\n';
		} else {
			cin >> a >> x;
			root[k] = update(root[k], 1, n, a, x);
		}
	}
	return 0;
}
