# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions
if [ -z $SSH_CONNECTION ];
then
        fortune
        echo
fi

alias ldir="ls -l|grep ^d"
alias mnt="mount|column -t"
alias rm="rm -i"
alias pcp="perl /home/ravi/workspace/linux-next/scripts/checkpatch.pl"
alias utc="TZ='UTC' date"
alias errno="cpp -dM /usr/include/errno.h | grep 'define E' | sort -n -k 3"
alias lock="qdbus org.freedesktop.ScreenSaver /ScreenSaver Lock"

export PATH=$PATH:"/home/ravi/bin"
export EDITOR=vim

#coloured man pages
export MANPAGER="/usr/bin/most -s"

ulimit -c unlimited
shopt -s cdspell
