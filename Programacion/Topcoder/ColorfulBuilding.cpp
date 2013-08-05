#line 2 "ColorfulBuilding.cpp"

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

#define mod 1000000009LL
#define MAXN 36*36+10

long long dp[MAXN][MAXN];
long long sum[MAXN];
long long pred[MAXN];
int n;
map<string,int> id;
vector<string> all;
int m;
int color[MAXN];
long long prod[MAXN];


class ColorfulBuilding {
	public:
	int count(vector <string> color1, vector <string> color2, int L) {
		string s1,s2;
		s1 = ""; s2 = "";
		for (int i=0; i<color1.size(); i++) s1 += color1[i];
		for (int i=0; i<color2.size(); i++) s2 += color2[i];
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		n = s1.length();
		for (int i=0; i<n; i++) {
			string tmp = "";
			tmp += s1[i];
			tmp += s2[i];
			all.push_back(tmp);
		}
		sort(all.begin(),all.end());
		for (int i=0; i<n; i++) {
			if (i==0 || all[i]!=all[i-1]) id[all[i]] = m++;
		}
		for (int i=0; i<n; i++) {
			string tmp = "";
			tmp += s1[i];
			tmp += s2[i];
			color[i] = id[tmp];
		}
		dp[1][color[0]] = 1;
		sum[1] = 1;
		for (int i=0; i<m; i++) prod[i] = 1;
		
		for (int i=1; i<n; i++) {
			
			for (int j=1; j<=n; j++) {
				dp[j][color[i]] = (dp[j][color[i]]*prod[color[i]])%mod;
			}
			prod[color[i]] = 1;
			
			for (int j=n; j>=1; j--) {
				sum[j] = (sum[j]*i)%mod;
				sum[j] = (sum[j] + sum[j-1] - dp[j-1][color[i]] + dp[j][color[i]])%mod;
				sum[j] = (sum[j]+mod)%mod;
				
				dp[j][color[i]] = ((i+1)*dp[j][color[i]])%mod;	
				dp[j][color[i]] = (sum[j-1] - dp[j-1][color[i]] + dp[j][color[i]])%mod;	
				dp[j][color[i]] = (dp[j][color[i]]+mod)%mod;
				
			}
			
			for (int j=0; j<m; j++) {
				if (j!=color[i]) {
					prod[j] = (prod[j]*i)%mod;
				}
			}
		}
		
		for (int j=1; j<=n; j++) {
			for (int k=0; k<m; k++) {
				dp[j][k] = (dp[j][k]*prod[k])%mod;
			}
		}	
			
		long long ans = 0;
		for (int k=0; k<m; k++) ans = (ans + dp[L][k])%mod;
		
		return (int)ans;	
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ColorfulBuilding (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375717871;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorfulBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string color1[] = {"aaba"};
				string color2[] = {"aaaa"};
				int L = 3;
				_expected = 6;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 1:
			{
				string color1[] = {"aaba"};
				string color2[] = {"aaba"};
				int L = 4;
				_expected = 0;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 2:
			{
				string color1[] = {"ab", "ba", "a", "aab"};
				string color2[] = {"bb", "ba", "a", "aba"};
				int L = 5;
				_expected = 432;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 3:
			{
				string color1[] = {"xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx"};
				string color2[] = {"xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx"};
				int L = 58;
				_expected = 619787617;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 4:
			{
				string color1[] = {"SJXcabKTWeUXhwxGixFepQaQlFxrAedNAtVP",
				                   "gorBIkcTlOFbLDbFeElYAyAqszQdMbpxSRdE",
				                   "SQVHPehlNtesbJDflyGxMqvgzjXisRnqDcQO",
				                   "pIAEBwbmpPWCooQAujbGXFGLvXxTmExLARkf",
				                   "AFnWyWKVObfxDGCjTxdZaObgwdxlPKtIxaAd",
				                   "uznMpJVNjAofbHJjOrZeSHgSagOCUMGbvkVR",
				                   "LBRrDbTAyKfVnedKiRfzgRzECpcsziqaTwdo",
				                   "JrJHvsEVVGDkNVGqLbpxyLDPloBuNDQKnReI",
				                   "SSYpbjKHSCnQhuyYrVauWDHDyhAoGyecrZMv",
				                   "UdetQfWEUWHHuAxRSdkJOOJSixKpQXpCFZHO",
				                   "KXVsQbuQtIgsULOMsTvPFNUqkBldMTLCipYK",
				                   "hoXConjnDWQkZVtyZlwSedvdVrNWqQhGUClQ",
				                   "TpsvvyoXsXmQpBAGGVDrXCkodoRHQZmpoQDW",
				                   "csiJspzTqeFBRmPgeEtTAzfrfCGlTZqcPuyO",
				                   "vsPDVBJVaJmUAtDdcsKoUkPEbDmAwtZKwjjP",
				                   "MOfoMhMiKIvGQoeIJXHzyClWRtRuKXMqxUAF",
				                   "KyyUCkRBjsYvmPFFEGBqqVhIUdtvIyyLacfu",
				                   "BfuwfSajSlcuTzhMufHSQLudvGEGlyHsEmBD",
				                   "PLpIXZkdyXveTMfSvqnDGKWOZrTBMUIlZrqF",
				                   "dzVMCqrSLbanRJTYpDJNHAOLPSzmvSEPQJYm",
				                   "rAjRkrSjouJyFaCSPPLYSzqDmMoADyWAbobJ",
				                   "eOCBrJNoyFnGpXpxiExXcoOHnVsaEPXhPfLe",
				                   "XMjRksnxWssPEINhdhbiLBSYpCLtwNshFjXS",
				                   "HnnDeUAbuswsgsYQuAaXySLkFYUwFXwYTreM",
				                   "uqLnwOEGbwZZDgAAWEdLRZxFlogDmlhjhgHM",
				                   "NcfaQsgPQfirkYDRFrLQpySmBGfRHumKULZf",
				                   "mOpmmgclsxRzXskEywfryqCRyATNoJwnlHiD",
				                   "AnoKoKAjrasttjNlHCROnvTJMhEHlVPVoVMo",
				                   "yegLyIuRkkENFAjwzDoPLKjgUHHEkfzYDIpo",
				                   "EcxRGGfuaBXUFXkSxctJWOLmmVbvoMkWtTvV",
				                   "nBMkOBHgaltEVzfyGxseGhmBscfGIbxFbqRn",
				                   "GvkEcLtqdOofGtsbWDafVMbNdJxsffKDzSiR",
				                   "jhZQUVzTzalrZcebvyqPWtOUUyniBKTWdyLi",
				                   "ODJLQPMdjDdTlxrfGsNmBfeGYjzeXApqKDhJ",
				                   "vlJkWMzdVQujKdLViQClOrJXMTBkuZEasFgg",
				                   "FAsbuzrLVIgaryqXBfuBRAbReleXSSgEKSvt"};
				string color2[] = {"XAhlUHtfjOpOlQlowWppQcodMGUiqoLobxnD",
				                   "IDzGlKrHiVGdBjZxIcoxjwagbWieKvUwZrjg",
				                   "SkpkTVeIFeoNQzUUgmYAYskKONNZdgXxSiWd",
				                   "rXBGhTmqnvxkmqiutoDzPusDiOUggEFXGCzm",
				                   "fzrxVuTbFXunGbeEavjshmrIRlDorTuISCxn",
				                   "LsvIaxTkOBjcskiekmrKNNFEXqnfMNXLWqqu",
				                   "ekzxGIlbJPVEQPYAbTuMtZKsCiubDXDiBVzU",
				                   "hZuOCJxvBOYENGSFcUiKKAKfCdebutVmnyvB",
				                   "UveNkKRQmHnedrROQOpHJfrHjwcNLUShlDbn",
				                   "ptUkvbaGDryHRkYfHKLkSgVpjWCEcgazyxGK",
				                   "nVPYEqTTJsRPjzjfdOiULhnZPFeNcnbXaQlk",
				                   "IPXBXRhMQIkxpygsgbcRfMuvIcuzUPPHGOWX",
				                   "yWWlNyEyqZSIOXBFAybIuFpVqpvmKRaRFrAE",
				                   "EvBJVtHvKhjrFcmtpdBbFTdTVtXXZQKAglKT",
				                   "bCVjHzUvyINFkxXageZQMzCyNhcifACdJVDh",
				                   "lZITYcDSeIbLweyFtoMAfOQyBNupKlhcNpgo",
				                   "BduslNrJdWOUukYFFidEkMFaghfofpxVgvJd",
				                   "YrJpDZKqdjEPzdLsOQEdkcrBfNHPemXHokCW",
				                   "GjeUKSGjDlgKTyUGNrMQbBLxRUcgrWpkAwOD",
				                   "wgxTcswqdJHaDugNIRMvrhBsdDaJAssVbSRW",
				                   "qmVmqFEpvgGioMXDSFqEoQcDOAaUoGPEovSO",
				                   "KrukPlpfOhawaovCfteTSCIdLMrtImVtiMyQ",
				                   "ykwmxHsKMFzFHwcbyyedLvhZPnaNGqJMMCxd",
				                   "HUNYCXjNLQIFCLLGpCXHBCHLTxLynBxnHFbx",
				                   "uwjzbNbJepVFgMPUXVirxYHzExquBEtPmKju",
				                   "xXAxAbJePyUsVHeLytDvAxBGMRtnvCEiZZqe",
				                   "xMkQoIVxWPXPgaOYmDjTOXiMImVdzojERNxS",
				                   "dwICFwMAmdOIUxyAdXdshasnzwyhfnVWVqZJ",
				                   "etypXNVvSTEQvriGBZdSGmDEHhvpSqkFklCS",
				                   "YkxpFBCRYUueRcKaJUXVdaMoYMYEooPQVMOr",
				                   "DTrexDqclZNKdPuTRFHualJSFziCLPCZjpxo",
				                   "TfEijcAsSJPikkmBSbXMqYHAhPTcpcKVSkIX",
				                   "xKXHYPYMJxFpSbxltDKYuRiTkOLxpQKnXZPs",
				                   "YFYuvuYHfpFJcrLNIdlNfBxRnWdppsdalBkx",
				                   "NFTysBvNFjejdnlhRTclbcfGipNCxpFEOriY",
				                   "thkgVflJYmbUYbIlafNUMGePQWiZyYzYXvUR"};
				int L = 1200;
				_expected = 396065426;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			/*case 5:
			{
				string color1[] = ;
				string color2[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}*/
			/*case 6:
			{
				string color1[] = ;
				string color2[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}*/
			/*case 7:
			{
				string color1[] = ;
				string color2[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
