from constants import (SkillType, LEVEL_NAMES)
from typing import TextIO
import random

#todo functionise this shit
def get_skills(skill_file: TextIO) -> dict[str,dict[int, list[SkillType]]]:
    """Return level to items to some number of skills choosen at random
    
    Preconditions: skill_file is of the outlined format

    eg
    {PS1: {1:SkillType, 2...}...}
    """
    level_to_items_to_skills = {}
    item_to_skills = {}
    level = ""
    skill = SkillType()
    current_skill_atribute = 0
    current_item = 0
    for line in skill_file:
        line = line.strip()
        if line in LEVEL_NAMES:
            if level != "":
                level_to_items_to_skills[level] = item_to_skills
                item_to_skills = {}
            level = line
            continue

        match current_skill_atribute:
            case 0:
                current_item = int(line)
                current_skill_atribute += 1
            case 1:
                skill.time = line
                current_skill_atribute += 1
            case 2:
                skill.skill_desc = line
                current_skill_atribute += 1
            case 3:
                skill.activity = line
                current_skill_atribute += 1
            case 4:
                skill.config = line
                current_skill_atribute += 1
            case 5:
                skill.materials = line
                if current_item in item_to_skills:
                    item_to_skills[current_item].append(skill)
                else:
                    item_to_skills[current_item] = [skill]
                skill = SkillType()
                current_skill_atribute = 0
    level_to_items_to_skills[level] = item_to_skills
    return level_to_items_to_skills


def get_weeks_skills(week_file: TextIO, level: str, week: int, 
                     level_to_items_to_skills: dict[str,dict[int, list[SkillType]]]) -> list[SkillType]:
    """Return a randomised selecton of skills for a given level week"""
    level_to_weeks_to_skills = {}
    weeks_to_skills = {}
    count = 1
    for line in week_file:
        line = line.strip()
        if line in LEVEL_NAMES and count != 1:
            level_temp = LEVEL_NAMES[LEVEL_NAMES.index(line)-1]
            level_to_weeks_to_skills[level_temp] = weeks_to_skills
            weeks_to_skills = {}
            count = 1
            continue
        elif line in LEVEL_NAMES:
            continue
        weeks_to_skills[count] = line.split()
        count += 1
    level_to_weeks_to_skills[line] = weeks_to_skills
    ## functinate
    skills = []
    week_skills = level_to_weeks_to_skills[level][week]
    level_skills = level_to_items_to_skills[level]
    for skill in week_skills:
        skill = int(skill)
        if len(level_skills) > 1:
            skills.append(level_skills[skill][random.randrange(0, len(level_skills[skill]))])
        else:
            skills.extend(level_skills[skill][0])
    return skills