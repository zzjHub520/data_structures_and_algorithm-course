#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int main() {
    vector<string> commandstr{
            "reset",
            "reset board",
            "board add",
            "board delete",
            "reboot backplane",
            "backplane abort"
    };
    vector<string> execute{
            "reset what",
            "board fault",
            "where to add",
            "no board at all",
            "impossible",
            "install first",
            "unknown command"
    };

//    vector<string> inputstrvec{"reset",
//                               "reset board",
//                               "board add",
//                               "board delet",
//                               "reboot backplane",
//                               "backplane abort"};

    vector<string> inputstrvec;
    string inputtmp;
    while (cin>>inputtmp){
        inputstrvec.emplace_back(inputtmp);
    }

    regex reg_s(R"(\s)");
    vector<pair<int,int>> resultvecp(inputstrvec.size(),make_pair(0,0));
    for (int i=0;i<inputstrvec.size();++i ) {
        smatch m;
        bool found=regex_search(inputstrvec[i],m,reg_s);
        string str=inputstrvec[i];
        if(found){
            int tmpp=m.position();
            str.insert(tmpp,R"(\w*)");
            str.append(R"(\w*)");
            pair<int,int> countp{0,0};
            for(int j=0;j<commandstr.size();++j){
                if(regex_match(commandstr[j],regex(str))){
                    countp.first++;
                    countp.second=j;
                }
            }
            resultvecp[i]=countp;
        } else{
            str.append(R"(\w*)");
            pair<int,int> countp{0,0};
            for(int j=0;j<commandstr.size();++j){
                if(regex_match(commandstr[j],regex(str))){
                    countp.first++;
                    countp.second=j;
                }
            }
            resultvecp[i]=countp;
        }
    }

    for (int i = 0; i < resultvecp.size(); ++i) {
        if(resultvecp[i].first==1){
            cout<<execute[resultvecp[i].second]<<endl;
        } else{
            cout<<execute[6]<<endl;
        }
    }



    return 0;
}





