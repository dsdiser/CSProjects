#lang racket
;; Import the Racket unit testing package.  for details, see
;; http://docs.racket-lang.org/rackunit/.  If this file is named
;; hw6test.ss, you can run it from the unix command line on gl like
;;
;;   mzscheme -f hw6test.ss

;; require the racket module for unit testing and its text user
;; interface
;; Load your HW6 file

(require rackunit rackunit/text-ui "hw6.ss")

;; Define some tests for chop and unchop

(define chop-tests
  (test-suite "tests for chop and unchop"

    ;; these should all produce a correct result
    (test-equal? "check 3 list" (chop '(1 2 3)) '(1 2))
    (test-equal? "check singleton" (chop '((1 2 3))) null)
    (test-equal? "check singleton" (chop '(1)) null)

    ;; these better all throw exceptions
    (check-exn exn:fail? (lambda () (chop 1)) "Chop should throw an
       exception if its arg is an atom")
    (check-exn exn:fail? (lambda () (chop '(1 . 2))) "Chop should
       throw an exception if its arg is not a proper list")
   ))



;; Define some tests for shift-left and shift-right

(define shift-tests 
  (test-suite "tests for shift functions"
    (test-equal? "left null" (shift-left null) null)
    (test-equal? "left (a)" (shift-left '(a)) '(a))
    (test-equal? "left (a b)" (shift-left '(a b)) '(b a))
    (test-equal? "left (a b c)" (shift-left '(a b c)) '(b c a))

    ;; these better all throw exceptions
    (check-exn exn:fail? (lambda () (shift-left 1)) "shift-left should throw an
       exception if its arg is an atom")
    (check-exn exn:fail? (lambda () (shift-left '(1 . 2))) "shift-left should
       throw an exception if its arg is not a proper list")

    (test-equal? "right null" (shift-right null) null)
    (test-equal? "right (a)" (shift-right '(a)) '(a))
    (test-equal? "right (a b)" (shift-right '(a b)) '(b a))
    (test-equal? "right (a b c)" (shift-right '(a b c)) '(c a b))

    ;; these better all throw exceptions
    (check-exn exn:fail? (lambda () (shift-right 1)) "shift-right should throw an
       exception if its arg is an atom")
    (check-exn exn:fail? (lambda () (shift-right '(1 . 2))) "shift-right should
       throw an exception if its arg is not a proper list")
  ))


;; Define some tests for zipper?, zip and unzip

(define zip-tests 
  (test-suite "tests for zip functions"

    (test-equal? "zipper? 1" (zipper? null) #t)
    (test-equal? "zipper? 2" (zipper? '((a 1))) #t)
    (test-equal? "zipper? 3" (zipper? '((a 1)(b 2))) #t)
    (test-equal? "zipper? 4" (zipper? 1) #f)
    (test-equal? "zipper? 5" (zipper? '(a 1)) #f)
    (test-equal? "zipper? 6" (zipper? '((a 1) (b))) #f)
    (test-equal? "zipper? 7" (zipper? '((a 1) . 2)) #f)

    (test-equal? "zip 1" (zip '(a) '(1)) '((a 1)))
    (test-equal? "zip 2" (zip '(a b) '(1 2)) '((a 1)(b 2)))
    (check-equal? (zip '(a b) '(1 )) '((a 1)(b ())) "zip 3: arg2 not defaulting")
    (test-equal? "zip 4" (zip '(a b) '(1 )) '((a 1)(b ())) )
    (test-equal? "zip 5" (zip '(a) '(1 2)) '((a 1)(() 2)))
    (test-equal? "zip 6" (zip null null) null)

    (test-equal? "unzip 1" (unzip null) '(()()))
    (test-equal? "unzip 2" (unzip '((a 1))) '((a) (1)))
    (test-equal? "unzip 3" (unzip '((a 1)(b 2))) '((a b) (1 2)))
    (test-equal? "unzip 4" (unzip '((a 1)(b ()))) '((a b) (1 ())))

))

;; Run the test suites and report the results

(printf "\nRunning chop tests\n")
(run-tests chop-tests)

(printf "\nRunning shift tests\n")
(run-tests shift-tests)

(printf "\nRunning zip tests\n")
(run-tests zip-tests)

;; We're done!
