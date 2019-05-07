// https://e-maxx-eng.appspot.com/graph/lca_binary_lifting.html

/*LCA template starts*/
int l;
int timer = 0;
int tin[MAXN], tout[MAXN];
int up[MAXN][20];
int height[MAXN];

void dfs(int root, int parent) {
	tin[root] = ++timer;
	up[root][0] = parent;
	for(int i=1;i<l;i++) {
		up[root][i] = up[up[root][i-1]][i-1];
	}
	for(auto next : v[root]) {
		if(next != parent) {
			height[next] = height[root] + 1;
			dfs(next, root);
		}
	}
	tout[root] = timer;
}

bool ancestor(int u, int v) {
	return (tin[u] <= tin[v]) && (tout[u] >= tout[v]);
}

int lca(int u, int v) {
	if(ancestor(u,v)) {
		return u;
	}
	else if(ancestor(v,u)) {
		return v;
	}
	for(int i=l;i>=0;--i) {
		if(!ancestor(up[u][i] , v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int kthAncestor(int root, int k) {
	for(int i=l-1;i>=0;--i) {
		if((1<<i) <= k) {
			k -= (1<<i); 
			root = up[root][i];
		}
	}
	return root;
}

//call dfs(root,root)
// set l = 20 usually

/*LCA template ends */