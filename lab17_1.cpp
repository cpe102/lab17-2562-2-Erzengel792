#include<iostream>
#include<fstream>
#include<string>

#include<cctype>
#include<vector>

using namespace std;

string upper(string s) {
    for(int i = 0 ;i<s.size();i++){
        s[i] = toupper(s[i]);
    }
    return s;
}



int main(){
    vector<string> v_name;
    vector<string> v_grade;
    ifstream data("name_score.txt");
    string text;
    char name[100];
    int num1 ,num2 , num3 , sum ;
    string input;
    while (getline(data,text)){
        sscanf(text.c_str(),"%[^:]:%d %d %d",name,&num1,&num2,&num3);
        v_name.push_back(name);
        sum+= num1+num2+num3;
        if(sum>=80) v_grade.push_back("A");
        else if(sum>=70 && sum<=79) v_grade.push_back("B");
        else if(sum>=60 && sum<=69) v_grade.push_back("C");
        else if(sum>=50 && sum<=59) v_grade.push_back("D");
        else if(sum < 50) v_grade.push_back("F");
        sum = 0;
    }


while(true){
    cout<<"Please input your command :";
    getline(cin , input);
    int idx = input.find_first_of(" ");
    string input1 = upper(input.substr(0, idx));
    string input2 = upper(input.substr(idx+1 , input.size()));
    if(input1.compare("NAME")==0){
        for(int i = 0 ; i < v_name.size();i++){
        if(input2 == upper(v_name[i])){
            cout<< v_name[i] <<"'s grade = "<<v_grade[i]<<'\n';
            break;
            }else if(i == v_name.size()-1){
                cout<<"Cannot found."<<'\n';
            }
        }      
    }
    else if(input1.compare("GRADE")==0){
        for(int i = 0; i< v_grade.size();i++){
            if(input2 == upper(v_grade[i])){
            cout<<v_name[i]<<endl;
            }
        }
    }
    else if(input1.compare("EXIT")==0){
        break;
    }else{
        cout<<"Invalid Command."<<'\n';
    }
}

return 0;
}
