from PPlay.window import *
from PPlay.keyboard import *
import menu


def game(dif = 1):
    janela = Window(1200, 844)
    teclado = Window.get_keyboard()
    while True:
        if (teclado.key_pressed("esc")):
            menu.menu()    
        janela.update()
