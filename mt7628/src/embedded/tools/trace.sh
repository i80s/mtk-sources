mount -t debugfs nodev /debug
cd /debug/tracing
echo ":mod:mt7603e_ap:" > set_ftrace_filter
echo "function" > current_tracer
echo 1 > tracing_on
cat trace_pipe > /root/debug_crash
