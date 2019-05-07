/* DSU Template Begins */
 
int parent[MAXN]; 
int _rank[MAXN];
 
int find(int x)
{
	if(parent[x] == x)
	{
		return x; 
	}
	return parent[x] = find(parent[x]) ;
}
 
void merge(int x, int y)
{
	int p1 = find(x) ; 
	int p2 = find(y) ; 
	if(p1 == p2) return;
	if(_rank[p1]>_rank[p2]) 
	{
		parent[p2] = p1 ;
	}
	else
	{
		parent[p1] = p2 ;
	}
	if(_rank[p1] == _rank[p2])
	{
		_rank[p2]++;
	}
}
 
void flush(int n) {
	for(int i=1;i<=n;i++){ 
		parent[i] = i;
		_rank[i] = 0;
	}
}
 
/* DSU template ends*/