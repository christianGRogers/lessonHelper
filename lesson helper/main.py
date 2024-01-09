from parsefunctions import (get_skills, get_weeks_skills)
from generate import get_table

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
input_data = open("temp.txt")
data = input_data.readlines()
input_data.close()
main(data[1].strip(), data[0].strip(), data[2].strip())