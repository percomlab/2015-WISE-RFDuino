# 2015-WISE-RFDuino

BlueZ安裝

	sudo apt-get install libdbus-1-dev libdbus-glib-1-dev libglib2.0-dev libical-dev libreadline-dev libudev-dev libusb-dev make

	mkdir -p work/bluepy

cd work/bluepy

wget https://www.kernel.org/pub/linux/bluetooth/bluez-5.11.tar.xz

xz -d bluez-5.11.tar.xz

tar xvf bluez-5.11.tar

cd bluez-5.11

./configure --disable-systemd

Make

sudo make install

確認Usb

hciconfig 

如果看到

hci0:	Type: BR/EDR  Bus: USB

	BD Address: 00:02:72:14:27:0E  ACL MTU: 1021:8  SCO MTU: 64:1
	
	DOWN 
	
	RX bytes:2715 acl:1 sco:0 events:146 errors:0
	
	TX bytes:2500 acl:0 sco:0 commands:133 errors:0
則將它開啟

sudo hciconfig hci0 up

掃描附近裝置(若有的話會得到xx:xx:xx:xx:xx:xx的位址)

sudo hcitool lescan

使用gatttool連接裝置

sudo gatttool -b xx:xx:xx:xx:xx:xx -t random --interactive
connect
char-desc

接收rfduino資料

char-write-req 0x000f 0100 –listen
