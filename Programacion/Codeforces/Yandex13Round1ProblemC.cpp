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

vector<int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while (t--) {
		v.clear();
		int n,k;
		cin>>n>>k;
		int sum = 0;
		for (int i=2; i*i<=n; i++) if (n%i==0) {
			int k = 0;
			while (n%i==0) {
				k++;
				n /= i;
			}
			sum += k;
			v.push_back(k);
		}
		if (n!=1) {
			v.push_back(1);
			sum++;
		}
		bool done = 0;
		if (v.size()==1) {
			if (v[0]%2==k%2 && v[0]>=k) {
				cout<<"YES"<<endl;
				done = 1;
			}
		}
		else {
			if (sum>=k) {
				cout<<"YES"<<endl;
				done = 1;
			}
		}
		//while (true) {
			////for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
			//if (v.size()==k) {
				//cout<<"YES"<<endl;
				//done = 1;
				//break;
			//}
			//if (k>v.size()) break;
			
			//bool f = 0;
			//for (int i=0; i<v.size(); i++) for (int j=i+1; j<v.size(); j++) {
				//int t = v[i]*v[j];
				//if ((int)sqrt((double)t)*(int)sqrt((double)t)!=t) {
					//f = 1;
					//v[i] *= v[j];
					//v.erase(v.begin()+j);
					//i = 100000;
					//break;
				//}
			//}
			//if (!f) {
				//for (int i=0; i<v.size(); i++) for (int j=i+1; j<v.size(); j++) {
					//for (int k=j+1; k<v.size(); k++) {
						//int t = v[i]*v[j]*v[k];
						//if ((int)sqrt((double)t)*(int)sqrt((double)t)!=t) {
							//f = 1;
							//v[i] *= v[j]*v[k];
							//v.erase(v.begin()+j);
							//v.erase(v.begin()+k-1);
							//i = 100000;
							//j = 100000;
							//break;
						//}
					//}
					//if (f) {i = 100000; break;}
				//}
			//}
			//if (!f) break;
		//}
		if (!done) cout<<"NO"<<endl;
	}

    return 0;

}
