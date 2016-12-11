(DEFINE (findMax list)
	(COND
		((NULL? list) ‘())
		((NULL? (CDR list)) (CAR list))
		((> (CAR list) (findMax (CDR list))) (CAR list))
		(ELSE (findMax (CDR list)))
	)
)


(DEFINE (findMin list)
	(COND
		((NULL? list) ‘())
		((NULL? (CDR list)) (CAR list))
		((< (CAR list) (findMin (CDR list))) (CAR list))
		(ELSE (findMin (CDR list)))
	)
)


(DEFINE (findMinAndMax list)
	(LIST ‘(findMax list) ‘(findMin list))
)
