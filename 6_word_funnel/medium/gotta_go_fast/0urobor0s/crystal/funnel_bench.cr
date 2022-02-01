require "benchmark"
require "./node"

def matches_1(input, funnel_set)
  matches = [] of String
  input.each_char_with_index do |char, index|
    new_word = input.sub(index, "")
    matches.push new_word if funnel_set.includes? new_word
  end
  matches
end

def tree_expansion_1(root, funnel_set)
  level = 1
  root.traverse_subtree do |node|
    matches = matches_1(node.content, funnel_set)
    matches.each do |match|
      node.add_child(Tree::Node.new(match, node.level + 1))
      level = node.level + 1
    end
  end
  level
end

def matches_2(input, funnel_set)
  matches = [] of String
  (0..input.size-1).each do |index|
    new_word = input.sub(index, "")
    matches.push new_word if funnel_set.includes? new_word
  end
  matches
end

def tree_expansion_2(root, funnel_set)
  level = 1
  root.traverse_subtree do |node|
    matches = matches_1(node.content, funnel_set)
    matches.each do |match|
      node.add_child(Tree::Node.new(match, node.level + 1))
      level = node.level + 1
    end
  end
  level
end

words = File.read_lines("../enable1.txt", chomp: true).to_set
input = File.read_lines(ARGV[0], chomp: true)

Benchmark.ips do |x|
  x.report("1") do 
    input.each do |word|
      info = tree_expansion_1(Tree::Node.new(word, 1), words)
      puts "#{word} - #{info}"
    end
  end

  x.report("2") do 
    input.each do |word|
      info = tree_expansion_2(Tree::Node.new(word, 1), words)
      puts "#{word} - #{info}"
    end
  end

  x.report("channels Int") do 
    channel = Channel(Int8 | Int32).new(input.size)
    input.each do |word|
      spawn do
        info = tree_expansion_1(Tree::Node.new(word, 1), words)
        channel.send(info)
      end
    end
    input.each do |word|
      puts "#{word} - #{channel.receive}"
    end
  end

  x.report("channels String") do 
    channel = Channel(String).new(input.size)
    input.each do |word|
      spawn do
        info = tree_expansion_1(Tree::Node.new(word, 1), words)
        channel.send("#{word} - #{info}")
      end
    end
    input.each do |word|
      puts channel.receive
    end
  end
end
