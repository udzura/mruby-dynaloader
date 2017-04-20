MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem '../mruby-dynaloader'
  conf.enable_debug
  conf.enable_test
end
