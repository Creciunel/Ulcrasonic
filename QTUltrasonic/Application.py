from PyQt5 import QtWidgets, uic
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice

# initial
serial = QSerialPort()
serial.setBaudRate(9600)
portList = []
portDesc = []
# Data path
# 0 - start/stop
# status = ""
# # 1 - on time
# onTimes = ""
# # 2 - total time
# periods = ""

# Outpud data
dataOutS = ""
dataOutT = ""
dataOutP = ""

# list of port
ports = QSerialPortInfo().availablePorts()

for port in ports:
    portList.append(port.portName())
    portDesc.append(port.description())


# function
def serialConect():
    serial.setPortName(ui.listS.currentText())
    serial.open(QIODevice.ReadWrite)
    print("COM PORT: " + str(ui.listS.currentText()))
    print('connect')


def serialDisconect():
    serial.close()
    print("disconnect")


def onRead():
    rx = serial.readLine()
    rxs = str(rx, "utf-8")
    print(rxs)


def onTime():
    onTimes = ui.iText.displayText()
    with open('readme.txt', 'a') as f:
        f.write("On time: "+onTimes)
    res = "t" + onTimes
    serial.write(res.encode())



def period():
    periods = ui.iText_2.displayText()
    with open('readme.txt', 'a') as f:
        f.write(" Off time: " + periods)
    res = "p" + periods
    serial.write(res.encode())


def startWork():
    f = open("readme.txt", "r")
    ui.out.setText(f.read() + "\n Now work")
    with open('readme.txt', 'w') as f:
        f.write("")
    serial.write('s1'.encode())



def stopWork():
    f = open("readme.txt", "r")
    ui.out.setText(f.read() + "\n Don't work")
    with open('readme.txt', 'w') as f:
        f.write("")
    serial.write('s0'.encode())


# show ui
app = QtWidgets.QApplication([])
ui = uic.loadUi("DesignApp.ui")
ui.setWindowTitle("Ultrasonic generator control")

ui.listS.addItems(portList)
ui.listDesc.addItems(portDesc)
# ui.listS.currentIndexChanged.connect(ui.listS.clear)
ui.conectS.clicked.connect(serialConect)
ui.disconectS.clicked.connect(serialDisconect)
ui.start.clicked.connect(startWork)
ui.Stop.clicked.connect(stopWork)
ui.Period.clicked.connect(period)
ui.onTime.clicked.connect(onTime)

serial.readyRead.connect(onRead)

ui.show()
app.exec()
