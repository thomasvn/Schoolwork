; Takes a list comprised of numerical values and returns the largest one

(define (find-biggest list)
    (if (null? (cdr list))  ; base case, one element left in list
        (car list)
        (if (> (car list) (find-biggest (cdr list)))  ; else, compare head against all tail elements
            (car list)  ; if head is find-biggest, return the head
            (find-biggest (cdr list)))))  ; if head is not find-biggest, call the function on the tail

(find-biggest '(1 2 3 4))
(find-biggest '(4 3 2 1))
(find-biggest '(1 9 14 9 12 11))
