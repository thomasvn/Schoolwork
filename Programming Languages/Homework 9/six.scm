(DEFINE (max min lis)
    (list (apply max lis)
    (apply min lis))
)
