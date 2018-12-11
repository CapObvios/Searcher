#pragma once
#include "include.h"

template <typename T>
class TrieNode
{
public:
	map<char, TrieNode*> Children;
	T* Data;

	TrieNode()
	{
		Data = new T();
	}

	~TrieNode()
	{
		delete Data;
		for (auto pair : Children)
		{
			delete pair.second;
		}
	}
};

template <typename T >
class Trie
{
public:
	TrieNode<T>* root;

	TrieNode<T>* getNode(string word)
	{
		TrieNode<T>* cur = root;
		for (char c : word)
		{
			if (cur == nullptr) break;
			cur = cur->Children[c];
		}
		return cur;
	}

	TrieNode<T>* createPath(string word)
	{
		TrieNode<T>* cur = root;
		for (char c : word)
		{
			if (cur->Children[c] == nullptr)
			{
				cur->Children[c] = new TrieNode<T>();
			}
			cur = cur->Children[c];
		}
		return cur;
	}

	Trie()
	{
		root = new TrieNode<T>();
	}

	~Trie()
	{
		delete root;
	}
};
