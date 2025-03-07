puts "Enter the number="
set n [gets stdin]
for {set i 1} {$i<=10} {incr i 1} {
    set res [expr $n*$i]
    puts "$n X $i=$res"
}