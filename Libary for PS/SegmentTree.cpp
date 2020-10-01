int arr[N], tree[4*N], lazy[4*N];

void build(int node, int start, int end) {
	if(start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void propagate(int node, int start, int end) {
	if(lazy[node] == -1) return;
	tree[node] += (end - start + 1) * lazy[node];
	if(start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = -1;
}

ll query(int node, int start, int end, int l, int r) {
	propagate(node, start, end);
	if(start > r || end < l)
		return 0;
	if(start >= l && end <= r) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int q1 = query(node * 2, start, mid, l, r);
	int q2 = query(node * 2 + 1,mid + 1, end, l, r);
	return q1 + q2;
}

void update(int node, int start, int end, int l, int r, int val) {
	propagate(node, start, end);
	if(start > r || end < l)
		return;
	if(start >= l && end <= r) {
		lazy[node] = val;
		propagate(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, l, r, val);
	update(node * 2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
