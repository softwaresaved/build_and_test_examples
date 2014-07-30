!> Test module for fibonacci_module.

!! Copyright 2014 The University of Edinburgh.
!!
!! Licensed under the Apache License, Version 2.0 (the "License"); 
!! you may not use this file except in compliance with the License. 
!! You may obtain a copy of the License at
!!
!!   http://www.apache.org/licenses/LICENSE-2.0
!!
!! Unless required by applicable law or agreed to in writing, software 
!! distributed under the License is distributed on an "AS IS" BASIS, 
!! WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
!! implied. See the License for the specific language governing
!! permissions and limitations under the License.

module fibonacci_test
  use fruit
  use fruit_helpers
  use fibonacci_module

  implicit none

contains

  !> Initialise test suite - no-op.
  subroutine setup
  end subroutine setup

  !> Clean up test suite - no-op.
  subroutine teardown
  end subroutine teardown

  !> Test fibonacci(1).
  subroutine test_fibonacci1()
    call assert_equals(1, fibonacci(1))
  end subroutine test_fibonacci1

  !> Test fibonacci(2).
  subroutine test_fibonacci2()
    call assert_equals(1, fibonacci(2))
  end subroutine test_fibonacci2

  !> Test fibonacci(3).
  subroutine test_fibonacci3()
    call assert_equals(2, fibonacci(3))
  end subroutine test_fibonacci3

  !> Test fibonacci(30).
  subroutine test_fibonacci30()
    call assert_equals(832040, fibonacci(30))
  end subroutine test_fibonacci30

  !> Call each test.
  subroutine fibonacci_basket()
    character(len=*) :: suite_name 
    parameter(suite_name='fibonacci_test')

    call run_fruit_test_case(test_fibonacci1,'test_fibonacci1',&
      setup,teardown,suite_name)
    call run_fruit_test_case(test_fibonacci2,'test_fibonacci2',&
      setup,teardown,suite_name)
    call run_fruit_test_case(test_fibonacci3,'test_fibonacci3',&
      setup,teardown,suite_name)
    call run_fruit_test_case(test_fibonacci30,'test_fibonacci30',&
      setup,teardown,suite_name)

  end subroutine fibonacci_basket

end module fibonacci_test
