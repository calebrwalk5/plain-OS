mkdir -p img
mkdir -p img/boot
cp kernel.bin img/boot/kernel.bin
mkdir -p img/boot/grub
cp grub.cfg img/boot/grub/grub.cfg
grub-mkrescue -o kernel.iso img
