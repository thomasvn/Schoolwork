(DEFINE (equal lis1 lis2)
    (COND

        ((NOT (LIST? lis1)) (EQ? lis1 lis2))
        ((NOT (LIST? lis2)) #F)

        ((NULL? lis1) (NULL? lis2))
        ((NULL? lis2) #F)

        (EQ? (CAR lis1) (CAR lis2)
            (equal (CDR lis1) (CDR lis2))
        )

    )
)

(equal '(1 2 3 4) '(1 2 3))
