Compiling Linux Kernel on Ubuntu 14.04
======================================
- Download and Extract Kernel Source from kernel.org
  `wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.6.tar.xz`
  `tar -xf linux-4.6.tar.xz`

- Install dependencies
``sudo apt-get build-dep linux-image-`uname -r```

- Install OpenSSL dev packages
`sudo apt-get install libssl-dev`

- Install make-kpkg (optional)
`sudo apt-get install kernel-package`

- Install libcurses for text menuconfig
`sudo apt-get install libncurses5 libncurses5-dev`

- Install QT tools for graphical menuconfig (optional)
`sudo apt-get install qt3-dev-tools libqt3-mt-dev`

- Switch to your kernel source directory
`cd ~/linux-4.6`

- Clean everything (optional)
`make mrproper`

- Reuse config of currently running kernel
`cp -vi /boot/config-`uname -r` .config`

- Configure drivers and modules to be included. Ignore the symbol value 'm' invalid warnings
`make menuconfig`

- Compile Kernel (-j is number of jobs)
`make -j4`
`make -j4 modules`
or
`make -j4 all`

- Install Modules
`sudo make modules_install`

- Install Kernel Image and Update GRUB
`sudo make install`

- Or use make-kpkg (N is number of CPUs to use)
`make-kpkg -j N --initrd --append-to-version=my-version kernel-image kernel-headers`
