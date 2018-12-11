#include "Searcher.h"

string Searcher::toLowerCase(string s)
{
	string ns(s.begin(), s.end());
	std::transform(ns.begin(), ns.end(), ns.begin(), tolower);
	return ns;
}

Searcher::Searcher()
{
	SearchTree = new Trie<set<int>>();
}

Searcher::~Searcher()
{
	delete SearchTree;
}

void Searcher::addEntry(const string &s, int id)
{	
	
	auto node = SearchTree->createPath(toLowerCase(s));
	node->Data->insert(id);
}

set<int> Searcher::search(const string & str, const set<int>& limiter)
{
	auto node = SearchTree->getNode(toLowerCase(str));
	if (node == nullptr) return set<int>();
	auto res = getIdsWithChildren(*node, limiter);
	return res;
}

set<int> Searcher::search(vector<string> strs)
{
	auto limiter = new set<int>({ -1 });
	set<int> res;

	for (int i = 0; i < strs.size() - 1; i++)
	{
		
		auto node = SearchTree->getNode(toLowerCase(strs[i]));
		res = getIds(*node, *limiter);
		*limiter = res;
	}

	res = search(toLowerCase(strs[strs.size() - 1]), *limiter);
	delete limiter;

	return res;
}
