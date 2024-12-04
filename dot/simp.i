loadI 8 => r1
loadI 12 => r4
load r1 => r3
load r4 => r5
add r1, r3 => r2
store r2 => r4
output 8
sub r2, r3 => r0
store r0 => r1
output 8