#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef unordered_map<string, int> WordCount;

struct Greater{
  bool operator()(const pair<int, WordCount::iterator>& lhs,
                  const pair<int, WordCount::iterator>& rhs) const
  {
    return lhs.second->first < rhs.second->first;
  }
};

int main(){
	WordCount counts;
	string word;
	while (cin >> word){
	if(word[0] < 'A' || word[0] > 'Z') break;
    	counts[word]++;
  	}
	typedef vector<pair<int, WordCount::iterator> > FreqList;
	FreqList freq;
	freq.reserve(counts.size());
	for (WordCount::iterator it = counts.begin(); it != counts.end(); ++it)
	    freq.push_back(make_pair(it->second, it));
	
	sort(freq.begin(), freq.end(), Greater());
		cout << freq.size() << '\n';
	for (auto item : freq)
	    cout << item.second->first << " " << item.first << '\n';
	return 0;
}
