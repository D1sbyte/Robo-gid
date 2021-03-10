import serial
from port import serial_ports, speeds


ports = serial_ports()
speeds_ = speeds



def connect(port ,speed):
    try:
            realport = serial.Serial(port, speed)
            return realport
    except Exception as e:
            print(e)

def send(realport,command):
    if realport:
        if command == 'enable':
            realport.write(b'e')
            print('вкл')
        elif command == 'disable':
            realport.write(b'd')
            print('выкл')
        elif command == 'blink':
            realport.write(b'b')
            print('Мигание')



def main():
    for i in range(len(ports)):
        print('-- ' + str(i) + ' - ' + ports[i])

    port = ports[int(input())]
    print('Выбран порт '+ port)

    for i in range(len(speeds_)):
        print('-- ' + str(i) + ' - ' + speeds_[i])

    speed = speeds_[int(input())]
    print('Выбрана скорость '+ str(speed))

    realport = connect(port, speed)
    while(True):
        send(realport, input('Введите команду '))


if __name__ == '__main__':
    main()
