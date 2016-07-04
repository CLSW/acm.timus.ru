from sys import stdin
a = stdin.read()
tab = {}
for x in range(256):
    if not chr(x).isalpha():
        tab[x] = 32
a = a.translate(tab)
a = a.split()
tram = a.count('tram')
trol = a.count('trolleybus')
if tram > trol:
    print("Tram driver")
elif trol > tram:
    print('Trolleybus driver')
else:
    print('Bus driver')
