class Solution:
    def reverse(self, x: int) -> int:
        #try:
        if len(str(x)) == 0:
            return 0
        if str(x)[0] == '-':
            append = '-'
        else:
            append = ''

        digits = [c for c in str(x)]
        digits = [c for c in digits if c in ['0','1','2','3','4','5','6','7','8','9']]
        reversed_digits = digits[::-1]

        as_string = "".join(reversed_digits)
        if len(reversed_digits) > 9 and as_string >= '2147483648':
            return 0

        integer = int(append + as_string) 
        return integer
        #except:
        #    return 0
        
