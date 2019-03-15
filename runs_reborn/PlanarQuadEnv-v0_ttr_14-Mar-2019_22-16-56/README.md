1. phi_range = 0.3 
previous issue happend at this param. It's harder, that's why the wrong plotting point occur a little late.

2. phi_range = 0.4 
I keep looking at visualization and found the possible reason: simulator error cause the drone stay on the ground swinging,
reset not working which is not correct. Maybe the detection of obstacle should be optimized.
But learning performance is still working fine. so relax!

check reset condition, and more accurate detection of obstacle.