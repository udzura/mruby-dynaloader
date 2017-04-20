##
## DynaLoader Test
##

assert("DynaLoader") do
  assert_true DynaLoader.is_a?(Class)
end

assert("DynaLoader.new") do
  t = DynaLoader.new("libc.so.6")
  assert_equal DynaLoader, t.class
  assert_equal String, t.handler_ptr_str.class
end
