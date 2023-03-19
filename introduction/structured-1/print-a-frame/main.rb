#!/usr/bin/env ruby
# coding: utf-8

def printRectangle(height, width)
  (1..height).each do |i|
    if i == 1 || i == height
      puts "#" * width
    else
      puts "#" + "." * (width - 2) + "#"
    end
  end
end

line = readlines
len = line.length
i = 0

while i < len
  height, width = line[i].chomp.split(' ').map(&:to_i)
  if (height == 0 && width == 0)
    # return
  else
    printRectangle(height, width)
    puts
  end
  i += 1
end
