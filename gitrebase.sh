#!/bin/bash

echo "#1.Checkout"
git checkout --orphan latest_branch || exit 1

echo "#2. Add all the files"
git add -A || exit 1

echo "#3. Commit the changes"
git commit -am "fix some thing." || exit 1

echo "#4. Delete the branch"
git branch -D master || exit 1

echo "#5.Rename the current branch to master"
git branch -m master || exit 1

ecoh "#6.Finally, force update your repository"
git push -f origin master || exit 1

