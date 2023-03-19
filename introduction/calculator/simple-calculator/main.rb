#!/usr/bin/env ruby
# coding: utf-8

def calculator(a, op, b)
  if op == "+"
    puts a + b
  end
  if op == "-"
    puts a - b
  end
  if op == "*"
    puts a * b
  end
  if op == "/"
    puts a / b
  end
end

line = readlines

(0..line.length - 1).each do |i|
  a, op, b = line[i].chomp.split(" ")
  calculator(a.to_i, op, b.to_i)
end
