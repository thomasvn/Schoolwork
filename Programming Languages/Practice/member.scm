(DEFINE (member x lis)
    (COND
        ((NULL? lis) #F)
        ((EQ? (CAR lis) x) #T)
        (ELSE (member x (CDR lis)))
    )
)
(member 6 '(1 2 3 4 5))
