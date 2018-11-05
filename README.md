# Snobby Cloud
Linux on the 2018 Hackaday Supercon Badge (PIC32MX370F512L)

This uses the Firmware written by [Jaromir Sukuba](https://github.com/jaromir-sukuba) provided by [Hackaday](https://hackaday.com "hackaday.com"):

[Supercon Badge Firmware](https://github.com/Hack-a-Day/2018-Supercon-Badge "Github")

[Belgrade Badge Firmware](https://github.com/Hack-a-Day/basic-badge "Github")

## Features
Interfaces with a I2C flash controller for filesystem

This is more of a filesystem navigation emulator for now because it doesnt have support for a lot of core linux stuffs

Supported Commands:
- clear
- echo
- rm
- touch
- ls
- write
- find
- cat // still a WIP
- help

Commands to Add: (in order of how likely it is to be added)
- mkdir
- rmdir
- pwd
- cd
- mv
- cp

- tail
- grep
- df
- whoami
