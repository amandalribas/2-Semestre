from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.sprite import *


janela = Window(900, 500)
cenario = GameImage("pong/teste.png")
bola = GameImage("pong/ball.png")
barraDir = GameImage("pong/barra.png")
barraEsq= GameImage("pong/barra.png")

velx = vely = 0.2

while True:
    barraDir.x = 20
    barraDir.y = (janela.height - barraDir.height)/2
    #barraDir.move_key_y(100)
    barraEsq.x = janela.width - 20 - barraEsq.width
    barraEsq.y = (janela.height - barraEsq.height)/2


    bola.y += vely
    bola.x += velx
    if bola.y >= (janela.height - bola.height) or bola.y <= 0:
        vely = - vely
        if vely < 0:
            vely += -0.005
        else:
            vely += 0.005
    if bola.x >= (janela.width - bola.width) or bola.x <= 0:
        velx = - velx

    #janela.draw_text("PONG", 385, 50, 50, (255,255,255), font_name="Arial")
    cenario.draw()
    bola.draw()
    barraDir.draw()
    barraEsq.draw()
    janela.update()
