//Christian Rogers 2023
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
    ifstream File(fileName+".txt");
    while (getline (File, temp)) {
        lineData.push_back(temp);
    }
    File.close();
    return lineData;   
}
void writeFile(string fileName, string fileContents){
    ofstream write(fileName+".html");
    write<<fileContents;
    write.close();
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
                if(i == skillsUnsorted.size()-1){
                    sortedSet.push_back(tempLevel);
                }
                continue;
            }
            skillItemCounter++;
        }
    }
    void test(){
        cout<<"==========test splitSkills"<<endl;
        int i =0;
        for(vector v:sortedSet){
            cout<<"=========="<<i<<endl;
            for(skill s: v){
                cout<<s.skillNum<<endl<<s.time<<endl<<s.skillDisc<<endl<<s.activity<<endl<<s.materials<<endl;
            }
            i++;
        }
    }
    vector<vector<skill>> getSortedSkills(){
        return sortedSet;
    }
};
class splitWeek{
private:
    parseFile newFile = parseFile("weekData");
    vector<string> rawLines = newFile.getCleanLines();
    vector<vector<vector<int>>> sortedSet;
    vector<string> levelNames = getLevelNames();
    vector<vector<int>> levelCorePlanTemp;

    vector<int> parseWeek(string lineDataRaw){
        vector<int> out;
        string FOO;
        for(int i =0; i<lineDataRaw.length(); i++){
            if(lineDataRaw[i] == ' '){
                out.push_back(stoi(FOO));
                FOO = "";
                continue;
            }
            FOO+=lineDataRaw[i];
        }
        out.push_back(stoi(FOO));
        return out;
    }
public:
    splitWeek(){
        int levelPositionCount = 0;
        for(int i =0; i<rawLines.size(); i++){
            if(rawLines[i] == levelNames[levelPositionCount]){
                continue;
            }
            if(rawLines[i] == levelNames[levelPositionCount+1]){
                levelPositionCount++;
                sortedSet.push_back(levelCorePlanTemp);
                levelCorePlanTemp.clear();
                continue;
            }
            levelCorePlanTemp.push_back(parseWeek(rawLines[i]));
            if(i ==rawLines.size()-1){
                sortedSet.push_back(levelCorePlanTemp);
            }
        }
    }
    void test(){
        cout<<"==========test splitWeek";
        int i =0;
        for(vector<vector<int>> v: sortedSet){
            cout<<"=========="<<i<<endl;
            for(vector<int> i: v){
                for(int skill: i){
                    cout<<skill<<"-";
                }
                cout<<endl;
            }
            i++;
        }
    }
    vector<vector<vector<int>>> getSortedWeek(){
        return sortedSet;
    }
};
class lessonPlan{
private:
    vector<string> levelNames = getLevelNames();
    string getTitle(string content){
        const string open = "<h2>";
        const string close ="</h2>";
        return open+content+close;
    }
    string startTable(){
        return "<table>";
    }
    string endTable(){
        return "</table>";
    }
    string addItem(skill newItem){
        return "<tr><td>"+newItem.time+"</td><td>"+newItem.skillDisc+"</td><td>"+newItem.activity+"</td><td>"+newItem.materials+"</td></tr>";
    }
    string getString(string fileName){
        string out;
        for(string s: readFile(fileName)){
            out+=s;
        }
        return out;
    }
    int convertLevelNameToInt(string level){
        for(int i =0; i<levelNames.size();i++){
            if(levelNames[i]==level){
                return i;
            }
        }
        return -1;
    }
    vector<int> weekPlan(int level, int week, vector<vector<vector<int>>> weekData){//return week plan (1 2 3 5 7) given a level and a week
        return weekData[level][week-1];
    }
    skill getSkill(int level, vector<vector<skill>> skillData, int skillNum){
        return skillData[level][skillNum-1];
    }
    string lessonPlanHtml;
public:
    lessonPlan(vector<vector<vector<int>>> weekData, vector<vector<skill>> skillData, string teacherName, string level, int week){
        lessonPlanHtml+=getString("top");
        lessonPlanHtml+=getTitle(level+"  "+teacherName+"  week "+to_string(week));
        lessonPlanHtml+=startTable();
        lessonPlanHtml+=getString("tableTitle");
        vector<int> skillPlan = weekPlan(convertLevelNameToInt(level), week, weekData);
        for(int skillNum: skillPlan){
            lessonPlanHtml+=addItem(getSkill(convertLevelNameToInt(level), skillData, skillNum));
        }
        lessonPlanHtml+=endTable();
        lessonPlanHtml+=getString("base");
        writeFile("output", lessonPlanHtml);
        
    }

};
int main(){
    string lessonLevel, instuctorName, week;
    parseFile commands = parseFile("temp");
    vector<string> newCommands = commands.getCleanLines();
    lessonLevel = newCommands[0];
    instuctorName = newCommands[1];
    week = newCommands[2];
    splitSkills newSkills;
    splitWeek newWeeks;
    lessonPlan newLessonPlan = lessonPlan(newWeeks.getSortedWeek(), newSkills.getSortedSkills(), instuctorName, lessonLevel, stoi(week));
    return 0;
}