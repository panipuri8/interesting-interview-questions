ll bit[MAXN];

ll query(int index) {
	index++;
	ll sum = 0;
	while(index > 0) {
		sum += bit[index];
		index = index - (index&(-index)); 
	}
	return sum;
}

void update(int index, int value) {
	index++;
	while(index < MAXN) {
		bit[index] += value;
		index = index + (index&(-index)); 
	}
}

ll query(int left, int right) {
	if(left > right) return 0;
	return query(right) - query(left - 1);
}