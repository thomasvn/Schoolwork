(DEFINE (Sum0toN x)
    (COND
        ((= x 0) 0)
        (ELSE (+ x (Sum0toN (- x 1))))
    )
)
(Sum0toN 3)
