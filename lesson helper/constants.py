class SkillType:
    item = 0
    time = 0
    skill = ""
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
<body>"""

FILE_BOTTOM = "</body></html>"