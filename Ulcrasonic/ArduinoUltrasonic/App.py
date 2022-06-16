import serial.tools.list_ports
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.stacklayout import StackLayout
from kivy.lang import Builder
import time

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

writeData = {}

class MyApp(App):
    def showPort(self):
        self.portlist = []
        self.box = StackLayout(spacing=5, padding=10)
        self.label = Label(size_hint=(1, 0.25),
                           width=50,
                           color=(1, 1, .3, 1))

        for i in ports:
            print(str(i))
            self.portlist.append(str(i))
            self.label.text += str(i) + "\n"

        self.textinput = TextInput(text='',
                                   size_hint=(1, 0.15),
                                   multiline=False)
        self.btn = Button(text="PORT",
                          size_hint=(0.2, 0.1),
                          on_press=self.answer)
        self.btn1 = Button(text="ON TIME",
                           size_hint=(0.2, 0.1),
                           on_press=self.onTime)
        self.btn2 = Button(text="OFF TIME",
                           size_hint=(0.2, 0.1),
                           on_press=self.offTime)
        self.btn3 = Button(text="Start",
                           size_hint=(0.2, 0.1),
                           on_press=self.start)
        self.btn4 = Button(text="Stop", size_hint=(0.2, 0.1))

        self.box.add_widget(self.label)
        self.box.add_widget(self.textinput)
        self.box.add_widget(self.btn)
        self.box.add_widget(self.btn1)
        self.box.add_widget(self.btn2)
        self.box.add_widget(self.btn3)
        self.box.add_widget(self.btn4)

        return self.box

    def answer(self, btn):
        self.label.text = "Selected PORT is: " + self.textinput.text

        for i in range(0, len(self.portlist)):
            if self.portlist[i].startswith("COM" + str(self.textinput.text)):
                portVal = "COM" + str(self.textinput.text)
                print(self.portlist[i])

        serialInst.baudrate = 9600
        serialInst.port = portVal
        serialInst.open()

        self.label1 = Label(size_hint=(1, 0.25),
                           width=50,
                           color=(1, 1, .3, 1))
        self.box.add_widget(self.label1)
        self.box.remove_widget(self.btn)

    def onTime(self, btn1):
        self.label.text = "Selected time on is: " + self.textinput.text
        writeData.update({"on": self.textinput.text})

    def offTime(self, btn2):
        self.label.text = "Selected time off is: " + self.textinput.text
        writeData.update({"off": self.textinput.text})

    def start(self, btn3):
        self.label.text = "Start"
        writeData.update({"start": 0})

        # self.label2 = Label(size_hint=(1, 0.25),
        #                     width=50,
        #                     color=(1, 1, .3, 1))
        # second = time.thread_time_ns()
        # self.label2.text = str(second)
        # self.box.add_widget(self.label2)

    def build(self):
        return self.showPort()


def serialF():
    for i in ports:
        portlist.append(str(i))
        print(str(i))

    inPort = input("Serial port COM: ")
    print(inPort)

    for i in range(0, len(portlist)):
        if portlist[i].startswith("COM" + str(inPort)):
            portVal = "COM" + str(inPort)
            print(portlist[i])

    serialInst.baudrate = 9600
    serialInst.port = portVal
    serialInst.open()

    while True:
        if serialInst.inWaiting():
            pack = serialInst.readline()
            print(pack.decode("utf").rstrip('\n'))


if __name__ == "__main__":
    MyApp().run()
    # serialF()
