(DEFINE (sumList lis)
    (COND
        ((NULL? lis) 0)
        (ELSE (+ (CAR lis) (sumList (CDR lis))))
    )
)
(sumList '(1 2 3))
