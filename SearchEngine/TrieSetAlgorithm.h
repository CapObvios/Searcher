#pragma once
#include "include.h"
#include "Trie.h"
#include "SetAlgorithms.h"

set<int> getIds(const TrieNode<set<int>>& node, const set<int>& limiter = NO_LIMITER);
void childrenIdsRecursive(const TrieNode<set<int>>& node, set<int>& res, const set<int>& limiter = NO_LIMITER);
set<int> getIdsWithChildren(const TrieNode<set<int>>& node, const set<int>& limiter = NO_LIMITER);