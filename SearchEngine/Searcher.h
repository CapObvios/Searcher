#pragma once
#include "include.h"
#include "Trie.h"
#include "TrieSetAlgorithm.h"

class Searcher
{
private:
	Trie<set<int>>* SearchTree;

	string toLowerCase(string s);

public:
	Searcher();
	~Searcher();

	void addEntry(const string& s, int id);
	set<int> search(const string &str, const set<int> &limiter = NO_LIMITER);
	set<int> search(vector<string> strs);
};

