#include <iostream>
#include<vector>
#include <algorithm>
#include<string>
#include<map>
#include<sstream>
#include<set>
#include<cstring>

using namespace std;
int main(){
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    map<int,map<string,string>>map1;
    map<string,set<int>>map2;
    int index =0;
    int N;
    cin>>N;
    N++;
    while(N--){
        string S;
        getline(cin,S);
        stringstream ss(S);
        string command;
        ss>>command;

        if(command=="{"){
            index+=1;
        }

        if(command=="}"){
            map1.erase(index);
            index -=1;
        }

        if(command == "TYPEOF"){
            string var;
            ss>>var;
            if(map1[index].find(var)!=map1[index].end()){
                cout<<(map1[index])[var]<<endl;
            }

            else{
                auto location = map2[var].end();
                bool found=false;
                while(location!=map2[var].begin()){
                location--;
                if(map1[*location].find(var)!=map1[*location].end()){
                    cout<<(map1[*location])[var]<<endl;
                    found=true;
                    break;
                }
                }
                if(found==false){
                    cout<<"UNDECLARED"<<endl;
                }
            }
            }

        if(command == "DECLARE"){
            string var;
            ss>>var;
            string type;
            ss>>type;

           if(map1[index].find(var)==map1[index].end()){
                map1[index].insert(make_pair(var,type));
                map2[var].insert(index);
           }
           else{
                cout<<"MULTIPLE DECLARATION"<<endl;
                return 0;
           }
            

        }




    }





    return 0;
}

