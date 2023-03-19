#!/usr/bin/env ruby
# coding: utf-8

line = gets.split(' ').map(&:to_i)
width, height, x, y, r = line
if width >= x + r && height >= y + r && x + r > 0 && y + r > 0
  puts 'Yes'
else
  puts 'No'
end

