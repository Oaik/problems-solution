int arr[N], ans[N], tree[N], last[N];

void update(int idx, int val) {
	while(idx < N) {
		tree[idx] += val;
		idx += (idx & (-idx));
	}
}

int query(int idx) {
	int total = 0;
	while(idx) {
		total += tree[idx];
		idx -= (idx & (-idx));
	}
	return total;
}
