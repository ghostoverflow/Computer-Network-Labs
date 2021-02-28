#!/usr/bin/tclsh
set num [gets stdin]
if {$num <= 4} {
	puts "Invalid input $num"
} else {
	if {[expr $num % 2] == 0} {
		for {set i 4} {$i <= $num} {incr i} {
			if {[expr $i % 2] == 0} {
				puts "$i "
			}
		}
	} else {
		for {set i 3} {$i <= $num} {incr i} {
			if {[expr $i % 2] != 0} {
				puts "$i "
			}
		}
	}
}
