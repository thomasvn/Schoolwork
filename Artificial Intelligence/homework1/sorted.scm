; Takes a single parameter: a list. Returns a boolean value indicating if that 
; list is in a (numerically) sorted order.

(define (sorted? list)
    (cond ((null? list) #t)  ; base case, list is empty
        ((equal? (length list) 1) #t)  ; base case, list has length 1
        ((> (cadr list) (car list)) (sorted? (cdr list)))  ; check if next item is greater than current item
        (#t #f)))  ; else, this list is not sorted

(sorted? '(1 2 3 4))
(sorted? '(1 64 128))
(sorted? '(1 15 12 19 3))