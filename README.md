# Connect Four

## NOTES:

## 5. Create a new branch for each new feature
From this point, each member of the group will create a new branch for any feature they are adding to the project. Do this by entering either of these two options:

#### Create a branch and checks it out
```$ git checkout -b branchName```

#### Checks out the branch
```$ git checkout branchName```

Be sure to always check which branch you are on using `git status` before you begin working!

## 6. Merge your branch
Once your branch is ready to be merged to master, follow these steps.

* While in your branch you will
   ```
   $ git add <files>
   $ git commit -m "message"
   $ git push origin <branch name>
   ```
   > The last command creates the branch remotely (in GitHub) and pushes to that branch on GitHub
* Go to GitHub and create a new pull request
   * You can compare your branch to any other branch, but you willm ost likely be comparing to `main/master`
   * You can assign a specific person or not
   * You will not be able to approve your own pull request
* Once someone reviews the pull request, they will resolve any issues or conflicts that come up and approve the pull request to be merged into the master

## 7. Start each day off right
Begin every day by pulling from the master to your local master.

* Pulling will automatically try to merge the recent commits from master and throw errors if there are any conflicts
* Fetching will gather the most recent commits in a branch which you can then view and decide to merge or not
* Once you have all the most recent updates on your `main/master` you can then merge those changes into your branch:
   ```
   $ git checkout <branch you want to update>
   $ git merge <branch name you're merging from>
   ```
* You may have to handle merge conflicts at this point. Note that files with merge conflicts are usually a different color in the sidebar.
* Create a new branch
   ```
   $ git checkout -b <new branch name>
   ```
* This branch will start off with a copy of the branch you were on.