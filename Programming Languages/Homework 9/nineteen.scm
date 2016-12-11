(DEFINE (partition compare li)
    (COND
        ((null? l1) '())
        (else (let ((pivot (car l1)))
            (append (append (quicksort (partition (lambda (x) (< x pivot)) l1)))
                (partition (lambda (x) (= x pivot)) l1)
            )
            (quicksort (partition (lambda (x) (> x pivot)) l1))
        ))
    )
)