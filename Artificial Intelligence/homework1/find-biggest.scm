; Takes a list comprised of numerical values and returns the largest one

(define (find-biggest list)
    (if (null? (cdr list))  ; check if there is 0 or 1 elements
        (car list)  ; edge case, return empty list or single element
        (if (< (car list) (find-biggest (cdr list)))  ; compare head against all tail elements
            (find-biggest (cdr list))  ; if head is not find-biggest, call the function on the tail
            (car list))))  ; if head is find-biggest, return the head

(find-biggest '(1 2 3 4))
(find-biggest '(4 3 2 1))
(find-biggest '(1 9 14 9 12 11))

; TODO: Empty list??
