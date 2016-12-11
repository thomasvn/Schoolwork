(DEFINE (reverse lis)
    (COND
        ((NULL? lis) '())
        (ELSE (APPEND (reverse (CDR lis) () )))
    )
)
