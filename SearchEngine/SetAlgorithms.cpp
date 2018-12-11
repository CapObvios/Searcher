#include "SetAlgorithms.h"

set<int> intersection(const set<int>& s1, const set<int>& s2)
{
	set<int> intersect;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(intersect, intersect.begin()));
	return intersect;
}

void filter(set<int>& s, const set<int>& limiter)
{
	set<int> filtered = intersection(s, limiter);
	s = filtered;
}

void add(set<int>& s1, const set<int>& s2)
{
	for (auto val : s2)
	{
		s1.insert(val);
	}
}

