#include "TrieSetAlgorithm.h"

set<int> getIds(const TrieNode<set<int>>& node, const set<int>& limiter)
{
	set<int> res(*node.Data);
	if (limiter.find(NO_LIMITER_CODE) == limiter.end())
		filter(res, limiter);
	return res;
}

void childrenIdsRecursive(const TrieNode<set<int>>& node, set<int>& res, const set<int>& limiter)
{
	add(res, getIds(node, limiter));
	for (auto pair : node.Children)
		childrenIdsRecursive(*pair.second, res, limiter);
}

set<int> getIdsWithChildren(const TrieNode<set<int>>& node, const set<int>& limiter)
{
	set<int> res;
	childrenIdsRecursive(node, res, limiter);
	return res;
}
