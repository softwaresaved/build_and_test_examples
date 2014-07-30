!> FRUIT unit test framework driver.

program fruit_test_driver

  use fruit

  ! Add modules here...
  use fibonacci_test

  call init_fruit()
  call init_fruit_xml()

  ! Add module basket calls here..
  call fibonacci_basket()

  call fruit_summary()
  call fruit_summary_xml()
  call fruit_finalize()

end program fruit_test_driver
