#!/usr/bin/env ruby
# coding: utf-8

line = gets.split(' ').map(&:to_i)
result = 0
(line[0]..line[1]).each do |i|
  if line[2] % i == 0
    result += 1
  end
end
puts result
