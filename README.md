# DFS
DFSWORK

Due to the bad network environment and some shitty bugs of my computer,
First we need to build a proxy to get through the firewall.
As for the shitty bugs, I need a file called "git.ignore" located in .git directory.
The content of which is as following:
```
		# Created by https://www.toptal.com/developers/gitignore/api/windows
		# Edit at https://www.toptal.com/developers/gitignore?templates=windows

		### Windows ###
		# Windows thumbnail cache files
		Thumbs.db
		Thumbs.db:encryptable
		ehthumbs.db
		ehthumbs_vista.db

		# Dump file
		*.stackdump

		# Folder config file
		[Dd]esktop.ini

		# Recycle Bin used on file shares
		$RECYCLE.BIN/

		# Windows Installer files
		*.cab
		*.msi
		*.msix
		*.msm
		*.msp

		# Windows shortcuts
		*.lnk

		# End of https://www.toptal.com/developers/gitignore/api/windows
```

To initialize a git core, use command 
```
git init 
```
in console or cmd or whatever.
Then a git core will be created.

But first choose a good position to deploy the git core. So I suggest to use cmd in windows directly and choose a good place istead of to use the git bash. The git bash performances pretty shity on windows or at least on my computer.

After deployed the git core, we can find a ".git" directory, which is hidden.

Open it and create the file "git.ignore", follow the structions above.

Then I think it's time to link the git to github.

Register a github, take a deep breath, and create a new repository (you can use others if you want to do so). Another .git directory shows up on the web! With two files named "LICENSE" and "README.md". The latter is what you're reading.

Then copy the full url of your repository, as usual namely "https://github.com/yournickname/repositoryname"

but add a ".git" after the url, as "https://github.com/yournickname/repositoryname.git"

Then open your cmd and find a location where you want to deploy the work. This time you're gonna upload it on the github. Of course can you choose the same directory of the initial .git if you would like to.

Then input 
```
git clone https://github.com/yournickname/repositoryname
```
A folder named repositoryname shows up. Inside there's another .git hidden folder.

Put the "ignore" file into ever .git folder in my computer can my git work well.

There may be a problem, we cannot get the information from github but we may can browse it on a browser of course with a proxy under our internet.

The point is, network communication started in Terminal "cmd" won't transfer it self to proxy directly but we have to settle that thing mannually.

Supposing the proxy number is 9999. Tell the git to transfer the fluss to right proxy. 
```
git config --global http.proxy 127.0.0.1:9999
git config --global https.proxy 127.0.0.1:9999
```
To reset,  use command
```
git config --global --unset http.proxy
git config --global --unset https.proxy
```
That shall be ok.
Then we start to add files into the folder.
After move the target file (or folder) into the repository folder, tell git:
```
git add filename/directoryname
```
Then commit
```
git commit -m "symbol_value_could_be_any_string_as_a_signature"
```
And push it to cloud!
```
git push (remoteaddress) (branch)
```
We can leave the latter two parameter blank if we are under the repository directory.
END