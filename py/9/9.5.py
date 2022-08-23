def convertToString(n, suffix):

    if n == 0:
        print(n)
        return EMPTY
 
    if n > 19:
        print(n)
        return Z[n // 100] + Y[n // 10 % 10] + X[n % 10] + suffix
    else:
        return X[n] + suffix
 
 

def convert(n):
    result = convertToString((n // 1_000_000_000) % 1000, 'мільярдів ')
 
    result += convertToString((n // 1_000_000) % 1000, 'мільйонів ')
 
    result += convertToString((n // 1000 % 1000), 'тисяч ')
 
    result += convertToString((n % 1000), '')
 
    return result.strip().rstrip(',')
 
 


EMPTY = ''

X = [EMPTY, 'один ', 'два ', 'три ', 'чотири ', 'п\'ять ', 'шість ',
    'сім ', 'вісім ', 'дев\'ять ', 'десять ', 'одинадцять ',
    'дванадцять ', 'тринадцять ', 'чотирнадцять ', 'п\'ятнадцять '
    'шістнадцять ', 'сімнадцять ', 'вісімнадцять ','дев\'ятнадцять ']

Y = [EMPTY, EMPTY, 'двадцять ', 'тридцять ', 'сорок ', 'п\'ятдесят ',
    'шістдесят ', 'сімдесят ', 'вісімдесят ', 'дев\'яносто ']

Z = [EMPTY, 'сто ', 'двісті ', 'триста ', 'чотириста ', 'п\'ятсот ',
    'шістсот ', 'сімсот ', 'вісімсот ', 'дев\'ятсот ']

print(convert(99))
print(convert(1000))
print(convert(14_632))
print(convert(997_751_076))
print(convert(2_147_483_647))