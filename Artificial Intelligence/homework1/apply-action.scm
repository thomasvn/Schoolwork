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

(define (apply-action action state)
    (cond ((= action "STAY") state)
        ; If the action tells us to MOVE-1, increment or decrement the respective coordinate
        ((= action "MOVE-1") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 2 state (+ 1 (nth-item 2 state))))
            ((= "S" (nth-item 3 state)) (replace-nth-item 2 state (- 1 (nth-item 2 state))))
            ((= "E" (nth-item 3 state)) (replace-nth-item 1 state (+ 1 (nth-item 1 state))))
            ((= "W" (nth-item 3 state)) (replace-nth-item 1 state (- 1 (nth-item 1 state))))))
        ; If the action tells us to MOVE-2, increment or decrement by 2 to the respective coordinate
        ((= action "MOVE-2") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 2 state (+ 2 (nth-item 2 state))))
            ((= "S" (nth-item 3 state)) (replace-nth-item 2 state (- 2 (nth-item 2 state))))
            ((= "E" (nth-item 3 state)) (replace-nth-item 1 state (+ 2 (nth-item 1 state))))
            ((= "W" (nth-item 3 state)) (replace-nth-item 1 state (- 2 (nth-item 1 state))))))
        ; If the action tells us to MOVE-3, increment or decrement by 3 to the respective coordinate
            ((= action "MOVE-3") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 2 state (+ 3 (nth-item 2 state))))
            ((= "S" (nth-item 3 state)) (replace-nth-item 2 state (- 3 (nth-item 2 state))))
            ((= "E" (nth-item 3 state)) (replace-nth-item 1 state (+ 3 (nth-item 1 state))))
            ((= "W" (nth-item 3 state)) (replace-nth-item 1 state (- 3 (nth-item 1 state)))))
        ; If the action tells us to TURN-LEFT, change the direction of the agent to the new direction
        ((= action "TURN-LEFT") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 3 state "W"))
            ((= "S" (nth-item 3 state)) (replace-nth-item 3 state "E"))
            ((= "E" (nth-item 3 state)) (replace-nth-item 3 state "S"))
            ((= "W" (nth-item 3 state)) (replace-nth-item 3 state "N"))))
        ; If the action tells us to TURN-RIGHT, change the direction of the agent to the new direction
        ((= action "TURN-RIGHT") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 3 state "E"))
            ((= "S" (nth-item 3 state)) (replace-nth-item 3 state "W"))
            ((= "E" (nth-item 3 state)) (replace-nth-item 3 state "S"))
            ((= "W" (nth-item 3 state)) (replace-nth-item 3 state "N"))))
        ; If the action tells us to TURN-AROUND, change the direction of the agent to the new direction
        ((= action "TURN-AROUND") (cond ((= "N" (nth-item 3 state)) (replace-nth-item 3 state "S"))
            ((= "S" (nth-item 3 state)) (replace-nth-item 3 state "N"))
            ((= "E" (nth-item 3 state)) (replace-nth-item 3 state "W"))
            ((= "W" (nth-item 3 state)) (replace-nth-item 3 state "E"))))
    )
)

(apply-action ‘(5 2 N) “MOVE-2”)
(apply-action ‘(0 1 W) “MOVE-1”)
(apply-action ‘(14 -4 E) “STAY”)
(apply-action ‘(0 0 S) “TURN-RIGHT”)
(apply-action ‘(1 2 E) “TURN-AROUND”)