from parsefunctions import (get_skills, get_weeks_skills)
from generate import get_table

skill_file = open("skillData.txt")
week_file = open("weekData.txt")
level_to_items_to_skills = get_skills(skill_file)
skills = get_weeks_skills(week_file, "SW6", 6, level_to_items_to_skills)
lesson_plan = get_table("Christian R", "SW6", "6", skills)
output = open("output.html", 'w')
output.write(lesson_plan)
output.close()
skill_file.close()
week_file.close()