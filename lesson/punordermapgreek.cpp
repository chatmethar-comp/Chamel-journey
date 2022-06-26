#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void freq_individual_word(const string &str)
{
    unordered_map<string, int> wordFreq;

    stringstream ss(str);
    string word;
    while(ss >> word){
        wordFreq[word]++;
    }
    //unordered_map<string, int>:: iterator itr;
    //for(itr=wordFreq.begin();itr!=wordFreq.end();itr++){
    //    cout << itr->first << " " << itr->second << endl;
    //}
    for(auto itr: wordFreq){
        cout << itr.first << " " << itr.second << endl;
    }
}

int main()
{
    string str = "geeks for geeks quiz practice qa for";
    freq_individual_word(str);
}
