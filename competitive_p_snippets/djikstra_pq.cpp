void djikstra(int src) {
    for(int i=1;i<=n;i++) dist[i] = 1e9 * 1e9;
    dist[src] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > q;
    q.push({0,src});
    while(!q.empty()) {
        pii x = q.top();
        q.pop();
        for(auto it : v[x.ss]) {
            if(dist[it.ff] > x.ff + it.ss) {
                dist[it.ff] = x.ff + it.ss;
                q.push({dist[it.ff], it.ff});
            }
        }
    }
}