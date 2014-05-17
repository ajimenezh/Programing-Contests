#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class DNADeletion {
	public:
	int differentProteins(vector <string> DNASequence, vector <string> codonTable) ;
};

int DNADeletion::differentProteins(vector <string> DNASequence, vector <string> codonTable) {
		
};

//BEGIN CUT HERE
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
		cout << "Testing DNADeletion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397048109;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DNADeletion _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string DNASequence[] = {"ACTG"};
				string codonTable[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"};
				_expected = 4;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}
			case 1:
			{
				string DNASequence[] = {"AAACCC"};
				string codonTable[] = {"AAA thr", "CCC cys"};
				_expected = 3;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}
			case 2:
			{
				string DNASequence[] = {"AAATCCC"};
				string codonTable[] = {"AAA gua","TCC dop","AAT dop","CCC gua"};
				_expected = 5;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}
			case 3:
			{
				string DNASequence[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
				                        "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
				                        "ATGCAG"};
				string codonTable[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
				                       "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
				                       "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
				                       "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
				                       "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
				                       "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"};
				_expected = 455985264;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}
			/*case 4:
			{
				string DNASequence[] = ;
				string codonTable[] = ;
				_expected = ;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string DNASequence[] = ;
				string codonTable[] = ;
				_expected = ;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string DNASequence[] = ;
				string codonTable[] = ;
				_expected = ;
				_received = _obj.differentProteins(vector <string>(DNASequence, DNASequence+sizeof(DNASequence)/sizeof(string)), vector <string>(codonTable, codonTable+sizeof(codonTable)/sizeof(string))); break;
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

//END CUT HERE
