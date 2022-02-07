from fractions import Fraction

tc = int(input())
for i in range(tc):
    index,denom,decim = map(str, input().split())
    index = int(index)
    denom = int(denom)
    decim = float(decim)
    x = Fraction(decim).limit_denominator(denom)
    print(str(index) + " " + str(x.numerator)+"/"+str(x.denominator))
