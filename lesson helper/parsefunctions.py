from constants import (SkillType, LEVEL_NAMES, COMMENT, 
                       TIME_C, SKILL_C, ACTIV_C,CONFIG_C, 
                       MAT_C,SKILL_C, SKILL_TYPE_ITEMS, MIN_WEEK, MAX_WEEK)
from typing import TextIO

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
    current_item = SKILL_TYPE_ITEMS
    for line in skill_file:
