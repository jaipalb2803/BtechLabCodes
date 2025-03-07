puts "Odd number from 10 to 1 are:"
(1..10).reverse_each do
|num|
    puts num if num.odd?
end    