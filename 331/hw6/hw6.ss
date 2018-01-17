#lang racket
;; CMSC 331 Spring 2012 hw6.ss, Daniel Diseroad, ddiser1@UMBC.EDU

(define (PASS . ARGS)
  ;; This is a a dummy function that takes any number of arguments and
  ;; always returns null.  You should replace calls to it with your
  ;; own scheme code.
  null)

;; problem one: chop and unchop

(define (chop l)
  ;; chop takes a proper list l with at least one element and returns
  ;; one like it with the last element removed.
  ;; Examples: (chop '(1 2))=>(1), (chop '(1))=>()
  (reverse (cdr (reverse l)))
  )

(define (unchop l x)
  ;; Takes a proper list l and adds a new element to the rear of it
  (if (null? l)
      (list x)
      (cons (car l) (unchop (cdr l) x)))
  )

;; problem two: shift-right and shift-left

(define (shift-right l)
  ;;  returns a new list with the last element moved to the front
  (if (null? l)
     l
     (shift-right2 l 1 (length l))
  )
)


(define (shift-right2 l x y)
  ;; recursive function for shift-right
  (if (eqv? x y)
      l
      (shift-right2 (shift-left l) (+ x 1) y))
  )

(define (shift-left l)
  ;; returns a new list like its argument but with first element moved to the end 
  ;; of the list. 
  (if (null? l)
      l
      (unchop (cdr l) (car l))
  ))


;; problem three: zipper?, zip and unzip
(define (zipper2 l)
  ;; assists zipper? function
  (if (list? l)
      (if (eqv? 2 (length l))
	  #t
	  #f
	  )
      #f
      )
)

(define (zipper? l)
  ;; returns #t if its single argument is a zipper and #f if it is not
  (if (list? l)
      (cond ((null? l) 
	     #t)
	    ((not (zipper2 (car l)))
	     #f)
	    (else (zipper? (cdr l)))
	    )
      #f
      )
  )

(define (zip l1 l2)
  ;; takes any two proper lists and creates a zipper out of them, pairing up 
  ;; elements from the first and second arguments
  (cond ((> (length l1) (length l2))
	 (map list l1 (fixSize l2 (length l1))))
	((< (length l1) (length l2))
	 (map list (fixSize l1 (length l2)) l2))
	(else 
	 (map list l1 l2))
	)     
  )

(define (fixSize l x)
  ;; makes the list the size specified in the parameter by adding empty lists
  (if (eqv? (length (unchop l '())) x)
      (unchop l '())
      (fixSize (unchop l '()) x))
  )

(define (unzip l) 
  ;; reverses the process, taking a zipper and returning a list of two lists
  (if (null? l)
      (list l l)
      (list (unzipFront l) (unzipBack l))
      )
)

(define (unzipFront l) 
  ;; unzips the front of the zippers
  (if (null? l)
         l
         (cons (car (car l)) (unzipFront (cdr l)))
         )
)

(define (unzipBack l)
  ;; unzips the back of the zippers
  (if (null? l)
      l
      (cons (car (cdr (car l))) (unzipBack (cdr l))))
)


(provide chop unchop
	  shift-left shift-right
	   zipper? zip unzip)