const int len = 500;

struct query {
	int l, r, i;
	bool operator <(const query &q) {
		if(l / len == q.l / len)
			return r < q.r;
		return l / len < q.l / len;
	}
};

void add(int val) {
	val = arr[val];
	if(!freq[val])
		++total;
	++freq[val];
}

void remove(int val) {
	val = arr[val];
	--freq[val];
	if(!freq[val])
		--total;
}

vector<query> vec;
for(int i = 0; i < q; ++i) {
	cin >> l >> r;
	--l, --r;
	vec.push_back({l, r, i});
}
sort(vec.begin(), vec.end());

int curL = 0, curR = -1, idx;
for (int i = 0; i < q; ++i) {
	l = vec[i].l, r = vec[i].r, idx = vec[i].i;
	while(curL > l) {
		--curL;
		add(curL);
	}
	while(curR < r) {
		++curR;
		add(curR);
	}
	while(curL < l) {
		remove(curL);
		++curL;
	}
	while(curR > r) {
		remove(curR);
		--curR;
	}
	ans[idx] = total;
}

