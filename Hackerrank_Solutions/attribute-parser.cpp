#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N,Q;
    cin >> N >> Q;

    vector<string> names,values; 

    string sourceCode[N];
    getline(cin,sourceCode[0]);
    string queries[Q];
    string temp;
    string currentTag;
    for(int i = 0; i < N; i++){
        getline(cin,temp);

        string word;
        bool tagNameFlag = false;
        bool attributeFlag = false;
        bool valueFlag = false;
        for (auto x : temp) 
        { 
            if(x == '"'){
                continue;
            }
            if (x == '<'){
                tagNameFlag = true;
                continue;
            }
            if (x == '>'){

                               if(tagNameFlag){
                    if(word[0] == '/'){
                        if(word.size()-1 == currentTag.size()){
                            currentTag = "";
                            //cout << currentTag << endl; 
                            continue;
                        }
                        word[0] = '.';
                        currentTag = currentTag.substr(0, currentTag.size()-word.size());
                        //cout << currentTag << endl; 
                        word = "";
                        continue;
                    }
                    if (currentTag.size() == 0){
                        currentTag = word;

                    }else{
                        currentTag = currentTag +"."+ word;

                    }
                    
                    tagNameFlag = false;
                    attributeFlag = true;
                    //cout << currentTag << endl; 

                }else{
                    if(word[0] == '='){
                        valueFlag = true;
                        attributeFlag = false;
                        word = "";
                        //cout<< "===" << endl;
                        continue;

                    }
                    if(attributeFlag){
                        //cout<< " ATT : "<<word << endl;
                        word = currentTag + "~" + word;
                        names.push_back(word);

                    }else if(valueFlag){
                        //cout << " VALUE : " << word << endl;
                        values.push_back(word);
                        valueFlag = false;
                        attributeFlag = true;
                    }else{
                        //cout << "HATA"<<endl;
                    }


                }
                //cout << word << endl; 
                word = ""; 

            }
            else if (x == ' ') 
            { 

                if(tagNameFlag){
                    if(word[0] == '/'){
                        if(word.size()-1 == currentTag.size()){
                            currentTag = "";
                            //cout << currentTag << endl; 
                            continue;
                        }
                        word[0] = '.';
                        currentTag = currentTag.substr(0, currentTag.size()-word.size());
                        //cout << currentTag << endl; 
                        word = "";
                        continue;
                    }
                    if (currentTag.size() == 0){
                        currentTag = word;

                    }else{
                        currentTag = currentTag +"."+ word;

                    }
                    
                    tagNameFlag = false;
                    attributeFlag = true;
                    //cout << currentTag << endl; 

                }else{
                    if(word[0] == '='){
                        valueFlag = true;
                        attributeFlag = false;
                        word = "";
                        //cout<< "===" << endl;
                        continue;

                    }
                    if(attributeFlag){
                        ////cout<< " ATT : "<<word << endl;
                        word = currentTag + "~" + word;
                        names.push_back(word);
                    }else if(valueFlag){
                        //cout << " VALUE : " << word << endl;
                        values.push_back(word);
                        valueFlag = false;
                        attributeFlag = true;
                    }else{
                        //cout << "HATA"<<endl;
                    }


                }
                //cout << word << endl; 
                word = ""; 

            }
            else
            { 
                word = word + x; 
            } 
        }

        sourceCode[i] = temp;
    }


    
    bool foundFlag;
    for(int i = 0; i < Q; i++){
        foundFlag = false;
        getline(cin,temp);

        for(int j = 0; j<names.size(); j++){

            if(names[j] == temp){
                foundFlag = true;
                cout << values[j] << endl;
            }

        }

        if(!foundFlag){
            cout << "Not Found!" << endl;
        }

        queries[i] = temp;


    }
    /*
    for(int i = 0; i < N; i++){
        cout << sourceCode[i] << endl;
    }
    for(int i = 0; i < Q; i++){
        cout << queries[i] << endl;
    }



    for(int i = 0; i <names.size(); i++){
        cout << names[i] << " : "<< values[i]<< endl;
    }
    
    */


    return 0;
}
