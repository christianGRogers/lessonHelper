from parsefunctions import (get_skills, get_weeks_skills)
from generate import get_table
import datetime

def main(name: str, level:str, week: str) -> None:
    """Modify output.html so it contains a lesson plan following..."""
    skill_file = open("skillData.txt")
    week_file = open("weekData.txt")
    level_to_items_to_skills = get_skills(skill_file)
    skills = get_weeks_skills(week_file, level, int(week), level_to_items_to_skills)
    lesson_plan = get_table(name, level, week, skills) # error when level changed
    output = open("output.html", 'w')
    output.write(lesson_plan)
    output.close()
    skill_file.close()
    week_file.close()
    log_file = open("userHistory.txt", 'r')
    data = log_file.read()
    log_file.close()
    print(data+str(datetime.datetime.now()) + " "+name+" "+level+" "+week+"\n")
input_data = open("temp.txt")
data = input_data.readlines()
input_data.close()
main(data[1].strip(), data[0].strip(), data[2].strip())