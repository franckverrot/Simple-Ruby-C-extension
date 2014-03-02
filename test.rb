require 'MyStruct'

hdfr = MyStruct.new('Franck', 42)

puts """
hdfr = MyStruct.new('Franck', 42)

hdfr.to_s : #{hdfr.to_s}
hdfr.name : #{hdfr.name rescue "Info not available to Ruby"}
hdfr.age  : #{hdfr.age rescue "Info not available to Ruby"}
"""
