proc readInput {List1 num} {
    for {set i 1} {$i <= $num} {set i [expr $i+1]} {
        puts "enter element-$i:"
        set  ele [gets stdin]
        lappend List1 $ele
      }
  return $List1
}
proc compare {a b} {
    if {$a>$b} {
        return 1
    } elseif {$a<$b} {
        return -1
    } else {
        return 0
    }
}
proc PrintOutput  {List1} {
    foreach item $List1 {
     puts -nonewline "$item\t"
   }
   return $List1
}
set List1 []

puts "Enter the no of ele:"
set num [gets stdin]
puts "Enter the elements:"
set List1 [readInput $List1 $num]
set List1 [lsort -command compare $List1]
puts "Elements sorted in list:"
set List1 [PrintOutput  $List1]