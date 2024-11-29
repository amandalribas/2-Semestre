from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.mouse import *
from PPlay.keyboard import *
import menuDificuldade
import game

def menu():
    janela = Window(1200, 744)
    background = GameImage("images/background.png")
    iniciar_buttom = GameImage("buttom/iniciar.png")
    dif_buttom = GameImage("buttom/dificuldade.png")
    rank_buttom = GameImage("buttom/ranking.png")
    sair_buttom = GameImage("buttom/sair.png")

    mouse = Window.get_mouse()

    #posicao Incicial
    iniciar_buttom.set_position(350,100)
    dif_buttom.set_position(350,270)
    rank_buttom.set_position(350,440)
    sair_buttom.set_position(350,610)


    while True:
        janela.set_title("MENU")
        if (mouse.is_over_area([350,100], [800,200])) and mouse.is_button_pressed(1): #iniciar
            game.game()
        if(mouse.is_over_area([350,270], [800,370])) and mouse.is_button_pressed(1): #dificuldade
            menuDificuldade.menuDif()
        #if(mouse.is_over_area([350,490], [800,590])) and mouse.is_button_pressed(1): #ranking
        if(mouse.is_over_area([350,440], [800,540])) and mouse.is_button_pressed(1): #sair
            janela.close()

        background.draw()
        iniciar_buttom.draw()
        dif_buttom.draw()
        rank_buttom.draw()
        sair_buttom.draw()
        janela.update()

