#!/bin/bash

max=` cat /proc/sys/kernel/pid_max`

echo "The maximum allocatable PID on this system is $max"
