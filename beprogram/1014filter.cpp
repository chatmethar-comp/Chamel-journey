#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    int pos;
    int len;
    int light[w];
    for(int i=0;i<w;i++){
        light[i]=2;
    }
    while(n--){
        cin >> pos >> len;
        for(int i=pos;i<pos+len && i<w;i++){
            light[i]--;
        }
    }
    int hundred=0, fifty=0;
    for(int i=0;i<w;i++){
        if(light[i]==2){
            hundred +=h;
        } else if(light[i]==1){
            fifty +=h;
        }
    }
    cout << hundred << " " << fifty;
    return 0;
}
