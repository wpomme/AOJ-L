#!/usr/bin/env ruby
# coding: utf-8

input = gets.to_i

def length (num)
  num.zero? ? 1 : Math.log10(num).to_i + 1
end

ret = (1..input)
  .select do |num|
    flag = false

    if num % 3 == 0
      flag = true
    end

    tmp = num
    while tmp > 0
        if tmp % 10 == 3
          flag = true
        end
        tmp = tmp / 10
    end

    flag
  end

print " "
print ret.join(" ")
puts
