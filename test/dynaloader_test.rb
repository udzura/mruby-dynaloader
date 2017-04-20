##
## DynaLoader Test
##

assert("DynaLoader.new") do
  assert_true DynaLoader.is_a?(Class)
end
