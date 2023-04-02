# 真正面からサイコロを見た時の配置を変数としている
# @dice = [top, front, right, back, left, bottom]
class Dice
  attr_reader :dice

  def initialize(dice = [1, 2, 3, 4, 5, 6])
    @dice_attr = %i[top front right left back bottom]
    @dice = Hash[@dice_attr.zip(dice)]
  end

  def self.face(name)
    define_method(name) do
      @dice[name]
    end
  end

  face :top
  face :front
  face :right
  face :back
  face :left
  face :bottom

  def debug
    puts @dice
  end

  def dice_eye_max2
    @dice.values.reject { |eye| eye == front || eye == back }.max
  end

  def dice_eye_min2
    @dice.values.reject { |eye| eye == front || eye == back }.min
  end

  def single?(eye)
    @dice.values.select { |value| value == eye }.size == 1
  end

  def dice_eye_min
    @dice.values.min
  end

  def dice_eye_max
    @dice.values.max
  end

  def find(dice_eye)
    @dice.key(dice_eye)
  end

  def place_dice_top(dice_eye)
    found = find(dice_eye)
    self if found == :top
    east if found == :left
    west if found == :right
    south if found == :back
    north if found == :front
    east.east if found == :bottom
  end

  def place_dice_front(dice_eye)
    found = find(dice_eye)
    self if found == :front
    south if found == :top
    north if found == :bottom
    clockwise.clockwise if found == :back
    clockwise if found == :right
    counterclockwise if found == :left
  end

  def roll(first:, second:, third:, fourth:)
    dice_copy = @dice.dup
    @dice[first] = dice_copy[fourth]
    @dice[second] = dice_copy[first]
    @dice[third] = dice_copy[second]
    @dice[fourth] = dice_copy[third]
    self
  end

  def counterclockwise
    roll(first: :back, second: :left, third: :front, fourth: :right)
  end

  def clockwise
    roll(first: :back, second: :right, third: :front, fourth: :left)
  end

  def east
    roll(first: :top, second: :right, third: :bottom, fourth: :left)
  end

  def west
    roll(first: :top, second: :left, third: :bottom, fourth: :right)
  end

  def south
    roll(first: :top, second: :front, third: :bottom, fourth: :back)
  end

  def north
    roll(first: :top, second: :back, third: :bottom, fourth: :front)
  end
end

# d = Dice.new([11, 12, 13, 14, 15, 16])
# d.place_dice_top(12)
# d.debug
# d.place_dice_front(14)
# d.right
# d.debug

line = readlines
len = line[0].chomp.to_i

dices = []

(1..len).each do |i|
  dices.push(Dice.new(line[i].chomp.split(' ').map(&:to_i)))
  # dices.push(Dice.new(dice_eyes[i - 1]))
end

if dices[0].single? dices[0].dice_eye_min
  (0..len - 1).each do |i|
    dices[i].place_dice_front(dices[i].dice_eye_min)
    dices[i].place_dice_top(dices[i].dice_eye_min2)
  end
else
  (0..len - 1).each do |i|
    dices[i].place_dice_front(dices[i].dice_eye_max)
    dices[i].place_dice_top(dices[i].dice_eye_min2)
  end
end

is_dice_same = false

(0..len - 1).each do |i|
  (i + 1..len - 1).each do |j|
    if dices[i].dice == dices[j].dice
      is_dice_same = true
      break
    end
  end
end

if is_dice_same
  puts 'No'
else
  puts 'Yes'
end
