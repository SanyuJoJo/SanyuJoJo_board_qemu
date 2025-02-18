PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/bin
LD_LIBRARY_PATH=/lib:/usr/lib:/usr/local/lib
export PATH LD_LIBRARY_PATH
export PS1="\[\e[32;40m\]\u@\h:\w\$ \[\e[0m\]"
export HISTFILESIZE=500
alias ll='ls -lt'
# screen 
QEMU_VPARAM="$(cat /sys/firmware/qemu_fw_cfg/by_name/opt/qemu_cmdline/raw | sed 's/\(.*\)qemu_vc=:\(.*\):\(.*\)/\2/g')"
ROWS="$(echo $QEMU_VPARAM | sed 's/\(.*\)vn:\(.*\)x\(.*\)/\2/g')"
COLS="$(echo $QEMU_VPARAM | sed 's/\(.*\)vn:\(.*\)x\(.*\)/\3/g')"
stty rows $ROWS cols $COLS
