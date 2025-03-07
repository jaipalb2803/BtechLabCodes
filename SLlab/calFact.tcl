puts "Enter a number:"
set num [gets stdin]
set res 1
for {set i 1} {$i <= $num} {set i [expr $i+1]} {
    set res [expr $res*$i]
}
puts -nonewline "Factorial value="
puts $res