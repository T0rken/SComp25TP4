obj-m +=  hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
    # Sign the module
	sudo /usr/src/linux-headers-$(shell uname -r)/scripts/sign-file sha256 MOK.priv MOK.der hello.ko

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# Install the kernel module to the default modules directory
install:
	install -p -m 644 hello.ko /lib/modules/$(shell uname -r)/kernel/drivers/misc/
	depmod -a

# Create a package using checkinstall
package: all
	sudo checkinstall --pkgname=hello-world --pkgversion=1.0 --provides=hello --nodoc