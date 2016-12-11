(DEFINE (countzeros list)
    (COND
        ((null? lis) 0)
        ((= (car list) 0) (+ 1 countzeros (cdr list)))
        (ELSE (countzeros (cdr list)))
    )
)
