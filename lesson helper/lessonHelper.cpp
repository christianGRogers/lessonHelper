#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

struct skill{
    int skillNum;
    string time;
    string skillDisc;
    string activity;
    string materials;
};
vector<string> readFile(string fileName){
    vector<string> lineData;
    string temp;
    ifstream File(fileName +".txt");
    while (getline (File, temp)) {
        lineData.push_back(temp);
    }
    File.close();
    return lineData;
}
class parseFile{
private:
    vector<string> rawLines;
    vector<string> cleanLines;
    bool checkCOMMENT(string input){
        return input[0] == '/' && input[1] == '/';
    }
public:
    parseFile(string fileName){
        rawLines = readFile(fileName);
        for(int i =0; i<rawLines.size(); i++){
            if(checkCOMMENT(rawLines[i])){
                continue;
            }
            cleanLines.push_back(rawLines[i]);
        }
    }
    void test(){
        for(string s: cleanLines)
            cout<<s<<endl;
    }
    vector<string> getCleanLines(){
        return cleanLines;
    }   
};
class splitSkills{
private:
    parseFile newSkillSet = parseFile("skillData");
    vector<string> skillsUnsorted= newSkillSet.getCleanLines();
    vector<vector<skill>> sortedSet; 
public:
    splitSkills(){

    }
};
int main(){

    
    
    string FOO;
    cin>>FOO;
    return 0;
}