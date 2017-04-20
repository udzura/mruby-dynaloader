MRuby::Gem::Specification.new('mruby-dynaloader') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Uchio Kondo'

  spec.linker.libraries << 'dl'
end
