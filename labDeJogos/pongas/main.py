from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.collision import*


def inicial(pad1,pad2,bola):
    pad1.set_position(15, (janela.height - pad1.height) / 2)
    pad2.set_position(janela.width - 15 - pad2.width,(janela.height - pad2.height) / 2)
    bola.set_position(janela.width / 2 - bola.width/2, janela.height/2)


janela = Window(900, 500)
background = GameImage("pongas/background.png")
#bola = GameImage("bola.png")
bola = Sprite("pongas/ball.png")
pad1 = GameImage("pongas/barra.png")
pad2 = GameImage("pongas/barra.png")
gol = False

teclado = Window.get_keyboard()
tela = Window.get_screen()

janela.set_title('Pongas')

velx = vely = 0.3 
lado1 = 0
lado2 = 0
inicial(pad1,pad2,bola)


while True:

    bola.y += vely
    bola.x += velx
    #velocidade ao encostar
    if bola.y >= (janela.height - bola.height) or bola.y <= 0:
        vely = - vely
        if vely < 0:
            vely += -0.005
        else:
            vely += 0.005
    if bola.x >= (janela.width - bola.width) or bola.x <= 0:
        velx = - velx


    #movendo a barra no KeyBoard
    if teclado.key_pressed("up") and  (pad1.y >= 0):
        pad1.y -= 0.3
    if teclado.key_pressed("down") and (pad1.y <= janela.height - pad1.height):
        pad1.y += 0.3

    #movendo a Barra Automaticamente
    if (bola.y <= janela.height/3 or bola.y <= 0.6*janela.height) and (pad2.y >= 0):
        pad2.y -= 0.15
    if (bola.y > janela.height*0.6 or pad2.y >= janela.height) and pad2.y <= janela.height - pad2.height:
        pad2.y += 0.15

    #colisao -------
    #colisao do lado esquerdo
    if Collision.collided(bola, pad1):
        velx = - velx
        vely = - vely

        if vely < 0:
            vely += -0.005
        else:
            vely += 0.005

    #colisao do lado direito
    if Collision.collided(bola,pad2):
        velx = - velx
        vely = - vely

        if vely < 0:
            vely += -0.005
        else:
            vely += 0.005


    #tratar o "gol"
    if bola.x <= 1:
        lado2 += 1
        vely = 0
        velx = 0
        gol = True
        inicial(pad1,pad2,bola)


    if bola.x >= janela.width - bola.width:
        lado1 += 1
        vely = 0
        velx = 0
        gol = True
        inicial(pad1,pad2,bola)

    if gol:
         if (teclado.key_pressed('space')):
            bola.set_position(janela.width / 2, janela.height/2)
            vely = 0.3
            velx = 0.3

    background.draw()
    bola.draw()
    pad1.draw()
    pad2.draw()
    janela.draw_text(str(lado1), janela.width/2 - bola.width/2, 50, 80, (255,255,0), font_name="Arial")
    janela.draw_text(str(lado2), janela.width/2 + bola.width/2, 50, 80, (255,255,0), font_name="Arial")

    janela.update()