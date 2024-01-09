class SkillType:
    time = ""
    skill_desc = ""
    activity = ""
    config = ""
    materials = ""

LEVEL_NAMES = [
    'PS1',
    'PS2',
    'PS3',
    'PS4',
    'PS5',
    'SW1',
    'SW2',
    'SW3',
    'SW4',
    'SW5',
    'SW6'
]

FILE_TOP = """
<!DOCTYPE html>
<html>
<head>
<style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;

    word-wrap: break-word;
    white-space:pre-wrap;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #dddddd;
}
</style>
</head>
<body>
<table><tr><th>Skill</th><th>Time</th><th>Activity</th><th>Materials</th><th>Formation</th></tr>"""
TABLE_ITEM = ["<td>", "</td>"]
TABLE_ROW = ["<tr>", "</tr>"]
FILE_BOTTOM = "</table></body></html>"

FORMATION_TYPES_TO_IMAGE = ['circle', 'line', 'wall line', 'scatered', 'null', 
                   'circle swim short', 'circle swim long']
WEEK_LBL = "week: "
H = ['<h2>', '</h2>']
SPC = " "
def GET_IMG(name: str) -> str:
    """Return image tag for file name"""
    if name == "null":
        return ""
    return "<img src='"+ name +".jpg"+"' alt='config' style='width:40%;height:30%;'>"