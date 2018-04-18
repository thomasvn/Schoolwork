; For this assignment, you will be implementing an algorithm that will sort a 
; list of locations on a map into order using only swap operations, so that 
; they form a continuous path through adjacent locations.

; Initial State: ordered list of locations
; Goal State: list of locations where any two locations adjacent to each other 
;               in the list are adjacent to each other in the map

; Transition Model: Each state may be transmuted to another state by switching 
;                       two locations.

; Cost Model: The goal of your search is to find a solution that requires the 
;               fewest number of swaps.


; ------------------------- Helper Functions -------------------------
; This function returns the nth item of a list
(define (nth-item index list)
    ; base case, index is equal to 0, return
    (cond ((equal? 1 index) (car list))
        ; decrement the index and get tail of list
        (#t (nth-item (- index 1) (cdr list)))))


; This function replaces the nth item of a list with another value
(define (replace-nth-item index list val)
    ; base case, return the tail of the list pre-pended with the new value
    (cond ((equal? 1 index) (cons val (cdr list)))
        ; pre-pend new list with original values that were iterated over
        (#t (cons (car list) (replace-nth-item (- index 1) (cdr list) val)))))

; This function swaps two elements in a list when passed their indices
(define (swap-elements i j lst)
    ; Temp variable to hold i
    (let ((temp (nth-item i lst)))
        ; Assign i=j then assign j=temp
        (replace-nth-item j (replace-nth-item i lst (nth-item j lst)) temp)
    )
)


; ------------------------------ Main Function ------------------------------
; This function implements an iterative-deepening depth first search to reach
; our goal state. 
; 
; If goal state cannot be reached, the function will output #f.
; If the goal state is reached the first return item will be the original list 
; of locations sorted into a valid solution state. The second return item will 
; be a list of pairs indicating which items need to be swapped in order to reach 
; the solution state.
; (define (id-dfs locations)
;     body)


; State Representation
; ((Alabama Mississippi Florida) ((1 2) (2 3)))


; (id-dfs '(Tennessee Iowa Kentucky North-Carolina Missouri))
; ; $1 = ((North-Carolina Tennessee Kentucky Missouri Iowa) ((1 2) (1 4) (4 5)))
; (id-dfs '(California))
; ; $2 = ((California) ())
; (id-dfs '(Arizona Alaska))
; ; $3 = #f