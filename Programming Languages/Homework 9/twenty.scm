(DEFINE (doitHelper n doit_)
    (IF (= n 0)
        doit
        (doitHelper (- n 1) (+ n doit))
    )
)

(DEFINE (doit n)
    (doitHelper n 0)
)
