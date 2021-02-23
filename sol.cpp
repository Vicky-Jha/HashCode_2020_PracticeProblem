#include <bits/stdc++.h>
#include <assert.h>
#define lli long long int
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M,N;
    scanf("%d %d", &M,&N);
	vector<int> slices(N);
    for (int &x : slices)
		scanf("%d", &x);
		
	vector<vector<pair<long long,vector<int>> >> v;
	v.resize(N+1, vector<pair<long long, vector<int>>>(M+1));	
	for (int i = 0; i <= M; ++i)
		v[0][i].first = 0;
	for (int i = 0; i <= N; ++i)
		v[i][0].first = 0;
		
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j){
			if(j >= slices[i-1]){
				if((slices[i-1] + v[i-1][j-slices[i-1]].first) > v[i-1][j].first){
					v[i][j].first = slices[i-1] + v[i-1][j-slices[i-1]].first;
					v[i][j].second = v[i-1][j-slices[i-1]].second;
					v[i][j].second.push_back(i-1);
				}else{
					v[i][j].first = v[i-1][j].first;
					v[i][j].second = v[i-1][j].second;
				}
			}else{
				v[i][j].first = v[i-1][j].first;
				v[i][j].second = v[i-1][j].second;
			}
			
		}
	}
	cout<<v[N][M].second.size()<<endl;
	for (auto x : v[N][M].second)
		cout<<x<<" ";

    return 0;
    assert(false);
}
