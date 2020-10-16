vector<int> Log(N);
for (int i = 2; i < N; ++i)
	Log[i] = Log[i / 2] + 1;

for (int j = 0; j < k; ++j) {
	cin >> arr[j];
	sparse[j][0] = arr[j];
}

for (int q = 1; q < LOG; ++q) {
	for (int j = 0; j + (1 << q) <= n; ++j) {
		sparse[j][q] = min(sparse[j][q - 1], sparse[j + (1 << (q-1))][q - 1]);
	}
}


// sum
long long sum = 0;
for (int j = K; j >= 0; j--) {
    if ((1 << j) <= R - L + 1) {
        sum += st[L][j];
        L += 1 << j;
    }
}

// RMQ
int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
