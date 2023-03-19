#!/usr/bin/env ruby
# coding: utf-8

counter = 1
while true
  i = gets
  if i.to_i == 0
    break
  end
  print "Case " + counter.to_s + ": " + i
  counter = counter + 1
end
