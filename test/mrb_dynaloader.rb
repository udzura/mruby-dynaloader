##
## DynaLoader Test
##

assert("DynaLoader#hello") do
  t = DynaLoader.new "hello"
  assert_equal("hello", t.hello)
end

assert("DynaLoader#bye") do
  t = DynaLoader.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("DynaLoader.hi") do
  assert_equal("hi!!", DynaLoader.hi)
end
