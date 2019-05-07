
vector<int> g[MAXN];
vector<int> gRev[MAXN];
bool visited[MAXN];
vector<int> order;
vector<int> component;

void dfs(int root) {
	visited[root] = true;
	for(auto next : g[root]) {
		if(!visited[next]) {
			dfs(next);
		}
	}
	order.pb(root);
}

void dfs2(int root) {
	visited[root] = true;
	component.pb(root);
	for(auto next : gRev[root]) {
		if(!visited[next]) {
			dfs2(next);
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for(int i=1;i<=m;i++) {
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		gRev[y].pb(x);
	}
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			dfs(i);
		}
	}
	mem(visited,false);
	for(int i=order.size()-1;i>=0;--i) {
		if(!visited[order[i]]) {
			dfs2(order[i]);
			for(auto it : component) {
				cout << it << ' ';
			}
			cout << endl;
			component.clear();
		}
	} 
}	