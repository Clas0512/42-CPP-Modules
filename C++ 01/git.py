import subprocess as shell

commitName = input("Commit Name: ")

commitSentence = "git commit -m \"" + commitName + "\""

shell.call("git add .", shell=True)
shell.call(commitSentence, shell=True)
shell.call("git push", shell=True)

