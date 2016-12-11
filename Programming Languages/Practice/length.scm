(DEFINE (length lis)
    (COND
        ((NULL? lis) 0)
        (ELSE (+ 1 (length (CDR lis))))
    )
)
(length '(1 2 3 4 5))
