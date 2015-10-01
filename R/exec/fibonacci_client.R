#' Simple client to calculate the Fibonacci number of the given integer.
#'
#' Usage: Rscript fibonacci_client.R n
#' Example: Rscript fibonacci_client.R 10

library(ssi.r.sample)

args <- commandArgs(TRUE)
n <- strtoi(args[1])
fib <- fibonacci(n)
cat("fib(", n, ") = ", fib, "\n")
