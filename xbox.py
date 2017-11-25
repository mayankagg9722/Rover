import pygame

import sys
import time
import socket
import cPickle as pickle
 
UDP_IP = "192.168.43.207"
UDP_PORT = 8080
MESSAGE = "Hello, World!"
 
print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT
print "message:", MESSAGE

#  MESSAGE = pickle.dumps(["1","2"])


sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) 

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
x='2'
y='3'

 
class TextPrint(object):
    def __init__(self):

        self.reset()
        self.x_pos = 10
        self.y_pos = 10
        self.font = pygame.font.Font(None, 20)
 
    def print1(self, my_screen, text_string):
        text_bitmap = self.font.render(text_string, True, BLACK)
        my_screen.blit(text_bitmap, [self.x_pos, self.y_pos])
        self.y_pos += self.line_height
 
    def reset(self):
        self.x_pos = 10
        self.y_pos = 10
        self.line_height = 15
 
    def indent(self):
        self.x_pos += 10
 
    def unindent(self):
        self.x_pos -= 10
 
 
pygame.init()
size = [500, 700]
screen = pygame.display.set_mode(size)
 
pygame.display.set_caption("My Game")
done = False
clock = pygame.time.Clock()
pygame.joystick.init()
textPrint = TextPrint()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")
    screen.fill(WHITE)
    textPrint.reset()
 
    joystick_count = pygame.joystick.get_count()

    for i in range(joystick_count):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()


        axes = joystick.get_numaxes()
        textPrint.print1(screen, "Number of axes: {}".format(axes) )
        textPrint.indent()
       
        for i in range( axes):
            if(i==0 or i==1):
                axis = joystick.get_axis( i )
                textPrint.print1(screen, "Axis {} value: {:>6.3f}".format(i, axis) )
                # if(axis>0.01 or axis<0):
                #     print axis
        textPrint.unindent()

        buttons = joystick.get_numbuttons()
        
        for i in range(buttons):
            button = joystick.get_button(i)         
            if(i==0 or i==1 or i==2 or i==3 or i == 11 or i==12 or i==13 or i==14):                
                if(button==1):
                    print i,button
                    MESSAGE = pickle.dumps([i,button])
                    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
                textPrint.print1(screen, "Button {:>2} vsalue: {}".format(i, button))
        textPrint.unindent()
 
    pygame.display.flip()

    clock.tick(10000)
 
pygame.quit()
