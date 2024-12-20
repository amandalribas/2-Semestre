from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.mouse import *
from PPlay.keyboard import *
import game
import config
import utilidades

def main():
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
        if (mouse.is_over_area([350,100], [800,200])) and mouse.is_button_pressed(1): #
            game.main()
        if(mouse.is_over_area([350,270], [800,370])) and mouse.is_button_pressed(1): #dificuldade
            menuDif()
        if(mouse.is_over_area([350,440], [800,540])) and mouse.is_button_pressed(1): #ranking
            rank()
        if(mouse.is_over_area([350,610], [800,710])) and mouse.is_button_pressed(1): #sair
            janela.close()

        background.draw()
        iniciar_buttom.draw()
        dif_buttom.draw()
        rank_buttom.draw()
        sair_buttom.draw()
        janela.update()


def rank():
    janela = Window(1200,844)
    #background = GameImage("images/background.png")
    arquivo = utilidades.ordenaArquivo()
    altura = 100
    fim = 0
    while True:
        #background.draw()

        #janela.draw_text(f"{arquivo[0][0]} {arquivo[0][1]} {arquivo[0][2]}", 10 , altura,size=35, color=(255,255,255))
        if fim<len(arquivo):
            if (len(arquivo)<=5):
                for linha in arquivo:
                    #janela.draw_text(str(linha[0]), 20, 100, size=62, color=(0,0,0), font_name="Arial", bold=False, italic=False)
                    fim += 1
                    janela.draw_text((f'{str(linha[0])} {str(linha[1])} {str(linha[2])}'), 450 , altura ,size=35, color=(255,255,255))
                    altura += 150
            else:
                for i in range (5):
                    #janela.draw_text(str(linha[0]), 20, 100, size=62, color=(0,0,0), font_name="Arial", bold=False, italic=False)
                    fim += 1
                    janela.draw_text((f'{str(arquivo[i][0])} {str(arquivo[i][1])} {str(arquivo[i][2])}'), 450 , altura ,size=35, color=(255,255,255))
                    altura += 150
        janela.update()

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
            game.main()
        if(mouse.is_over_area([350,370], [800,470])) and mouse.is_button_pressed(1): #facil
            config.dificuldade = 2
            game.main()
        if(mouse.is_over_area([350,590], [800,690])) and mouse.is_button_pressed(1): #facil
            config.dificuldade = 3
            game.main()

        background.draw()
        facil_buttom.draw()
        medio_buttom.draw()
        dificil_buttom.draw()
        janela.update()
