# Prompt the user for input
k = input('Enter an integer between 1 and 8: ')

def fun1():
    j = 2 * k - 1
    print ('j: ' + str(j))

def fun2():
    j = 3 * k + 1
    print ('j: ' + str(j))

def fun3():
    j = 4 * k - 1
    print ('j: ' + str(j))

def fun4():
    j = k - 2
    print ('j: ' + str(j))

options = {
    1: fun1,
    2: fun1,
    3: fun2,
    4: fun3,
    5: fun2,
    6: fun4,
    7: fun4,
    8: fun4
}

options[k]()
