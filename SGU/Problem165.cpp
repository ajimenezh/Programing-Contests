#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
vector<pii> pos,neg;
int id[6010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	int k = 0;
	for (int i=0; i<n; i++) {
		double t;
		scanf("%lf",&t);
		int p = (int)round(t*1000000);
		if (p>2000000) pos.push_back(make_pair(p-2000000,i));
		else if (p<2000000) neg.push_back(make_pair(p-2000000,i));
		else id[k++] = i;
	}
	
	int sum = 0;
	
	sort(neg.begin(),neg.end());
	sort(pos.begin(),pos.end());
	reverse(pos.begin(),pos.end());
	int i=0, j=0;
	while (true) {
		if (i<pos.size() && abs(sum+pos[i].first)<=100000) {
			id[k++] = pos[i].second;
			sum += pos[i].first;
			i++;
		}
		else if (j<neg.size() && abs(sum+neg[j].first)<=100000) {
			id[k++] = neg[j].second;
			sum += neg[j].first;
			j++;
		}
		else break;
		if (i==pos.size() && j==neg.size()) break;
	}
	
	if (k!=n || sum>100000) cout<<"no"<<endl;
	else {
		cout<<"yes"<<endl;
		for (int i=0; i<k; i++) cout<<id[i]+1<<" ";
	}

    return 0;

}
