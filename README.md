# Snobby Cloud
Linux on the 2018 Hackaday Supercon Badge (PIC32MX370F512L)

This uses the Firmware written by [Jaromir Sukuba](https://github.com/jaromir-sukuba) provided by [Hackaday](https://github.com/Hack-a-Day/basic-badge).

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
- cat

Commands to Add: (in order of how likely it is to be added)
- mkdir
- rmdir
- pwd
- cd
- mv
- cp

- man

- tail
- grep
- df
- whoami
