!> Command-line tool to calculate the Fibonacci number of a given
!! integer.

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

program fibonacci_program

  use fibonacci_module

  implicit none

  integer       :: num_arguments, n, fib
  character(60) :: argument

  num_arguments=command_argument_count()
  if (num_arguments == 0) then
    call print_usage()
    stop 1
  end if
  call get_command_argument(1, argument)
  read(argument,*) n
  if (n < 0) then
    call print_usage()
    stop 2
  end if
  fib = fibonacci(n)
  write(*,*) 'fibonacci(',n,') = ',fib

contains

  subroutine print_usage()
    write(*,*) 'Usage: ./fibonacci N'
    write(*,*) '  where N >= 0'
  end subroutine print_usage

end program fibonacci_program
