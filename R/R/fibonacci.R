#' Calculate the Fibonacci number of the given integer.
#'
#' @param n an integer, if <= 0 then 0 is assumed.
#' @return Fibonacci number

fibonacci<-function(n)
{
  if (n <= 0) 
  {
    return(0)
  }
  if (n == 1) 
  {
    return(1)
  }
  return(fibonacci(n - 1) + fibonacci(n - 2))
}
