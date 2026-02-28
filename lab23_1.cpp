#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}
void importDataFromFile(const string& filename,
vector<string> &names,
vector<int> &scores,
vector<char> &grades){
    ifstream file(filename);
    string data;
    
    while(getline(file,data)){
        char name[100];
        const char* text = data.c_str();
        char format[]="%[^:]: %d %d %d";
        int sc1,sc2,sc3;
        sscanf(text,format,name,&sc1,&sc2,&sc3);
        int score=sc1+sc2+sc3;
        char grade=score2grade(score);
        names.push_back(name);
        scores.push_back(score);
        grades.push_back(grade);
        
        
        
        
        
        
    }file.close();




}
void getCommand(string &command, string &key){
    cout<< "Please input your command:\n";
      string line;
    getline(cin, line);

    if (line.empty()) {
        command = "";
        key = "";
        return;
    }

    
    size_t pos = line.find(' ');
    if (pos == string::npos) {
        command = line;
        key = "";
    } else {
        command = line.substr(0, pos);
        key = line.substr(pos + 1);
    }
}





void searchName(vector<string> &names,
vector<int> &scores,
vector<char> &grades,
string key

){  bool found=false;
    cout<<"---------------------------------\n";

    for(size_t i=0;i<names.size();i++){
    if(key==toUpperStr(names[i])){
        cout<<names[i]<<"'s score = "<<scores[i]<<"\n";
        cout<<names[i]<<"'s grade = "<<grades[i];
        found=true;
    }
    
    
}if(found==false){ cout<<"Cannot found.";}
cout<<"\n---------------------------------\n";





}



void searchGrade(
    vector<string> &names,
    vector<int> &scores, 
    vector<char> &grades
    , string key){
    bool found=false;
    cout<<"---------------------------------\n";
 for(size_t i=0;i<names.size();i++){
    if( grades[i] == toupper(key[0])){
        cout<<names[i]<<" ("<<scores[i]<<")\n";
        found=true;
    }

    
    
    
    
    
}
if(found==false){cout<<"Cannot found.\n" ;   }
cout<<"---------------------------------\n";
 



}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand( command, key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}