(DEFINE (numZeros lis)
    (COND
        ((NULL? lis) 0)
        ((= (CAR lis) 0) (+ 1 (numZeros (CDR lis))))
        (numZeros (CDR lis))
    )
)
(numZeros '(0 1 2))
