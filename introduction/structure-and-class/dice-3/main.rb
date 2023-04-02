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

dice_eyes1 = line[0].chomp.split(' ').map(&:to_i)
dice_eyes2 = line[1].chomp.split(' ').map(&:to_i)

d1 = Dice.new(dice_eyes1)
d2 = Dice.new(dice_eyes2)

if d1.single? d1.dice_eye_min
  d1.place_dice_front(d1.dice_eye_min)
  d2.place_dice_front(d2.dice_eye_min)

  d1.place_dice_top(d1.dice_eye_min2)
  d2.place_dice_top(d2.dice_eye_min2)
else
  d1.place_dice_front(d1.dice_eye_max)
  d2.place_dice_front(d2.dice_eye_max)

  d1.place_dice_top(d1.dice_eye_min2)
  d2.place_dice_top(d2.dice_eye_min2)
end

if d1.dice == d2.dice
  puts 'Yes'
else
  puts 'No'
end
