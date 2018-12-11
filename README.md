# Searcher

A lingustic, case insensitive search engine to store ids corresponding to keywords and extracting them.

This was implemented with a custom Trie, std::map and std::set data structures. Trie nodes is connected to other nodes via hashset (map) with chars as keys. Set's on on the trienodes contain sets of integers corresponding to ids.

This code is letter case insensitive.

The file to include: Searcher.h. 
Searcher class creates a trie object on instantiation and deletes it on object destruction.

## Main methods:
### void addEntry(const string& s, int id)
This method takes your "word" - path and stores the given id on its end.
Complexity: O(n + k), where n is given "word" length and k being a complexity of insertiong to the std::set (usually log(m) where m is number of elements).

### set\<int> search(const string &str, const set\<int> &limiter = NO_LIMITER)
This method searches for all id's in the node corresponding to the word given (str) and all of the words being continuation of that word.
For example, if you have words "cat" and "caterpillar" and you give a word "cat" as str, it will return you all of the ids corresponding to both keywords.
Limiter, if specified, will limit the output elements to the intersection of the actual result and the limiter. E.g. if your actual result is {1,2,3,4} and the limiter is {2,3,5}, then the output will be just {2,3}. If not specified, nothing will happen.
Complexity: O(n + n*s) = O(n*s), where n is number of all descendants of a node (worst case if root) and s is an average number of number of elements in a set.

### set\<int> search(vector\<string> strs)
Works similarly to the previous method with 3 major differences:
1. It works for a vector of strings (searches for intersection of results for these strings).
3. Has no limiter to specify.
2. For all of the words, except the last one, the results corresponding only to the node (not children) will be used. Then, they will be used as a limiter to the future words. The very last word will be treated as explained in the previous method.
