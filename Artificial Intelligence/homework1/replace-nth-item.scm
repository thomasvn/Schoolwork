; Takes three parameters: an index (position), a list, and a value to substitute 
; into the list. Returns the list, with the item at the specified index replaced 
; with the new value.

(define (replace-nth-item index list val)
    ; base case, return the tail of the list pre-pended with the new value
    (cond ((equal? 1 index) (cons val (cdr list)))
        ; pre-pend new list with original values that were iterated over
        (#t (cons (car list) (replace-nth-item (- index 1) (cdr list) val)))))

(replace-nth-item 4 '(1 2 3 4) 14)
(replace-nth-item 2 '(a b c d e) '(1 2 3))
(replace-nth-item 1 '(((1 2 3) (4 5 6)) b c d) 'a)