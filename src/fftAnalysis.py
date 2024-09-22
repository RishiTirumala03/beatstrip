import os; os.system('cls'); 
import serial
import pyaudio
import sounddevice as sd
import struct
import numpy as np
import matplotlib.pyplot as plt

CHUNK = 1024 * 4
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100

p = pyaudio.PyAudio()
arduino = serial.Serial(port='COM3',baudrate=9600,timeout=0.1)
stream = p.open(
    format=FORMAT,
    channels=CHANNELS,
    rate=RATE,
    input=True,
    output=True,
    input_device_index=5,
    frames_per_buffer = CHUNK
)
fig,(ax,ax1) = plt.subplots(2)
x_fft = np.linspace(0,RATE,CHUNK)
x = np.arange(0, CHUNK * 2, 2)
line, = ax.plot(x, np.random.rand(CHUNK),'r')
line_fft, = ax1.semilogx(x_fft,np.random.rand(CHUNK))
ax.set_ylim(-60000,60000)
ax.set_xlim(0,CHUNK)
ax1.set_ylim(0,1)
ax1.set_xlim(20,RATE/2)
fig.show()
while 1:
    data = stream.read(CHUNK)
    data_int = struct.unpack(str(CHUNK) + 'h', data)
    line.set_ydata(data_int)
    fft_data = (np.abs(np.fft.fft(data_int))*2/(33000 * CHUNK))
    line_fft.set_ydata(fft_data)
    Msg = round(np.max(fft_data[0:15])*100)
    if(Msg>=40):
        print(str(Msg))

    else:
        print(Msg)
    arduino.write(bytes(str(Msg), 'utf-8'))
    #msgRD = arduino.readline()
    #msgRD = msgRD.decode('utf-8')
    #print(f'Read message from Arduino: {msgRD}\n')
    fig.canvas.draw()
    fig.canvas.flush_events()
