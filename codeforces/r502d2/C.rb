n = gets.chomp.to_i

st = Math.sqrt(n).to_i

(1..n).step(st) do |i|
  [i+st-1,n].min.downto(i) { |j| print "#{j} " }
end

puts ""
