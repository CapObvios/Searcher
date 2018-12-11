#pragma once

#include <map>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>

using std::string;
using std::set;
using std::map;

template <class T>
class TrieNode {
	friend class Trie;
public:
	TrieNode<T>();
	~TrieNode();

private:
	map<char, TrieNode*> Children;
	T value;
};

template <class T>
class Trie1
{
private:
	TrieNode<T> * root;

	set<int> intersection(const set<int>& s1, const set<int>& s2);
	TrieNode* traverseWord(const string& word, TrieNode* origin);

public:
	TrieDictionary();
	~TrieDictionary();

	void addKeyWord(const string& word, const int& id);
	set<int> getIds(const string& word, TrieNode* origin);
	set<int> getIds(const string& word);
	set<int> getIds(const string& word, const set<int>& limiter);
	void traverseChildren(TrieNode* origin, set<int> * res);
	set<int> getIdsWithChildren(const string& word);	
	set<int> getIdsWithChildren(const string& word, const set<int>& limiter);
};
