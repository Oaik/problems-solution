// iota(par, par + N, 0);
// fill(sz, sz + N, 1);


int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(y == x) return;
	if(sz[x] < sz[y]) swap(x, y);
	par[y] = x;
	sz[x] += sz[y];
}
