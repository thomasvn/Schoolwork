; Takes two parameters: an action and a state. Returns the updated state that 
; will result by following that action. 
; 
; A state is a list of three elements: an X position, a Y position, and a 
; direction (N, S, E, or W). 
; 
; An action is one of the following strings: STAY, MOVE-1, MOVE-2, MOVE-3,
; TURN-LEFT, TURN-RIGHT, or TURN-AROUND. 
; 
; Assume that all moves are forward, relative to the current direction.

(define (nth-item index list)
    (cond ((equal? 1 index) (car list))
        (#t (nth-item (- index 1) (cdr list)))))

(define (replace-nth-item index list val)
    (cond ((equal? 1 index) (cons val (cdr list)))
        (#t (cons (car list) (replace-nth-item (- index 1) (cdr list) val)))))

(define (apply-action state action)
    (cond ((equal? action "STAY") state)
        ; If the action tells us to MOVE-1, increment or decrement the respective coordinate
        ((equal? action "MOVE-1") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 2 state (+ (nth-item 2 state) 1)))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 2 state (- (nth-item 2 state) 1)))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 1 state (+ (nth-item 1 state) 1)))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 1 state (- (nth-item 1 state) 1)))))
        ; If the action tells us to MOVE-2, increment or decrement by 2 to the respective coordinate
        ((equal? action "MOVE-2") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 2 state (+ (nth-item 2 state) 2)))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 2 state (- (nth-item 2 state) 2)))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 1 state (+ (nth-item 1 state) 2)))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 1 state (- (nth-item 1 state) 2)))))
        ; If the action tells us to MOVE-3, increment or decrement by 3 to the respective coordinate
        ((equal? action "MOVE-3") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 2 state (+ (nth-item 2 state) 3)))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 2 state (- (nth-item 2 state) 3)))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 1 state (+ (nth-item 1 state) 3)))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 1 state (- (nth-item 1 state) 3)))))
        ; If the action tells us to TURN-LEFT, change the direction of the agent to the new direction
        ((equal? action "TURN-LEFT") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 3 state 'W))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 3 state 'E))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 3 state 'S))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 3 state 'N))))
        ; If the action tells us to TURN-RIGHT, change the direction of the agent to the new direction
        ((equal? action "TURN-RIGHT") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 3 state 'E))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 3 state 'W))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 3 state 'S))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 3 state 'N))))
        ; If the action tells us to TURN-AROUND, change the direction of the agent to the new direction
        ((equal? action "TURN-AROUND") (cond ((equal? 'N (nth-item 3 state)) (replace-nth-item 3 state 'S))
            ((equal? 'S (nth-item 3 state)) (replace-nth-item 3 state 'N))
            ((equal? 'E (nth-item 3 state)) (replace-nth-item 3 state 'W))
            ((equal? 'W (nth-item 3 state)) (replace-nth-item 3 state 'E))))
    )
)

(apply-action '(5 2 N) "MOVE-2")
(apply-action '(0 1 W) "MOVE-1")
(apply-action '(14 -4 E) "STAY")
(apply-action '(0 0 S) "TURN-RIGHT")
(apply-action '(1 2 E) "TURN-AROUND")