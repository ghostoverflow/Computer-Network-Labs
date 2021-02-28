set ns  [new Simulator]

$ns color 1 blue
$ns color 2 red
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
for {set i 1} {$i<7} {incr i} {
        $ns duplex-link $n(0) $n($i) 512Kb 10ms SFQ
}

set tcpagent [new Agent/TCP]
$tcpagent set class_ 1
$ns attach-agent $n(1) $tcpagent

set sinkagent [new Agent/TCPSink]
$ns attach-agent $n(4) $sinkagent
$ns connect $tcpagent $sinkagent
set udpagent [new Agent/UDP]
$udpagent set class_ 2
$ns attach-agent $n(2) $udpagent
set nullagent [new Agent/Null]
$ns attach-agent $n(5) $nullagent
$ns connect $udpagent $nullagent
set cbr [new Application/Traffic/CBR]
$cbr set rate_ 256Kb
$cbr attach-agent $udpagent
set ftp [new Application/FTP]
$ftp attach-agent $tcpagent

$ns rtmodel-at 0.5 down $n(0) $n(5)
$ns rtmodel-at 0.9 up $n(0) $n(5)
$ns rtmodel-at 0.7 down $n(0) $n(4)
$ns rtmodel-at 1.2 up $n(0) $n(4)

$ns at 0.1 "$ftp start"
$ns at 1.5 "$ftp stop"

$ns at 0.2 "$cbr start"
$ns at 1.3 "$cbr stop"

$ns at 2.0 "finish"
$ns run