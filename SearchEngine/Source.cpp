#include <iostream>

#include "Searcher.h"

int main()
{
	Searcher s;

	s.addEntry("Vasya", 0);
	s.addEntry("Pupkin", 0);
	s.addEntry("Keks", 1);
	s.addEntry("Kesha", 1);
	s.addEntry("Keesha", 2);

	vector<string> strs;
	string str;
	int N;
	std::cin >> N;
	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
	{			
		std::cin >> str;
		strs.push_back(str);
	}

	auto res = s.search(strs);
	
	for (int id : res)
	{
		std::cout << id << " ";
	}

	return 0;
}