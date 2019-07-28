#
#	FreeRTOS portable layer for RaspberryPi
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/RaspberryPi/port.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/RaspberryPi/portisr.o

#
#	FreeRTOS Core
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/croutine.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/list.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/queue.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/tasks.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/event_groups.o

#
#	Interrupt Manager & GPIO Drivers
#
OBJECTS += $(BUILD_DIR)Drivers/interrupts.o
OBJECTS += $(BUILD_DIR)Drivers/gpio.o

$(BUILD_DIR)FreeRTOS/Source/portable/GCC/RaspberryPi/port.o: CFLAGS += -I $(BASE)Demo/

#
#	Selected HEAP implementation for FreeRTOS.
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/MemMang/heap_4.o

#
#	Startup and platform initialisation code.
#
OBJECTS += $(BUILD_DIR)Demo/startup.o


#
#	Main Test Program
#
OBJECTS += $(BUILD_DIR)Demo/main.o

#things
#OBJECTS += $(BUILD_DIR)Drivers/mailbox.o
#OBJECTS += $(BUILD_DIR)Demo/trace.o
OBJECTS += $(BUILD_DIR)Drivers/mem.o
OBJECTS += $(BUILD_DIR)Drivers/aux.o
OBJECTS += $(BUILD_DIR)Drivers/uart.o
#OBJECTS += $(BUILD_DIR)Drivers/pwm.o
#OBJECTS += $(BUILD_DIR)Drivers/spi.o
#OBJECTS += $(BUILD_DIR)Drivers/i2c.o
#OBJECTS += $(BUILD_DIR)Drivers/pcm.o
#OBJECTS += $(BUILD_DIR)Drivers/emmc.o
#OBJECTS += $(BUILD_DIR)Drivers/slave.o

#video stuff
#OBJECTS += $(BUILD_DIR)Drivers/video.o

#smsc9514 (LAN and USB)
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/uspibind.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/uspilibrary.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhcidevice.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhciregister.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhcixferstagedata.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbconfigparser.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbdevice.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbdevicefactory.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbendpoint.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbrequest.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbstandardhub.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/devicenameservice.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/macaddress.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/smsc951x.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/string.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/util.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbmassdevice.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhciframeschednper.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhciframeschedper.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/keymap.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbkeyboard.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhcirootport.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbmouse.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/dwhciframeschednsplit.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbgamepad.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/synchronize.o
#OBJECTS += $(BUILD_DIR)Drivers/lan9514/lib/usbstring.o

#freeRTOS-TCP
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_ARP.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_DHCP.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_DNS.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_IP.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_Sockets.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_Stream_Buffer.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_TCP_IP.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_TCP_WIN.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/FreeRTOS_UDP_IP.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/portable/BufferManagement/BufferAllocation_2.o
#OBJECTS += $(BUILD_DIR)Drivers/FreeRTOS-Plus-TCP/portable/NetworkInterface.o
