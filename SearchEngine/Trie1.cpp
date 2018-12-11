//#include "Trie.h"

set<int> TrieDictionary::intersection(const set<int>& s1, const set<int>& s2)
{
	set<int> intersect;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.begin(), std::inserter(intersect, intersect.begin()));
	return intersect;
}

TrieNode * TrieDictionary::traverseWord(const string & word, TrieNode * origin)
{
	TrieNode *cur = origin;
	for (char c : word)
	{
		cur = cur->Children[c];
	}
	return cur;
}

void TrieDictionary::addKeyWord(const string & word, const int & id)
{
	TrieNode *cur = root;
	for (char c : word)
	{
		cur = cur->Children[c];
	}
	cur->Ids->insert(id);
}


set<int> TrieDictionary::getIds(const string & word, TrieNode * origin)
{
	TrieNode* cur = traverseWord(word, origin);	
	return set<int>(*cur->Ids);
}

set<int> TrieDictionary::getIds(const string & word)
{
	return getIds(word, root);
}

set<int> TrieDictionary::getIds(const string & word, const set<int>& limiter)
{
	return intersection(getIds(word), limiter);
}

void TrieDictionary::traverseChildren(TrieNode * origin, set<int> * res)
{
	res->insert(origin->Ids->begin(), origin->Ids->end());
	
	for (auto pair : origin->Children)
	{
		traverseChildren(pair.second, res);
	}
}

set<int> TrieDictionary::getIdsWithChildren(const string & word)
{
	TrieNode* cur = traverseWord(word, root);	
	set<int> res;
	traverseChildren(cur, &res);
	return res;
}

set<int> TrieDictionary::getIdsWithChildren(const string & word, const set<int>& limiter)
{
	return intersection(getIdsWithChildren(word), limiter);
}