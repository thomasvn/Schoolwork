; Takes two integer parameters: a starting and an ending value. Prints all 
; integers between those two number (inclusive).

; ASSUMPTION: All start variables are smaller than or equal to finish variables
(define (count-from start finish)
    ; base case: when start val meets finish val, print then terminate
    (cond ((= start finish) (begin (display finish) (newline)))
        ; print start, and move start closer to finish
        (#t (begin (display start) (newline) (count-from (+ 1 start) finish)))))

(count-from 1 2)
(count-from 14 21)
(count-from 101010 101020)
