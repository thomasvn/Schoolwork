(DEFINE (append lis1 lis2)
    (COND
        ((NULL? lis1) lis2)
        (ELSE (CONS (CAR lis1) (append (CDR lis1) lis2)))
    )
)
(append '(1 2 3) '(4 5 6))
