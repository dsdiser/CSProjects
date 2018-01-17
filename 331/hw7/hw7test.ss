#lang scheme
;; Import the Racket unit testing package.  for details, see
;; http://docs.racket-lang.org/rackunit/.  This file should be in
;; the same directory as your homework solution file hw7.ss
;; NB: Currently, the verion of MzScheme on GL is too old to run rackunit

;; require the racket module for unit testing and its text user
;; interface

(require rackunit rackunit/text-ui)

;; Load your HW7 file
;; NB: It must have a "(provide func1 func2 func3)" expression at the
;; end to export all of the functions you are testing

(require "hw7.ss")

;; Define some tests for the lambda expressions

(define lambda-tests
  (test-suite "tests for lambda expressions"

    ;; these should all produce a correct result
    (test-equal? "do-nothing" (do-nothing) 0)
    (test-equal? "first-str 1" (first-str "bar" "foo") "bar")
    (test-equal? "first-str 2" (first-str "foo" "foo") "foo")
    (test-equal? "first-str 3" (first-str "foo" "bar") "bar")
    (test-equal? "converse-func 1" ((converse-func even?) 2) #f)
    (test-equal? "converse-func 2" ((converse-func even?) 3) #t)
    (test-equal? "converse-func 3" ((converse-func <) 4 3) #t)
    (test-equal? "converse-func 4" ((converse-func <) 3 4) #f)
    (test-equal? "converse-func 5" ((converse-func <) 3 3) #t)
    (test-equal? "converse-func 6" ((converse-func <) 3 4 5 6) #f)
    (test-equal? "converse-func 7" ((converse-func <) 3 4 5 1) #t)
    (test-equal? "converse-func 8" ((converse-func (converse-func <)) 3 4) #t)
    (test-equal? "converse-func 9" ((converse-func (converse-func <)) 4 3) #f)
    
   ))



;; Define some tests for unique-atoms

(define unique-atoms-tests 
  (test-suite "tests for unique-atoms"
    (test-equal? "unique-atoms 1" (unique-atoms '()) null)
    (test-equal? "unique-atoms 2" (unique-atoms '(()(())())) null)
    (test-equal? "unique-atoms 3" (sort (unique-atoms '(1 2 3)) <) '(1 2 3))
    (test-equal? "unique-atoms 4" (sort (unique-atoms '(3 2 1)) <) '(1 2 3))
    (test-equal? "unique-atoms 5" (sort (unique-atoms '(1 1 2 3 2 3 1)) <) '(1 2 3))
    (test-equal? "unique-atoms 6" (sort (unique-atoms '((1) ((2)) (((3))))) <) '(1 2 3))
    (test-equal? "unique-atoms 7" (sort (unique-atoms '((1) 1 ((2) 2) (((3) () 3) 2) 1)) <) '(1 2 3))

  ))



;; Define some tests for reverse-tree

(define reverse-tree-tests 
  (test-suite "tests for reverse-tree"
    (test-equal? "reverse-tree 1" (reverse-tree '(A B C)) '(C B A))
    (test-equal? "reverse-tree 2" (reverse-tree '(A (X Y Z) B C)) '(C B (Z Y X) A))
    (test-equal? "reverse-tree 3"
      (reverse-tree '(A B (P Q R (X Y Z) (1 2 3) ()) D E (((F) G) H)))
      '((H (G (F))) E D (() (3 2 1) (Z Y X) R Q P) B A))

  ))


;; Run the test suites and report the results

(printf "\nRunning lambda tests\n")
(run-tests lambda-tests)

(printf "\nRunning unique-atoms tests\n")
(run-tests unique-atoms-tests)

(printf "\nRunning reverse-tree tests\n")
(run-tests reverse-tree-tests)

;; We're done!
