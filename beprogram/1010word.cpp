#include<bits/stdc++.h>
using namespace std;
bool compare(char a, char b)
{
    if(a==b || a==b-97+65 || a==b+97-65)
    {
        return true;
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    char table[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
//            cout << "table " << i << " " << j << endl;
            cin >> table[i][j];
        }
    }


    string s;
    int k;
    cin >> k;
    int ans[k];
    for(int q=0;q<k;q++){
        cin >> s;
        int exist=true;
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(compare(s[index], table[i][j])){
//                    cout << i << " " << j << endl;
                    index++;
//                    cout << s.length() << endl;
                    if(s.length()-1+j<m){
                        exist=true;

                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i][j+index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                        }
                    }
                    if(s.length()-1+i<n){
                        exist = true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i+index][j])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }

                    if(s.length()-1+j<m && s.length()-1+i<n){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i+index][j+index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    if(j-s.length()>=0){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i][j-index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    if(i-s.length()>=0){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i-index][j])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    if(i-s.length()>=0 && j-s.length() >=0){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i-index][j-index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    if(i+s.length()-1<n && j-s.length() >=0){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i+index][j-index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    if(i-s.length()-1>=0 && j+s.length()<m){
                        exist=true;
                        for(index;index<s.length();index++){
                            if(!compare(s[index], table[i-index][j+index])){
                                index=1;
                                exist=false;
                                break;
                            }
                        }
                        if(exist){
                            cout << i << " " << j << endl;
                            break;
                            break;
                        }
                    }
                    index=0;
                }
            }
        }
    }
    return 0;
}
