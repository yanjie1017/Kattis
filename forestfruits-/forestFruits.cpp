#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> llp;

#define INF 2000000000000000

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
	ll V, e, c, k, m; cin >> V >> e >> c >> k >> m;
	
	ll u, v, w;
	vector<vector<llp>> AL;
	AL.assign(V+1, vector<llp>());
	vector<ll> dist;
	dist.assign(V+1, INF);
	set<llp> pq;
	
	for(int i=0; i<e; ++i){
		cin >> u >> v >> w;
		AL[u].push_back(make_pair(v, w));
		AL[v].push_back(make_pair(u, w));
	}
	
	dist[1] = 0;
	for(int i=0; i<V+1; ++i){
		pq.insert({dist[i], i});
	}
	
	/*cout << "pq: ";
	for(auto i : pq){
		cout << i.first << " " << i.second << ", ";
	}cout << endl;
	
	cout << "dist: ";
	for(auto i : dist){
		cout << i << " ";
	}cout << endl;*/
	
	while(!pq.empty()){
		llp temp = *pq.begin(); pq.erase(pq.begin());
		//if(temp.first > dist[temp.second]) continue;
		//cout << "temp.first: " << temp.first << " temp.second: " << temp.second << endl;
		
		for(auto it : AL[temp.second]){
			//cout << "it.first: " << it.first << " it.second: " << it.second << endl;
			if(dist[temp.second] + it.second >= dist[it.first]) continue;
			pq.erase(pq.find({dist[it.first], it.first}));
			dist[it.first] = dist[temp.second] + it.second;
			pq.insert({dist[it.first], it.first});
			//cout << "inserted: " << dist[it.first] << " " << it.first << endl;
			
		}
	}
	
	/*for(auto i : dist){
		cout << i << " ";
	}cout << endl;*/
	
	vector<llp> fruit;
	
	int f;
	
	for(int i=0; i<c; ++i){
		cin >> f;
		if(dist[f] != INF) fruit.push_back(make_pair(dist[f], 1));
	}

	
	sort(fruit.begin(), fruit.end());
	/*ll max =0;
	
	for(auto i: fruit){
		cout << i.first << " " << i.second << ", ";
	}cout << endl;
	
	bool found_fruit = true;*/
	
	if(fruit.size()<k){
		cout << "-1" << endl;
		return 0;
	}else{
		cout << 2*fruit[min(m, k)-1].first << endl;
	}
	
	/*for(int i=1; i<m+1 && found_fruit; ++i){
		for(auto &it : fruit){
			if(it.second <= i){
				found_fruit = true;
				it.second += k;
				if(it.first > max) max = it.first;
				break;
			}
			found_fruit = false;
		}
	}
	
	if(found_fruit){
		cout << 2*max << endl;
	}else{
		cout << "-1" << endl;
	}*/
	
	
	return 0;
}
