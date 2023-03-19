#!/usr/bin/env ruby
# coding: utf-8

line = readlines
lst = line[1].chomp.split(" ").map(&:to_i)

puts lst.min.to_s + " " + lst.max.to_s + " " + lst.sum.to_s
