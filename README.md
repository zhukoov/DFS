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
It's ok to update it with commands above.
Besides we can use socks5 proxy by commands:
```
git config --global https.proxy socks5://127.0.0.1:9999
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
Then you have to authenticate your identity, a new window will pop up and ask you to login with browser or using personal token.
To generate tokens, first verify your email address, if it hasn't been verified yet.

In the upper-right corner of any page, click your profile photo, then click Settings.

![这是图片](/Asset/img/userbar-account-settings.png "s2")

In the left sidebar, click Developer settings.

![这是图片](/Asset/img/developer-settings.png "s3")

In the left sidebar, click Personal access tokens.

![这是图片](/Asset/img/personal_access_tokens_tab.png "s4")

Click Generate new token.

![这是图片](/Asset/img/generate_new_token.png "s5")

Give your token a descriptive name.

![这是图片](/Asset/img/token_description.png "s6")

To give your token an expiration, select the Expiration drop-down menu, then click a default or use the calendar picker.


![这是图片](/Asset/img/token_expiration.png "s7")

Select the scopes, or permissions, you'd like to grant this token. To use your token to access repositories from the command line, select repo.

![这是图片](/Asset/img/token_scopes.gif "s8")

Click Generate token.

![这是图片](/Asset/img/generate_token.png "s9")
![这是图片](/Asset/img/personal_access_tokens.png "s9")

Warning: Treat your tokens like passwords and keep them secret. When working with the API, use tokens as environment variables instead of hardcoding them into your programs.

Paste the token to the blank, authentication complete.

You won't have to do this again until the token expired.

We can leave the latter two parameter blank if we are under the repository directory.





While I'm using git to upload my homework data (Hausaufgabe in germany). It goes sticky and suddenly don't work any more.
I struggled for about a whole afternoon, gained a better command of the command line and config properties about git without solving the problem.

The maximum of the uploading size is 500MB. But the default size is 1MB.

To change the size, we can use command:
```
git config --global http.postbuffer 5242880000
```
Well no matter how large you set the number, it will remain 5242880000 at the top.

And when the network is unstable, here I mean unstable rather than shitty, we can use the following command to extent the limit of the network quality.
```
git config --global http.lowspeedlimit 0
git config --global http.lowspeedtime 999999
```

Sometimes, we also use 
```
git config --global http.sslverify false
```

But thats "http" oriented rather than https, I didn't try how's it work on https.

Actually I haven't found the differences between before and after I had applied them as well.

That goes to the solution to the problem:

What if I mistakely added and commited files larger than 500MB?

The answer is nothing will happen. REALLY!

And then you will be not able to push any thing! EVEN IF YOU REMOVE THOSE FILES!

BECAUSE THEY HAVE BEEN COMMITTED!

But there is still a way to solve that kind of problem.

First, find out the log.

```
git log
```

It shows:
![这是图片](/Asset/img/Git_Log.png "s7")

Find the commit you want to get back to and copy the hash string.
```
git reset --hard commit_hash 
```
Ok, nothing really happens.

END