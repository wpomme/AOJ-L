#!/usr/bin/env ruby
# coding: utf-8

line = readlines
len = line.length
index = 0

def combination(n, x)
  count = 0
  (1..n).each do |i|
    ((i+1)..n).each do |j|
      ((j+1)..n).each do |k|
        if x == i + j + k
          count += 1
        end
      end
    end
  end
  return count
end

while index < len
  n, x = line[index].chomp.split(' ').map(&:to_i)
  if n == 0 && x == 0
    # return
  else
    puts combination(n, x)
  end
  index += 1
end
