#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

void bfs(vector<vector<int> >& edges, int source)
{
	queue<pair<int,int> > q;
	q.push(make_pair(source, 0));
	int heardInDay[5000];
	bool occurs[2500];
	memset(occurs,false,sizeof(occurs));
	memset(heardInDay,0,sizeof(heardInDay));
	while(!q.empty())
	{
		pair<int,int> current = q.front();
		q.pop();

		if(occurs[current.first])
			continue;

		occurs[current.first] = true;

		heardInDay[current.second]++;

		for(int i = 0; i < edges[current.first].size(); ++i)
		{
			q.push(make_pair(edges[current.first][i], current.second+1));
		}
	}

	int max, day;
	max = 0;
	for(int i = 1; i < 5000; ++i)
	{
		if (heardInDay[i] > max){
			max = heardInDay[i];
			day = i;
		}
	}
	if(max == 0) cout<<0<<endl;
	else cout<<max<<" "<<day<<endl;
}

int main()
{
	int e;
	cin>>e;

	vector<vector<int> > friends(e);
	for(int i = 0; i < e; ++i)
	{
		int n;
		cin>>n;
		for(int j = 0; j < n; ++j)
		{
			int in;
			cin>>in;
			friends[i].push_back(in);
		}

	}
	int cases;
	cin>>cases;
	for(int j = 0; j < cases; ++j)
	{
		int source;
		cin>>source;
		bfs(friends, source);
	}
	return 0;
}
