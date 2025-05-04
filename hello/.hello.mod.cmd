savedcmd_/home/nawres/hello/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/nawres/hello/"$$0) }' > /home/nawres/hello/hello.mod
