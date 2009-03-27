#!/usr/bin/ruby

# Stephen Paul Weber
# For use with mnmonicode
# ISC license

arr = []
str = ""
inarr = STDIN.read.split(//)
inarr.each do |i|
	print ("%x" % i[0]).rjust(2,'0')
end
puts
