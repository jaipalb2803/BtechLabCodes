def isPalindrome(str):
    print(len(str))
    if len(str) <= 1:
        return True
    else:
        return str[0] == str[-1] and isPalindrome(str[1:-1])


print(isPalindrome('ABCBA'))
print(isPalindrome('ABCA'))

