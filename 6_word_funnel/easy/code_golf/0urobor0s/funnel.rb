#!ruby -n
a=[];f,l=$_.split;(0..f.size-1).each{|i|f.dup.tap{|s|s.slice!(i);a<<s}}
p a.include?(l)