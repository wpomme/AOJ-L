# 真正面からサイコロを見た時の配置を変数としている
# @dice = [top, front, right, back, left, bottom]
class Dice
  def initialize(dice = [1, 2, 3, 4, 5, 6])
    @dice_attr = %i[top front right left back bottom]
    @dice = Hash[@dice_attr.zip(dice)]
  end

  def debug
    puts @dice
  end

  def self.face(name)
    define_method(name) do
      puts @dice[name]
    end
  end

  # REFACTOR NEEDED
  face :top
  face :front
  face :right
  face :back
  face :left
  face :bottom

  def roll(first:, second:, third:, fourth:)
    dice_copy = @dice.dup
    @dice[first] = dice_copy[fourth]
    @dice[second] = dice_copy[first]
    @dice[third] = dice_copy[second]
    @dice[fourth] = dice_copy[third]
    self
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

direction_map = { E: 'east', W: 'west', N: 'north', S: 'south' }
line = readlines

dice_eyes = line[0].chomp.split(' ').map(&:to_i)
directions = line[1].chomp.split(//, 0)

d = Dice.new(dice_eyes)
directions.each do |direction|
  d.public_send(direction_map[direction.to_sym])
end

d.top
