#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, double> umap;
    umap["pi"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    umap.insert(make_pair("e",2.718));

    string key = "pi";
    if(umap.find(key) == umap.end()){
        cout << key << "not found" << endl;
    } else {
        cout << "Found " << key << " is " << umap[key] << endl;
    }

    key = "V";
    if(umap.find(key) == umap.end()){
        cout << key << " not found" << endl;
    } else {
        cout << "Found " << key << " is " << umap[key] << endl;
    }

    unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for(itr = umap.begin();itr!=umap.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "\n" << umap.begin()->first << endl;
    cout << "\nAll Elements : \n";
    for(auto pair:umap){
        cout << pair.first << ": " << pair.second << endl;
    }
}
