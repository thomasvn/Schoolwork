; Takes three parameters: a percept (a la AgentWorld), an X coordinate, and a 
; Y coordinate. Assuming that the agent is in location 0,0 and is facing north, 
; returns the element in the specified location.

; Helper function to get length of list
(define (list-length lst)
    (if (null? lst)
        0
        (+ 1 (list-length (cdr lst)))))

; Helper function to find the starting index of the percept
(define (get-starting-index list)
    (+ (/ (- (list-length list) 1) 2) 1))

; Helper function to return the nth-item of a list
(define (nth-item index list)
    (cond ((equal? 1 index) (car list))
        (#t (nth-item (- index 1) (cdr list)))))

; This function returns the element in the specified location of the percept
(define (get-location percept x y)
    (nth-item (+ x (get-starting-index (nth-item y percept))) (nth-item y percept)))

(get-location '((empty empty empty)
    (empty (vegetation 2 45) empty empty empty)
    ((vegetation 3 150) empty empty empty empty empty barrier)
    (barrier empty empty empty empty empty empty barrier barrier)
    (barrier barrier empty (vegetation 4 200) empty empty empty
        (vegetation 1 125) barrier barrier barrier)) 
    0 1)

(get-location '((empty empty empty)
    (empty (vegetation 2 45) empty empty empty)
    ((vegetation 3 150) empty empty empty empty empty barrier)
    (barrier empty empty empty empty empty empty barrier barrier)
    (barrier barrier empty (vegetation 4 200) empty empty empty
        (vegetation 1 125) barrier barrier barrier)) 
        -1 2)

(get-location '((empty empty empty)
    (empty (vegetation 2 45) empty empty empty)
    ((vegetation 3 150) empty empty empty empty empty barrier)
    (barrier empty empty empty empty empty empty barrier barrier)
    (barrier barrier empty (vegetation 4 200) empty empty empty
        (vegetation 1 125) barrier barrier barrier))
     3 5)
