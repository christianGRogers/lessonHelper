from constants import (SkillType, LEVEL_NAMES)

def get_skills() -> dict[str,dict[int, list[SkillType]]]:
    """Return level to items to some number of skills choosen at random"""