//BELLMAN FORD
struct edge
{
	int s;
	int e;
	int t; // costs/ distance/ time
};
vector<edge> list;
void solve(int n)//n = numnodes
{	
	vector<int> costs(n, MAX_INT);
	vector<int> parent(n, -1)
	costs[0] = 0;
	for(int i = 1; i < n; i++) 
	{
		for0( a , list.size()) // for each edge
		{		
			int s = list[a].s;
			int e = list[a].e;
			if (costs[s] + list[a].t < costs[e])
			{
				costs[e] = costs[s] + list[a].t;
				parent[e] = s;
			}			
		}		
	}	
	bool negc = false;
	for0(a, list.size())
	{	
		if (costs[list[a].s] + list[a].t < costs[list[a].e])
			negc = true;
	}	
}

//~KNAPSACK --2 towers problem (using coins)
vector<int> ans(sum/2 +1, 0);
for(int i = 0; i < M; i++)
{			
	if (coins[i] <= sum / 2) //big coins overflow
	{				
		for(int j = sum/2; j >= 0; j--) //backwards important, all writes are j+
		{					
			if (ans[j])
				if (j + coins[i] <= sum/2)
					ans[j + coins[i]]++;			
		}	
		ans[coins[i]]++;			
	}
}
//every entry in ans is a possible subset sum, value irrellevant, so could use bools for larger
//arrays, find the highest ans for the subset closest to 1/2

//FLOYD WARSHALL - remember non neg edges
for0(k, N)
{
	for0(j, N)
	{
		for0(i, N)
		{
			map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}
}

//COIN CHANGE - ans needs to be -1.
int ans[5][8000];
int val[] = {1,5,10,25,50};//coin sizes
int r(int bC, int cents)
{		
	if (bC < 0)return 0;
	if (cents == 0)return 1;
	if (cents < 0)return 0;
	if (ans[bC][cents] != -1) return ans[bC][cents];
	int ret = r(bC -1, cents) + r(bC, cents - val[bC]);
	ans[bC][cents] = ret;
	return ret;
}

//MST 
pair<int, double> temp(0, 0);//int is the node, double for the distance.
q.push(temp);
vector<bool> vis(N, false);//visiteds	
double len = 0; //length of span / lines
int count = 0;	//easier to count that track
while(count != N)
{
	pair<int, double> cur = q.top();
	q.pop();		
	if (vis[cur.first])
		continue;
	count++;	
	vis[cur.first] = true;
	len += cur.second;			
	for0(i, nodes.size()) // THIS ASSUMES CONNECTIONS TO ALL
	{ // CHANGE TO map[cur.first].nodes (maybe)
		if (!vis[i] && cur.first != i)
		{
			temp.first = i;
			temp.second = dist(nodes[cur.first], nodes[i]);
			q.push(temp);
		}
	}
}

//LONGEST COMMON SUBSEQUENCE
int tab[a.size()+1][ b.size()+1];		
for0(i, a.size()+1)
{
	for0(j, b.size()+1)
	{
		if (i==0 || j == 0)
			tab[i][j] = 0;
		else if(a[i-1] == b[j-1])
			tab[i][j] = tab[i-1][j-1] + 1;
		else
			tab[i][j] = max(tab[i-1][j], tab[i][j-1]);			
	}
}
