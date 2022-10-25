#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("Text.txt");

	if (in) {
		string word;
		vector<string> words_vector;
		map<string, int> words_map;
		
		//записываем слова в вектор
		while (!in.eof())
		{
			in >> word;
			words_vector.push_back(word);
		}

		//сортировка вектора
		sort(words_vector.begin(), words_vector.end());

		//подсчёт слов и запись в map
		auto it1 = words_vector.begin();
		auto it2 = it1;
		while (it1 != --words_vector.end())
		{
			int count = 0;
			it2++;
			while(it2 != words_vector.end())
			{				
				if (*it1 == *it2)
				{
					if (it2 == --words_vector.end())
					{
						words_map.insert(make_pair(*it1, count + 2));
						it1 = it2;
						break;
					}
					count++;						
					it2++;					
				}
				else if (count > 0) 
				{
					words_map.insert(make_pair(*it1, count + 1));
					it1 = it2;
					break;
				}
				else {
					it1 = it2;
					break;
				}
			}
		}

		//вывод слов и их количества
		ofstream out("Word_repeat.txt");

		for (auto it = words_map.begin(); it != words_map.end(); it++)
		{
			out << it->first << "\t" << it->second << endl;
			cout << it->first << "\t" << it->second << endl;
		}
		out.close();
		in.close();		
	}
	else cout << "Can't open the file." << endl;
}