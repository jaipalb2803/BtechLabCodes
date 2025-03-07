set f1 [open "one.txt" w]
puts "Enter the no of line:"
set num [gets stdin]
puts "Enter the Data:"
for {set i 1} {$i <= $num} {set i [expr $i+1]} {
    set line [gets stdin]
    puts $f1 $line
}
puts "success to written"
close $f1 
set f3 [open "one.txt" r]
set f2 [open "two.txt" w]
gets $f3 line
while {![eof $f3]} {
    puts $f2 $line
    gets $f3 line
}
puts "success to copied"
close $f2  
close $f3      

#scirpt-2
puts "source file:"
set s [gets stdin]
puts "destination file:"
set d [gets stdin]

set sf [open $s r]
set content [read $sf]

set df [open $d w]
puts $df $content
