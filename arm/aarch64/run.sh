qemu-system-aarch64 -machine virt -cpu cortex-a57 -machine type=virt -nographic -smp 1 -m 512 -kernel ./aarch64-linux-3.15rc2-buildroot.img  --append "console=ttyAMA0"
