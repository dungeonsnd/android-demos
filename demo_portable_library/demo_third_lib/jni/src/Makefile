

TOOLCHAIN_PATH = $(NDK_ROOT)/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
CC = $(TOOLCHAIN_PATH)/arm-linux-androideabi-gcc
LD = $(TOOLCHAIN_PATH)/arm-linux-androideabi-ld
AR = $(TOOLCHAIN_PATH)/arm-linux-androideabi-ar

CFLAGS = -I $(NDK_ROOT)/platforms/android-19/arch-arm/usr/include
LDFLAGS = -L $(NDK_ROOT)/platforms/android-19/arch-arm/usr/lib


all:
	$(CC) -O2 -fPIC -c $(CFLAGS) $(LDFLAGS) add.c -o add.o
	$(CC) -O2 -fPIC -c $(CFLAGS) $(LDFLAGS) main.c -o main.o
	#$(LD) -o libthirdlib.so main.o add.o -shared
	$(AR) -crv libthirdlib.a main.o add.o
	mkdir -p ../../libs/armeabi/
	mv libthirdlib.a ../../libs/armeabi/

	rm -rf *.o
