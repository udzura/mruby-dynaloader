# mruby-dynaloader   [![Build Status](https://travis-ci.org/udzura/mruby-dynaloader.svg?branch=master)](https://travis-ci.org/udzura/mruby-dynaloader)
DynaLoader class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-dynaloader'
end
```
## example
```ruby
p DynaLoader.hi
#=> "hi!!"
t = DynaLoader.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
