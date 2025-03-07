puts "source file:"
set s [gets stdin]
puts "destination file:"
set d [gets stdin]

set sf [open $s r]
set content [read $sf]

set df [open $d w]
puts $df $content