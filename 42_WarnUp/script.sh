#!/bin/bash
rm -rf .git

git clone $1 git

cd git

mv .git ../

cd ..

rm -rf git

git add .

git commit -m "testes continuos do dia 18"

git push

git status
