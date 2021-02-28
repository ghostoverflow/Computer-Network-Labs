set ns [new Simulator]
$ns rtproto DV

#file should exsist or this "w" will give error
set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exit 0
        }

for {set i 0} {$i<7} {incr i} {
        set n($i) [$ns node]
}

for {set i 0} {$i<7} {incr i} {
        $ns duplex-link $n($i) $n([expr ($i+1)%7]) 512Kb 5ms DropTail
}

$ns duplex-link-op $n(0) $n(1) queuePos 1
$ns duplex-link-op $n(0) $n(6) queuePos 1
set udp0 [new Agent/UDP]
$ns attach-agent $n(0) $udp0
set nullagent [new Agent/Null]
$ns attach-agent $n(3) $nullagent
$ns connect $udp0 $nullagent

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 1024
$cbr set interval_ 0.01
$cbr attach-agent $udp0

$ns rtmodel-at 0.4 down $n(2) $n(3)
$ns rtmodel-at 1.0 up $n(2) $n(3)

$ns at 0.01 "$cbr start"
$ns at 1.5 "$cbr stop"

$ns at 2.0 "finish"
$ns run