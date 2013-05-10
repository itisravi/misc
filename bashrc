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

export PATH=$PATH:"/home/ravi/bin"
export EDITOR=vim

