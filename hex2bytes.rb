#!/usr/bin/ruby

# Stephen Paul Weber
# For use with mnmonicode
# ISC license

arr = []
str = ""
inarr = STDIN.read.split(//).select { |i| "1234567890ABCDEFabcdef".include?i }
if inarr.length % 2 != 0
	inarr.unshift '0'
end
inarr.each do |i|
	str << i
	if str.length == 2
		arr << str
		str = ""
	end
end
print arr.collect {|i| i.to_i(16).chr}.join
