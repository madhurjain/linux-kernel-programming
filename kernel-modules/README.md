Kernel Modules
==============

Compile Module `make`
Install Kernel Module `sudo insmod module_name.ko`
Remove Kernel Module `sudo rmmod module_name`
Check Loaded Kernel Modules `lsmod`

### Force Remove Kernel Module (for debugging)
Enable Force Removal when compiling kernel using option `CONFIG_MODULE_FORCE_UNLOAD`
Then use `sudo rmmod -f module_name`

Reference Link-
http://www.tldp.org/LDP/lkmpg/2.6/html/index.html
