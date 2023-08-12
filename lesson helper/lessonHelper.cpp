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
vector<string> getLevelNames(){
    parseFile newFile = parseFile("levelNames");
    return newFile.getCleanLines();
}
class splitSkills{
private:
    parseFile newSkillSet = parseFile("skillData");
    vector<string> skillsUnsorted= newSkillSet.getCleanLines();
    vector<vector<skill>> sortedSet; 
    vector<string> levelNames = getLevelNames();
    vector<skill> tempLevel;
    skill tempSkill;
public:
    splitSkills(){
        int currentLevel = 0;//by vector position
        int skillItemCounter =0;
        for(int i =0; i<skillsUnsorted.size(); i++){
            if(skillsUnsorted[i] == levelNames[currentLevel]){//skip the first level
                continue;
            }
            //if the current element is a level title increase counter and append set
            if(skillsUnsorted[i] == levelNames[currentLevel+1]){
                currentLevel++;
                sortedSet.push_back(tempLevel);
                tempLevel.clear();
                skillItemCounter = 0;
                continue;
            }

            switch(skillItemCounter){
                case 0: tempSkill.skillNum = stoi(skillsUnsorted[i]);
                case 1: tempSkill.time = skillsUnsorted[i];
                case 2: tempSkill.skillDisc = skillsUnsorted[i];
                case 3: tempSkill.activity = skillsUnsorted[i];
                case 4: tempSkill.materials = skillsUnsorted[i];
            }
            if(skillItemCounter >=4){
                tempLevel.push_back(tempSkill);
                skillItemCounter = 0;
                continue;
            }
            skillItemCounter++;
        }
    }
    void test(){
        cout<<"start"<<endl;
        for(vector v:sortedSet){
            cout<<"=========="<<endl;
            for(skill s: v){
                cout<<s.skillNum<<endl<<s.time<<endl<<s.skillDisc<<endl<<s.activity<<endl<<s.materials<<endl;
            }
        }
    }
};
int main(){

    splitSkills newskills;
    newskills.test();
    //
    return 0;
}