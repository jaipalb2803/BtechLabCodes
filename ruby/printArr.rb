def readArr(arr,n)
   for i in (0..n-1)
     print"Element ",i+1,"="
     arr[i]=gets.chomp.to_i
   end
end
def printArr(arr,n)
    for i in (0..n-1)
      print arr[i],"\t"
    end
 end
print"Enter the size of array="
n=gets.chomp.to_i
arr=[]
readArr(arr,n)
puts "Array elements are:"
printArr(arr,n)

puts "\nSize of arr is:#{arr.size}"
puts "Size of length is:#{arr.length}"
puts "Size of first is:#{arr.first}"
puts "Size of last is:#{arr.last}"
puts "Unquie ele:#{arr.uniq}"
puts "without Destruction:#{arr}"
arr.uniq!
puts "with Destruction:#{arr}"
puts "Push ele:#{arr.push(7)}"
puts "Pop ele:#{arr.pop}"
puts "Unshift ele:#{arr.unshift(1)}"
puts "shift ele:#{arr.shift()}"
puts "Sort ele:#{arr.sort}"
puts "insert ele:#{arr.insert(2,5,6)}"
puts "delete ele:#{arr.delete(5)}"
puts "slice ele:#{arr.slice(0,3)}"
puts "reverse ele:#{arr.reverse!}"
puts "clear ele:#{arr.clear()}"