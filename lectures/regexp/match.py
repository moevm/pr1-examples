import re

reg = r'^[A-Z][a-z]+ [A-Z]\.([A-Z].)?$'
s = 'Chayka K.V'

if re.match(reg, s):
    print("match")
else:
    print("no match")
