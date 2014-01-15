/*
	[NWERC'10] TELEPHONE NETWORK
	by: Jan Kuipers
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve (vector<int> c) {

	if (c.size() == 1) return vector<int>(1,0);

	int N=c.size();
	vector<int> r(N,0);
	vector<int> u(N,0);
	vector<int> s[2];

	for (int i=0; i<N; i++) r[c[i]]=i;

	for (int i=0; i<N; i++) {
		int x=i;
		while (!u[x]) {
			s[0].push_back(x);
			u[x] = 1;
			x = r[c[x]<N/2 ? c[x]+N/2 : c[x]-N/2];
			s[1].push_back(x);
			u[x] = 1;
			x = x<N/2 ? x+N/2 : x-N/2;
		}
	}

	vector<int> nc[2];
	vector<int> res(N);

	for (int i=0; i<2; i++) {
		nc[i] = vector<int>(N/2);
		for (int j=0; j<N/2; j++)
			nc[i][s[i][j]%(N/2)] = c[s[i][j]]%(N/2);

		vector<int> ri = solve(nc[i]);

		for (int j=0; j<N/2; j++)
			res[s[i][j]] = i*N/2 + ri[s[i][j]%(N/2)];
	}

	return res;
}

int main () {

	int runs;
	cin>>runs;

	while (runs--) {

		int N,M;
		cin>>N>>M;

		vector<int> c(1<<N,-1);
		vector<int> u(1<<N,0);
		vector<int> f(M);

		for (int i=0; i<M; i++) {
			int a,b;
			cin>>a>>b;
			c[a]=b;
			u[b]=1;
			f[i]=a;
		}

		int a=0,b=0;
		while (1) {
			while (a<1<<N && c[a]!=-1) a++;
			if (a==1<<N) break;
			while (u[b]) b++;
			c[a]=b++;
		}

		vector<int> res = solve(c);

		for (int i=0; i<M; i++) {
			if (i>0) cout << " ";
			cout << res[f[i]];
		}
		cout << endl;
	}

	return 0;
}
