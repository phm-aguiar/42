#!/bin/bash
# rm -rf .git

# git clone $1 git
# git clone git@github.com:phm-aguiar/42_libft.git git

# cd git

# mv .git ../

# cd ..

# rm -rf git

# cd ~/Documents/projetos/42_libft

git add .

git commit -S -m "progresso do dia $(date '+%d/%m/%Y') na 42sp"

git push

git status
