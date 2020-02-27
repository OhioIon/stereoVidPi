# stereoVidPi
Displays two analog video streams on Oculus Rift CV1 connected to Raspberry Pi 4

<b>Before you start</b>
- Please note that the riftDriverPi application should be compiled and started first
- It will activate the Oculus Rift as extended display
- Follow the instructions on: https://github.com/OhioIon/riftDriverPi
- In case you already see the Rapbian desktop through the Oculus Rift CV1... continue

<b>How to compile the software</b>
- Start RPi 4 and open a terminal
- Execute the following commands

```shell
sudo apt install qt5-default qtmultimedia5-dev libqt5multimedia5-plugins
git clone --recurse-submodules https://github.com/OhioIon/stereoVidPi
cd stereoVidPi
qmake
make
```

<b>Hardware setup</b>

- Connect two video devices to the USB 2 ports of the RPi 4
- The cameras should be spaced 6 cm / 2.36 inch appart (average interpupillary distance) and should face into the same direction (i.e. parallel to each other)

Example setup:
- Two CMOS cameras
- Two 5.8 GHz video transmitters
- Two 5.8 GHz video receivers
- Two USB analog video capture devices (e.g. EasyCAP DC60 / Fushicai USBTV007)
