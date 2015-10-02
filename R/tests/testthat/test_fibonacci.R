# Copyright 2014 The University of Edinburgh.
#
# Licensed under the Apache License, Version 2.0 (the "License"); 
# you may not use this file except in compliance with the License. 
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software 
# distributed under the License is distributed on an "AS IS" BASIS, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.

#' Fibonacci numbers tests.

library(testthat)
library(ssi.r.sample)

context("Fibonacci tests")

test_that("fibonacci(0)",{
  expect_that(0, equals(fibonacci(0)))
})

test_that("fibonacci(1)",{
  expect_that(1, equals(fibonacci(1)))
})

test_that("fibonacci(2)",{
  expect_that(1, equals(fibonacci(2)))
})

test_that("fibonacci(3)",{
  expect_that(2, equals(fibonacci(3)))
})

test_that("fibonacci(30)",{
  expect_that(832040, equals(fibonacci(30)))
})
