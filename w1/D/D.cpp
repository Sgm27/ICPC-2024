#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
int n,st,en,u,d;
int f[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>st>>en>>u>>d;
	memset(f,0x3f,sizeof(f));
	f[st]=0;

	queue<int>q;
	q.push(st);
	while (q.size())
	{
		int v= q.front();
		q.pop();
		if (v+u<=n&&f[v]+1<f[v+u])
		{
			q.push(v+u);
			f[v+u]=f[v]+1;

		}
		if (v-d>=1&&f[v]+1<f[v-d])
		{
			q.push(v-d);
			f[v-d]=f[v]+1;
		}
	}
	if (f[en]>=1e9)
		cout<<-1;
	else
	cout<<f[en];
}
