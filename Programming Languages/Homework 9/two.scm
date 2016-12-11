(DEFINE (quadratic_roots a b c)
    (LET (
        (term1 (/ (- 0 b)(* 2 a)))
        (term2 (/ (SQRT (- (* b b)(* 4 a c)))(* 2 a)))
        (LIST (+ term1 term2)) (- term1 term2))
    )
)
