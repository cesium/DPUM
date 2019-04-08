$/=' '
$<.map(&:to_i).sort.combination(3).select{|c|c.sum==0}.uniq.map{|r|puts r*?\s}
