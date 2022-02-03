/*
Vector Pair의 정렬
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair <string, pair <int, int>> a, pair <string, pair <int, int>> b){
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main(void){
	vector<pair <string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>> ("A", make_pair(90, 19961222)));
	v.push_back(pair<string, pair<int, int>> ("B", make_pair(97, 19931222)));
	v.push_back(pair<string, pair<int, int>> ("C", make_pair(95, 19930222)));
	v.push_back(pair<string, pair<int, int>> ("D", make_pair(90, 19921222)));
	v.push_back(pair<string, pair<int, int>> ("E", make_pair(88, 19901222)));

	sort(v.begin(), v.end(), cmp);
	for(int i=0; i< v.size(); i++){
		cout << v[i].first << " ";
	}
	cout << "\n";
	return 0;
}