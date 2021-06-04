puts '###########################'
puts `gem list | grep rice`
require 'rubygems'
require 'mkmf-rice'

create_makefile('vtslv/vtslv')
