
#Get the file names from the command line arguments
#set file1 [lindex $argv 0]
#set file2 [lindex $argv 1]

puts "enter file-1="
set f1 [gets stdin]
puts "enter file-2="
set f2 [gets stdin]

if {![file exist $f1]} {
    puts "invalid"
} elseif {![file exist $f1]} {
    puts"invalid"
} else {
    set t1 [file mtime $f1]
    set t2 [file mtime $f2]
    if {$t1==$t2} {
        puts "equal"
    } elseif {$t1>$t2} {
        puts "Recent modified file is $f1"
    } else {
        puts "Recent modified file is $f2"
    }
}
