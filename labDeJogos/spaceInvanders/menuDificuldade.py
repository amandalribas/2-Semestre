from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.mouse import *
import game

def menuDif():
    
    janela = Window(1200, 844)
    background = GameImage("images/background.png")
    facil_buttom = GameImage("buttom/facil.png")
    medio_buttom = GameImage("buttom/medio.png")
    dificil_buttom = GameImage("buttom/dificil.png")
    mouse = Window.get_mouse()


    facil_buttom.set_position(350,150)
    medio_buttom.set_position(350,370)
    dificil_buttom.set_position(350,590)
    while True:
        janela.set_title("DIFICULDADE")
        
        if(mouse.is_over_area([350,150], [800,250])) and mouse.is_button_pressed(1): #facil
            game.game()
        if(mouse.is_over_area([350,370], [800,470])) and mouse.is_button_pressed(1): #facil
            game.game(2)
        if(mouse.is_over_area([350,590], [800,690])) and mouse.is_button_pressed(1): #facil
            game.game(3)

        background.draw()
        facil_buttom.draw()
        medio_buttom.draw()
        dificil_buttom.draw()
        janela.update()

