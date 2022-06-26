#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    if(n<6){
        cout << "no";
        return 0;
    }
    dp[6]=1;
    dp[9]=1;
    if(n>=20){
        dp[20]=1;
    }
    if(n>=6){
        cout << 6 <<endl;
    }
    if(n>=9){
        cout << 9 << endl;
    }
    for(int i=12;i<=n;i++){
        if(dp[i-6] || dp[i-9]){
            dp[i]=1;
        }
        if(n>20 && dp[i-20] && i>20){
            dp[i]=1;
        }
        if(dp[i]){
            cout << i << endl;
        }
    }
    return 0;
}
////100
//6
//9
//12
//13
//14
//15
//18
//19
//20
//21
//22
//23
//24
//25
//26
//27
//28
//29
//30
//31
//32
//33
//34
//35
//36
//37
//38
//39
//40
//41
//42
//43
//44
//45
//46
//47
//48
//49
//50
//51
//52
//53
//54
//55
//56
//57
//58
//59
//60
//61
//62
//63
//64
//65
//66
//67
//68
//69
//70
//71
//72
//73
//74
//75
//76
//77
//78
//79
//80
//81
//82
//83
//84
//85
//86
//87
//88
//89
//90
//91
//92
//93
//94
//95
//96
//97
//98
//99
////100
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    int n;cin >> n;
//    set<int> s;
//    for(int i=0;i<=n;i+=6){
//        for(int j=0;j<=n;j+=9){
//            for(int k=0;k<=n;k+=20){
//                if(i+j+k <= n && i+j+k != 0) s.insert(i+j+k);
//            }
//        }
//    }
//    if(!s.empty()){
//        for(auto it=s.begin();it!=s.end();it++){
//            cout << *it << "\n";
//        }
//    }
//    else cout << "no";
//    return 0;
//}
