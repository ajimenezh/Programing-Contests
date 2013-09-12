//Ulm Local 2006
//Problem: Automatic Correction of Misspellings
//
//Solution: Build a tree with the words in the dictionary, and
//			search if the word exists, if it doesn't  BF all swaps, 
//			search the word, and then search words with one modification, 
//			and pick the least index.
//			If index is INF, word is unknown

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

struct node{
	int words;
	int minWord;
	int prefixes;
	node* edges[26];
	node() {
		words = 0;
		prefixes = 0;
		for (int i=0; i<26; i++) 
			edges[i] = NULL;
		minWord = 1000000;
	}
};
int cnt;
node v[15000*26];

void addWord(node *cur, int i,const string &s, int &id) {
	if (i==s.length()) {
		cur->words++;
		cur->minWord = min(cur->minWord, id); 
		return;
	}
	else {
		cur->prefixes++;
		int c = (s[i]-'a'); 
		if (cur->edges[c]==NULL) {
			cur->edges[c] = &v[cnt++];
		}
		addWord(cur->edges[c],i+1,s, id);
	}
}

int countWords(node *cur, int i, const string &s) {
	if (i==s.length()) {
		return cur->words;
	}
	int k = s[i]-'a';
	if (cur->edges[k]==NULL) {
		return 0;
	}
	else {
		return countWords(cur->edges[k],i+1,s);
	}
}

int countPrefixes(node *cur, int i, const string &s) {
	if (i==s.length()) {
		return cur->prefixes;
	}
	int k = s[i]-'a';
	if (cur->edges[k]==NULL) {
		return 0;
	}
	else {
		return countWords(cur->edges[k],i+1,s);
	}
}

int findWord(node *cur, int i, const string &s, bool flag) {
	if (flag) {
		if (i==s.length()) {
			return cur->minWord;
		}
		int k = s[i]-'a';
		if (cur->edges[k]==NULL) {
			return 1000000;
		}
		else {
			return findWord(cur->edges[k],i+1,s,1);
		}
	}
	int k = s[i]-'a';
	int best = 1000000;
	if (cur->edges[k]!=NULL) {
		best = min(best, findWord(cur->edges[k],i+1,s,0));
	}
	for (int j=0; j<26; j++) {
		if (cur->edges[j]!=NULL) {
			best = min(best, findWord(cur->edges[j],i,s,1));
			best = min(best, findWord(cur->edges[j],i+1,s,1));
		}
	}
	if (i<s.length()-1) {
		k = s[i+1]-'a';
		if (cur->edges[k]!=NULL) {
			best = min(best, findWord(cur->edges[k],i+2,s,1));
		}
	}
	else best = min(best, cur->minWord);
	return best;
}


int n,q;
node root;
string all[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    

	cin>>n;
	for (int i=0; i<n; i++) {
		string s;
		cin>>s; 
		addWord(&root,0,s,i); 
		all[i] = s;
	} 
	
	cin>>q;
	for (int i=0; i<q; i++) {
		string s;
		cin>>s;
		
		if (countWords(&root,0,s)>0) {
			printf("%s is correct\n",s.c_str());
		}
		else {
			int k = findWord(&root,0,s,0);
			for (int j=0; j<s.length()-1; j++) {
				swap(s[j],s[j+1]);
				k = min(k, findWord(&root,0,s,1));
				swap(s[j],s[j+1]);
			}
			if (k<n) {
				printf("%s is a misspelling of %s\n",s.c_str(),all[k].c_str());
			}
			else printf("%s is unknown\n",s.c_str());
		}
	}
			
    return 0;

}
