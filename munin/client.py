import pygame
import socket
import time

sock = socket.socket()

host = "192.168.1.22" #ESP32 IP in local network
port = 80             #ESP32 Server Port

sock.connect((host, port))

pygame.init()
done = False
pygame.joystick.init()

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    joystick_count = pygame.joystick.get_count()
    for i in range(joystick_count):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()
        x = int(round(joystick.get_axis(0), 1) * 100)
        y = int(round(joystick.get_axis(1), 1) * 100)
        z = int(round(joystick.get_axis(2), 1) * 100)
        print('{},{},{};'.format(x, y, z).encode())
        sock.send('{},{},{};'.format(x, y, z).encode())
        time.sleep(0.1)
pygame.quit()
sock.close()
