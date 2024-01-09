from constants import (SkillType, FILE_TOP, FILE_BOTTOM, 
                       TABLE_ITEM, TABLE_ROW, H, WEEK_LBL, 
                       GET_IMG, SPC)

def get_table(name: str, level: str, week: str, skills: list[SkillType]) -> str:
    """Return a fully formed lesson plan given stuff ..."""
    lesson_plan = FILE_TOP + H[0] +name + SPC + level +SPC+ WEEK_LBL + week + H[1]
    for i in range(len(skills)):
        lesson_plan += TABLE_ROW[0]
        lesson_plan += TABLE_ITEM[0] + skills[i].skill_desc + TABLE_ITEM[1]
        lesson_plan += TABLE_ITEM[0] + skills[i].time + TABLE_ITEM[1]
        lesson_plan += TABLE_ITEM[0] + skills[i].activity + TABLE_ITEM[1]
        lesson_plan += TABLE_ITEM[0] + skills[i].materials + TABLE_ITEM[1]
        lesson_plan += TABLE_ITEM[0] + GET_IMG(skills[i].config) + TABLE_ITEM[1]
        lesson_plan += TABLE_ROW[1]
    lesson_plan += FILE_BOTTOM
    return lesson_plan