#!/usr/bin/env ruby
# coding: utf-8

line = gets.split(' ').map(&:to_i)
line.sort!.each_index do |i|
  if i == line.size - 1
    print line[i].to_s + "\n"
  else
    print line[i].to_s + " "
  end
end
