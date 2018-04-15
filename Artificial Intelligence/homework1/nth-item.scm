; Takes two parameters: an index (position) and a list. Returns the item in the 
; list corresponding to the index specified.

; ASSUMPTION: The index is not out of bounds given the list
(define (nth-item index list)
    (cond ((equal? 1 index) (car list))  ; base case, index is equal to 0, return
        (#t (nth-item (- index 1) (cdr list)))))  ; decrement the index and get tail of list

(nth-item 4 '(1 2 3 4))
(nth-item 1 '((1 2) (3 4)))
(nth-item 2 '(a b c d e f))