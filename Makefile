VPATH = ./src
OBJPATH = ./obj/
CC = riscv64-unknown-elf-gcc
CFLAGS = -g -mcmodel=medany -mabi=lp64 -nostartfiles -nostdlib
AS = riscv64-unknown-elf-as
ASFLAGS = -g -mabi=lp64
LD = riscv64-unknown-elf-ld
LDFLAGS =  -Tlinker.ld
OBJS = start.o interrupts.o mutex.o uart.o utils.o main.o
TARGET = test.elf
IDIRS = -I. -I./include

OBJECTS = $(addprefix $(OBJPATH), $(OBJS))

all: obj $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

$(OBJPATH)%.o: %.c
	$(CC) $(CFLAGS) $(IDIRS) -c $< -o $@

$(OBJPATH)%.o: %.s
	$(AS) $(ASFLAGS) -c $< -o $@
	
obj:
	mkdir -p obj	
	
clean:
	rm -rf $(OBJPATH) *.o *.elf $(OBJPATH)
	
run:
	qemu-system-riscv64 -machine sifive_u -nographic -kernel $(TARGET) -bios none 
	
qemudebug: 
	qemu-system-riscv64 -machine sifive_u -nographic -display none -serial mon:stdio -bios none -kernel $(TARGET) -s -S

gdb:
	riscv64-unknown-elf-gdb  $(TARGET)
	  
objdump:
	riscv64-unknown-elf-objdump.exe -f -d $(TARGET)
