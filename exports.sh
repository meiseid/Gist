export HISTSIZE=1000
export SAVEHIST=1000000
export EDITOR=vi
export LD_LIBRARY_PATH="/usr/local/lib"
alias ll='ls -alF'
alias lt='ls -ltr'
# git commit; git push;
function gco(){
 if [ "x$1" = "x" ]; then
  git commit -a
 else
  git commit -a -m "$1"
 fi
 git push -u origin master
}
alias gdf='git diff remotes/origin/master'
ulimit -S -c unlimited
if [ -d $HOME/.nodebrew ]; then
 export PATH=$HOME/.nodebrew/current/bin:$PATH
fi
