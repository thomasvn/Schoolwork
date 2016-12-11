(DEFINE (reverse lis)
    (COND
        ((NULL? lis) '())
        (ELSE (APPEND (reverse (CDR lis)) (LIST (CAR lis))))
    )
)
(reverse '(1 2 3 4 5))
