import math
class Solution:
    def intToRoman(self, num: int) -> str:
        s = ""

        s += math.floor(num/1000)*'M'
        num -= math.floor(num/1000)*1000

        hundreds = math.floor(num/100)
        s += ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'][hundreds]
        num -= hundreds*100

        tens = math.floor(num/10)
        s += ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'][tens]
        num -= math.floor(num/10)*10

        ones = num
        s += ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'][ones]

        return s
