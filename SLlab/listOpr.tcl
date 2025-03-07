proc createList {n} {
    set list []
    for {set i 0} {$i < $n} {incr i 1} {
            puts "ele-$i=";
            set ele [gets stdin]
            lappend list $ele
    }
    return $list
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
puts "enter the num="
set n [gets stdin]
set list1 [createList $n]
set list2 [createList $n]
set merge [concat $list1 $list2]
foreach var $list1 {
   puts $var
}
#set list1 [lsort -command compare $list1]
puts " New List:$merge"