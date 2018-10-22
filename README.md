# Snobby Cloud
Linux on the 2018 Hackaday Supercon Badge (PIC32MX370F512L)

This uses the Firmware written by [Jaromir Sukuba](https://github.com/jaromir-sukuba) provided by [Hackaday](https://github.com/Hack-a-Day/basic-badge).

## Features
Interfaces with a I2C flash controller for filesystem

This is more of a filesystem navigation emulator for now because it doesnt have support for a lot of core linux stuffs

Supported Commands:
- echo
- clear
- mkdir
- rmdir
- pwd
- cd
- rm
- mv
- ls
- cp
- cat
- man

Commands to Add: (in order of how likely it is to be added)
- touch
- tail
- grep
- find/locate
- df
- whoami
