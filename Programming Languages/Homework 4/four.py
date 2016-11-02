def one ():
    a = 1
    print str(a)
    def two():
        b = 2
        print str(a) + ' ' + str(b)
        def three():
            c = 3
            print str(a) + ' ' + str(b) + ' ' + str(c)
        three()
    two()
one()
