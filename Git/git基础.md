1. [获取Git仓库](#获取git仓库)
   1. [在本地目录中初始化仓库](#在本地目录中初始化仓库)
   2. [克隆现有的仓库](#克隆现有的仓库)
2. [记录每次更新到仓库](#记录每次更新到仓库)
   1. [查看文件状态](#查看文件状态)
   2. [跟踪新文件](#跟踪新文件)
   3. [暂存已修改的文件](#暂存已修改的文件)
   4. [查看已暂存和未暂存的修改](#查看已暂存和未暂存的修改)
   5. [提交更新](#提交更新)
   6. [移除已跟踪的文件](#移除已跟踪的文件)
   7. [移动文件](#移动文件)
3. [查看提交历史](#查看提交历史)
4. [撤销操作](#撤销操作)
   1. [修补提交](#修补提交)
   2. [取消暂存](#取消暂存)
   3. [撤销修改](#撤销修改)
5. [远程仓库的使用](#远程仓库的使用)
   1. [查看远程仓库](#查看远程仓库)
   2. [添加远程仓库](#添加远程仓库)
   3. [从远程仓库拉取](#从远程仓库拉取)
   4. [推送到远程仓库](#推送到远程仓库)
   5. [远程仓库的重命名与删除](#远程仓库的重命名与删除)
6. [打标签](#打标签)
   1. [列出标签](#列出标签)
   2. [创建标签](#创建标签)
      1. [附注标签](#附注标签)
7. [忽略文件](#忽略文件)


# 获取Git仓库

通常有两种获取 Git 项目仓库的方式：

1. 将尚未进行版本控制的本地目录转换为Git仓库
2. 从其他服务器上克隆一个已存在的Git仓库

这两种方式都会在你的本地机器上得到一个工作就绪的Git仓库。

## 在本地目录中初始化仓库

如果你有一个尚未进行版本控制的项目目录，并想用Git来控制它，那么首先需要进入到该项目目录中：

例如，我在home目录的用户目录下创建了一个MyProject文件夹，打开终端，使用`cd`命令扩展到该目录下：
```bash
cd MyProject
```
然后，执行
```bash
git init
```
<img src=image/2021-02-07_15-01.png>

该命令将创建一个名为`.git`的子目录，这个子目录中含有你初始化的Git仓库中所有的必须文件，这些文件是Git仓库的骨干。

但是，这时我们仅仅是做了一个初始化的操作，项目里的文件还没有被跟踪。

注意到，`.git`默认被隐藏，在ubuntu下查看被隐藏的文件使用`ctrl+h`

<img src=image/2021-02-07_15-02.png>

## 克隆现有的仓库

如果你想获取一份已经存在了的Git仓库的拷贝，比如你想为某个开源项目作出贡献，这时就要用到`git clone`命令。

克隆仓库的命令是：`git clone <url>`

例如：
```bash
git clone https://github.com/lixk28/LearnGit.git
```
这会在当前目录下创建一个名为LearnGit的目录，并在这个目录下初始化一个`.git`文件夹，从远程仓库拉取下所有数据放入该文件夹，然后从中读取最新版本的文件的拷贝。

<img src=image/2021-02-07_20-04.png>

<img src=image/2021-02-07_20-05.png>

如果你想在克隆远程仓库的时候，自定义本地仓库的名字，你可以通过额外的参数指定新的目录名：
```bash
git clone https://github.com/lixk28/LearnGit.git MyLearnGit
```
这会执行与上一条命令相同的操作，但目标目录的名称是`MyLearnGit`。

Git支持多种数据传输协议，除了`https://`，也可以用`git://`或SSH传输协议。


# 记录每次更新到仓库

工作目录下的每一个文件都只有两种状态：
- **已跟踪(tracked)**：已经被纳入版本控制的文件
  - **未修改(unmodified)**：或者说**已提交(commited)**，是指已经保存到`.git`数据库中的文件
  - **已修改(modified)**：文件被修改但没有被放入暂存区
  - **暂存(staged)**：放入暂存区的文件，注意到暂存区一般也在`.git`文件夹中
- **未跟踪(untracked)**：除了已跟踪的文件的其它所有文件

初次克隆某个仓库的时候，工作目录中的所有文件都属于已跟踪文件，并处于未修改（已提交）状态。

编辑过某些已被跟踪的文件之后，Git将它们标记为已修改文件。在工作时，你可以选择性地将这些修改过的文件放入暂存区，然后提交所有已暂存的修改，如此反复。

<img src=image/2021-02-07_20-59.png>


## 查看文件状态

查看文件状态的命令：
```bash
git status
```

我们先来查看刚才克隆的LearnGit：
<img src=image/2021-02-07_21-23.png>
这表明工作目录是干净的，所有的已跟踪文件在上次提交后都未被修改过。否则，Git将会把所有未跟踪的文件，已跟踪的已修改但未被提交的文件

此外，你还可以通过添加一个选项来获得更为简洁紧凑的文件状态输出：
```bash
git status -s
git status --short
```

## 跟踪新文件

跟踪新文件的命令：
```bash
git add <filename>
git add <directorypath>
```
`git add`命令使用文件名或目录的路径作为参数，表示命令Git跟踪某个文件或者某个目录下的所有文件。

我们先在LearnGit创建一个新文件`Hello`，然后查看文件的状态：
<img src=image/2021-02-07_22-50.png>
在状态报告中，可以看到新建的`Hello`文件出现在`Untracked files`（即未跟踪的文件）下。未跟踪的文件表示Git之前的快照中（提交)中没有这些文件。

然后跟踪`Hello`文件，再查看文件的状态：
<img src=image/2021-02-07_22-55.png>
可以看到`Hello`已经被跟踪，并处于暂存状态。只要在要提交的变更（Changes to be commited）下的文件，就说明是已暂存状态。


## 暂存已修改的文件

暂存已修改的文件的命令：
```bash
git add <filename>
```
`git add`命令是个多功能命令，它除了可以用来跟踪新文件，还可以将已跟踪的文件放到暂存区，以及用于合并时把有冲突的文件标记为已解决状态等。这个命令应该理解为：**将内容添加到下一次提交中**。

我们先来修改之前已被跟踪的`Hello`文件，向其中写入`Hello, Git!`，再来查看文件状态：
<img src=image/2021-02-07_23-05.png>
我们发现，在要提交的变更中以及尚未暂存以备提交的变更(Changes not staged for commit)中，都出现了文件`Hello`。换句话说，文件`Hello`同时出现在暂存区和非暂存区，这是肿么回事捏？

实际上，Git只暂存了我们之前执行`git add`命令时的版本，而不是当前工作目录中的版本。也就是说，暂存区中的`Hello`文件是我们一开始添加的版本，非暂存区中的`Hello`文件是我们修改后的版本。

我们再使用`git add`命令，把工作区的`Hello`文件放到暂存区中：
<img src=image/2021-02-07_23-12.png>
可以看到，这时暂存区的`Hello`已经更新为我们修改后的版本了。


## 查看已暂存和未暂存的修改

`git status`命令只会输出暂存区和工作区的文件，而当你需要查看暂存区和工作区中相同文件（它俩文件名相同但版本不同）的差异，可以使用`git diff`命令：
```bash
git diff 
```
注意到，`git diff`命令只会显示尚未暂存的文件相比暂存区文件的差异，也就是尚未暂存的改动。如果你将所有更新过的文件全部暂存，再运行`git diff`命令，将会什么也没有。

例如，我们在`Hello`文件中添加一行内容`I love Git.`，再执行`git diff`命令：
<img src=image/2021-02-07_23-31.png>
可以看到，我们工作区的`Hello`相比暂存区的`Hello`添加了一行`I love Git.`


## 提交更新

前面说到，暂存区的文件最终将会被提交到Git仓库中，作为一个历史版本。在此之前，请务必确认还有什么已修改或新建的文件还没被`git add`过，否则提交时不会记录这些尚未暂存的变化。

所以，每次提交前，先用`git status`命令查看一下，看你所需要的文件是否都被暂存了，然后再进行提交。

将暂存区的文件提交的命令是：
```bash
git commit
```

<img src=image/2021-02-07_23-44.png>
<img src=image/2021-02-07_23-41.png>

执行之后，会启动你选择的文本编辑器来输入提交说明（你可以指定文本编辑器）。

可以看到，进入编辑器后会在注释行中显示最后一次运行`git status`命令的输出和提示信息，你可以在这个文件`COMMIT_EDITMSG`中输入该次提交说明，你完全可以去掉这些注释行，不过留着也没什么关系。

退出编辑器时，Git会丢弃注释，用你输入的提交说明生成一次提交。

注意到，成功提交后，会显示你在哪个分支（上面是main）提交的，本次提交完整的校验和是什么（上面是54e7424），以及在本次提交中，有多少文件修改过，多少行添加和删改过（上面是1 file changed, 2 insertions(+)）。

另外，你也可以在`git commit`命令后添加`-m`选项，将提交说明与命令放在同一行，这样会更加简便：
```bash
git commit -m '<commit message>'
```

尽管使用暂存区的方式，可以精心准备要提交的细节和内容，但有时这么做略显繁琐。Git提供了一种跳过使用暂存区的方式，在`git commit`命令后添加`-a`选项，Git就会自动把所有已经跟踪的文件暂存起来一并提交，从而跳过`git add`步骤：
```bash
git commit -a -m '<commit message>'
```
这很方便，但要小心，有时这个选项会将不需要的文件添加到提交中。


## 移除已跟踪的文件

要从Git中移除某个被跟踪的文件，或说从暂存区移除。可以使用`git rm`命令：
```bash
git rm <filename>
```
`git rm`命令会**将文件从暂存区移除，并连带在工作目录中删除该文件**，这样**在下一次提交后，该文件就不会出现在未跟踪文件清单中了**。

我们在LearnGit目录下创建文件`Trash`，并跟踪它。

如果只是简单地从工作目录中手动删除文件，运行`git status`命令时，仍然会在非暂存区看到它：
<img src=image/2021-02-08_00-15.png>
可以看到，非暂存区中显示`Trash`文件被删除，但没有被暂存，而暂存区中仍然有`Trash`文件。

如果使用`git rm`命令，我们将会得到：
<img src=image/2021-02-08_00-17.png>
可以看到，`Trash`文件不仅从暂存区中移除，而且它也从本地工作目录中删除了，因为没有现实未被跟踪的文件。

如果我们不小心将不需要纳入版本控制的文件放到了暂存区，必须在`git rm`命令后添加强制删除选项`-f`.

如果我们想把文件从Git仓库中删除（亦即从暂存区移除），但仍然希望保留在当前工作目录中。换句话说，你只是想让Git不再继续跟踪这个文件，从而令这个文件处于未被跟踪的状态。需要在`git rm`命令后添加`--cached`选项：
```bash
git rm --cached <filename>
```

我们在LearnGit目录下创建文件`Remain`，并跟踪它，然后用`git rm --cached`命令解除对它的跟踪：
<img src=image/2021-02-08_00-28.png>


## 移动文件

在Git中对文件改名，需要用`git mv`命令：
```bash的
git mv <filename_old> <filename_new>
```

无须担心重命名带来的文件跟踪方面的问题，Git十分聪明地会识别重命名的文件，而不会将出重命名后的文件认为是一个新文件：
<img src=image/2021-02-08_00-34.png>

实际上，运行`git mv`命令相当于运行了下面3条命令：
```bash
mv HelloGit Hello
git rm HelloGit
git add Hello
```
即使这么分开操作，Git也会意识到这是一次重命名，仍然会得到相同的结果：
<img src=image/2021-02-08_00-38.png>


# 查看提交历史

查看项目的提交历史，需要使用`git log`命令：
```bash
git log
```
在不传入任何参数的情况下，`git log`命令会按时间先后顺序列出所有的提交，最近的更新排在最上面。`git log`命令会列出每个提交的SHA-1校验和，作者和邮箱，提交时间以及提交说明。

我们使用`git log`命令，查看LearnGit的提交历史：
<img src=image/2021-02-08_17-17.png>

另外，`git log`可以附带一些选项，来显示不同结果：

- ```bash
  git log --patch -<log number>
  ```
  `--patch`选项会显示每次提交所引入的差异（按补丁的格式输出）,`-<log number>`选项可以限制显示的日志条目数量。
  <img src=image/2021-02-08_17-26.png>

- ```bash
  git log --stat
  ```
  `--stat`选项会显示每次提交的简略统计信息。包括每次提交中被修改过的文件，有多少文件被修改了，以及被修改的文件有多少行的添加或删除。
  <img src=image/2021-02-08_17-29.png>

- ```bash
  git log --pretty=<suboptions>
  ```
  `--pretty`选项可以使用不同于默认格式的方式显示提交历史，它还有一些内建的子选项供你使用。例如`oneline`会将每个提交放在一行显示。还有比如`short`，`full`，`fuller`，它们显示的信息格式基本一致，只是详细程度不一。
  特别有`format`子选项，可以定制记录的显示格式：
  ```bash
  git log --pretty=format:"<your format>"
  ```

# 撤销操作

在任何一个阶段，你可能都想要撤销某些操作。

## 修补提交

有时候我们提交之后发现漏掉几个文件，或者提交说明写错了。此时，可以运行带有`--amend`选项的命令来重新提交：
```bash
git commit --amend
```
这个命令会将暂存区中的文件提交，如果自上次提交以来你没有做任何修改，那么快照将会保持不变，而你所修改的只是提交信息。
注意到，当你修补提交时，旧有的提交就像从未存在过一样（只会有一个提交），它不会出现在仓库的历史中，这样就不会弄乱你仓库的历史。

我们先修改一下Hello文件，然后将其提交，再使用修补提交命令提交忘记提交的文件Forgotten：
<img src=image/2021-02-09_16-05.png>

## 取消暂存

如果我们想要取消暂存（或取消跟踪）某个暂存区中的文件：
```bash
git restore --staged <filename>
```
这样就可以取消Git对某个文件的跟踪，从而使其变为未跟踪的文件。

## 撤销修改

如果我们不想保留对某个文件的修改，你可以使用下面的命令使其还原为上次提交时的内容（或刚克隆时，或刚将其放入工作目录时）：
```bash
git restore <filename>
```
这样就可以撤销对**工作区**的某个文件做过的修改，注意到这么做不能呢个撤销对暂存区文件的修改，因为暂存区是认为你已经修改好待提交的文件。

记住，在Git中任何**已提交**的东西几乎总是可以恢复的。


# 远程仓库的使用

## 查看远程仓库

如果想要查看你已经配置的远程仓库，可以运行`git remote`命令：
```bash
git remote
```
你也可以添加选项`-v`，会显示需要读写远程仓库使用的Git保存的简写与其对应URL:
```bash
git remote -v
```

<img src=image/2021-02-09_16-51.png>

如果想要查看某个远程仓库的更多信息，可以使用：
```bash
git remote show <remote>
```
例如，查看`origin`，将会得到下面的信息：
<img src=image/2021-02-09_17-26.png>
这些信息十分有用，它告诉你当前处于`main`分支，并且如果运行`git pull`，就会抓取所有的远程引用，然后将远程`main`分支合并到本地`main`分支。它也会列出拉取到的所有远程引用。


## 添加远程仓库

除了用`git clone`命令自动克隆远程仓库，还可以用`git remote add`命令手动添加一个新的远程仓库，同时指定一个方便使用的缩写：
```bash
git remote add <shortname> <url>
```
然后你就可以在命令行中使用简写来代替整个URL。

`git clone`命令会将克隆的仓库自动添加为远程仓库，并默认以`origin`为其简写。

## 从远程仓库拉取

从远程仓库中获取数据：
```bash
git fetch <url/shortname>
```
这个命令会访问远程仓库，从中拉取所有你还没有的数据。执行完成后，你将会拥有那个远程仓库中所有分支的引用，可以随时合并或查看。

注意到，`git fetch`命令只会将数据下载到你的本地仓库——它并不会自动合并或修改你当前的工作。当准备好时你必须手动将其合并入你的工作。

## 推送到远程仓库

当你想分享你的项目时，必须将其推送到上游：
```bash
git push <remote> <branch>
```
`git push`命令会将分支推送到远程服务器，例如：
```bash
git push origin main
```
将会把`main`分支推送到`origin`服务器（克隆时会自动帮你设置好这两个名字），这样就可以将你所做的备份到服务器。

我们将工作区的文件全部推送到远程服务器上：
<img src=image/2021-02-09_17-30.png>
<img src=image/2021-02-09_17-31.png>

Ohhhhhhh~~~，我们在Github上看到了这些推送！！！

我们成功地对本地文件进行了修改和提交，并在Github上备份了它们！！！

## 远程仓库的重命名与删除

远程仓库的重命名：
```bash
git remote rename <oldname> <newname>
```

远程仓库的删除：
```bash
git remote remove <reponame>
```


# 打标签

Git可以给仓库历史中的某一个提交打上标签，以示重要。例如，人们经常使用这个功能来标记发布结点`v1.0`，`v2.0`等等。

## 列出标签

使用`git tag`命令列出标签：
```bash
git tag
```
也可以按照特定的模式查找标签，例如：
```bash
git tag --list "v1.*"
```
这样会列出所有前缀为`v1.`的标签。

## 创建标签

Git支持两种标签：
- 轻量标签(lightweight)
- 附注标签(annotated)

### 附注标签


# 忽略文件

一般我们总会有文件无需纳入Git的管理，也不希望它们出现在未跟踪文件列表。通常都是一些自动生成的文件，如编译链接文件，日志文件。

我们可以创建一个`.gitignore`文件，列出要忽略的文件的模式。

文件`.gitignore`的格式规范如下：
- 所有空行或者以`#`开头的行都会被Git忽略
- 可以使用标准的 glob 模式(shell所使用的简化了的正则表达式）匹配,它会递归地应用在整个工作区中
- 匹配模式可以以`/`开头防止递归，匹配模式可以以`/`结尾指定目录
- 要忽略指定模式以外的文件或目录,可以在模式前加上叹号`!`取反

glob模式常用的有：
- `?`只匹配任意一个字符
- `*`匹配零个或多个任意的字符
- `[]`匹配任意一个列在其中的字符
- `[]`中可以使用`-`分隔两个字符，表示所有在这两个字符范围内的都可以匹配，例如`[0-9]`表示匹配所有0到9的数字
- `**`表示匹配任意中间目录

`.gitignore`的一些例子：
```bash
#忽略所有的 .a 文件
*.a 

#忽略所有的 .o 或 .a 文件
*.[oa]

#但跟踪所有的 lib.a，即使在前面忽略了 .a 文件
*!lib.a

#只忽略当前目录下的名为 test1 的文件
/test1

#忽略任何目录下名为 test2 的文件夹
test2/

#忽略 doc/test3.txt，但不忽略 doc/note/test4.txt
doc/*.txt

#忽略 doc 目录及其所有子目录下的 .pdf 文件
doc/**/*.pdf
```

一般的情况下，一个仓库可能只有根目录下有一个`.gitignore`文件，它递归地应用到整个仓库中。