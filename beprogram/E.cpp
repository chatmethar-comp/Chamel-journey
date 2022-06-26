
#include<bits/stdc++.h>
using namespace std;
pair<int,int> KG[4002][2002];
pair<int,int> FLG[4002][2002];
bool VeryFLG[4002][2002];
queue<tuple<int,int>> PARA;
int main(){
    ios::sync_with_stdio(false);
    int n,m;scanf("%d %d",&n,&m);
    for(int t=0;t<=m*2;t++)KG[t][0] = {0,m};
    for(int i=1;i<=n;i++){
        int a,c;char b,d;scanf("%d %c %d %c",&a,&b,&c,&d);
        for(int t=0;t<=m*2;t++){

            int L = min(a,c);
            int R = max(a,c);
            KG[t][i] = {L+1,R-1};
            if(b=='R'){
                if(a==m){
                    a--;
                    b='L';
                }
                else a++;
            }
            else{
                if(a==0){
                    a++;
                    b = 'R';
                }
                else a--;
            }
            if(d=='R'){
                if(c==m){
                    c--;
                    d='L';
                }
                else c++;
            }
            else{
                if(c==0){
                    c++;
                    d = 'R';
                }
                else c--;
            }
        }
    }
    for(int i=0;i<m*2;i++)for(int j=0;j<=n;j++)FLG[i][j] = {m*2,0};
    FLG[0][0] = {0,m};
    PARA.push({0,0});
    while(not PARA.empty()){
        int now_time,now_level,life_L,life_R;
        tie(now_time,now_level) = PARA.front();
        life_L = FLG[now_time%(m*2)][now_level].first;
        life_R = FLG[now_time%(m*2)][now_level].second;
        PARA.pop();
        printf("In %d sec at level %d = [%d,%d]\n",now_time,now_level,life_L,life_R);
        VeryFLG[now_time%(m*2)][now_level] = false;

        if(now_level == n){
            printf("%d",now_time+1);
            return 0;
        }
        int new_postime = (now_time+1)%(m*2);
        //Go BRR
        int nextL = max(life_L,KG[new_postime][now_level+1].first);
        int nextR = min(life_R,KG[new_postime][now_level+1].second);
        if(nextL <= nextR){

            if(nextL < FLG[new_postime][now_level+1].first || nextR > FLG[new_postime][now_level+1].second){

                FLG[new_postime][now_level+1].first = min(nextL,FLG[new_postime][now_level+1].first);
                FLG[new_postime][now_level+1].second = max(nextR,FLG[new_postime][now_level+1].second);
                if(!VeryFLG[new_postime][now_level+1]){
                    VeryFLG[new_postime][now_level+1] = true;
                    PARA.push({now_time+1,now_level+1});
                }
            }
        }
        //Wait
        nextL = max(life_L,KG[new_postime][now_level].first);
        nextR = min(life_R,KG[new_postime][now_level].second);
        if(nextL <= nextR){

            if(nextL < FLG[new_postime][now_level].first || nextR > FLG[new_postime][now_level].second){

                FLG[new_postime][now_level].first = min(nextL,FLG[new_postime][now_level].first);
                FLG[new_postime][now_level].second = max(nextR,FLG[new_postime][now_level].second);
                if(!VeryFLG[new_postime][now_level]){
                    VeryFLG[new_postime][now_level] = true;
                    PARA.push({now_time+1,now_level});
                }
            }
        }
    }
    //MEOW
    printf("NOT FOUND :(");
    return 0;
}
