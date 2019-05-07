/*Segment tree template starts*/
ll tree[4*MAXN];

void build(int start, int end , int treeIndex) {
	if(start == end) {
		tree[treeIndex] = a[start];
		return;
	}
	int mid = start + (end-start)/2;
	build(start,mid,2*treeIndex);
	build(mid+1,end,2*treeIndex+1);
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

void clean(int start, int end , int treeIndex) {
	tree[treeIndex] = (end-start+1) - tree[treeIndex];
	if(start!=end) {
		lazy[2*treeIndex] = (lazy[treeIndex] + lazy[2*treeIndex])%2;
		lazy[2*treeIndex+1] = (lazy[treeIndex] + lazy[2*treeIndex+1])%2;
	}
}

void update(int start, int end, int left, int right , int treeIndex) {
	//sometimes lazy propogation could be needed here too (clean operation)
	if(start > end || end < left || start > right ) return;
	if(start >= left && end <= right) {
		tree[treeIndex] = (end-start+1) - tree[treeIndex];
		if(start != end) {
			lazy[2*treeIndex] = (lazy[2*treeIndex] + 1)%2;
			lazy[2*treeIndex + 1] = (lazy[2*treeIndex + 1] + 1)%2;
		}
		return;
	}
	int mid = start + (end - start)/2;
	update(start,mid,left,right,2*treeIndex);
	update(mid+1,end,left,right,2*treeIndex+1);
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

ll query(int start, int end, int left, int right, int treeIndex) {
	if(lazy[treeIndex]!=0) {
		clean(start,end,treeIndex);
		lazy[treeIndex] = 0;
	}
	if(start > end || end < left || start > right ) return 0;
	if(start >= left && end <= right) {
		return tree[treeIndex];
	}
	int mid = start + (end-start)/2;
	return query(start,mid,left,right,2*treeIndex) + query(mid+1,end,left,right,2*treeIndex+1);
}

/*End of segment tree template */


/*ADDITION -> POINT UPDATE*/

void update(int start, int end, int index, int treeIndex, ll value) {
	if(index > end || index < start) {
		return;
	}
	if(start == end) {
		tree[treeIndex] = value;
		return;
	}
	int mid = start + (end - start)/2;
	update(start,mid,index,2*treeIndex,value);
	update(mid+1,end,index,2*treeIndex+1,value);
	tree[treeIndex] = tree[2*treeIndex] ^ tree[2*treeIndex+1];
}