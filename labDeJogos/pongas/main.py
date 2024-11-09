from PPlay.gameimage import GameImage
from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.collision import*


def inicial(pad1,pad2,bola):
    pad1.set_position(15, (janela.height - pad1.height) / 2)
    pad2.set_position(janela.width - 15 - pad2.width,(janela.height - pad2.height) / 2)
    bola.set_position(janela.width / 2 - bola.width/2, janela.height/2)

def padPos(p1,p11,p2,p21):
    p1.set_position(15, pad1.y)
    p11.set_position(15, 180 + pad1.y)
    p2.set_position(janela.width - 15 - pad2.width, pad2.y)
    p21.set_position(janela.width - 15 - pad2.width, 180 + pad2.y)

def inveterY(vY):
    vY = - vY
    if vY < 0:
        vY += -0.003
    else:
        vY += 0.003
    return vY

janela = Window(900, 500)
background = GameImage("background.png")
#bola = GameImage("bola.png")
bola = Sprite("ball.png")

pad1 = Sprite("barra.png")
pad2 = Sprite("barra.png")

#pad1 = GameImage("barra.png")
#pad2 = GameImage("barra.png")
gol = False

pad11 = Sprite("barraP.png")
pad12 = Sprite("barraP.png")

pad21 = Sprite("barraP.png")
pad22 = Sprite("barraP.png")

teclado = Window.get_keyboard()
tela = Window.get_screen()

janela.set_title('Pongas')

velx = vely = 0.3
lado1 = 0
lado2 = 0
inicial(pad1,pad2,bola)
colisao = 0

while True:

    bola.y += vely
    bola.x += velx
    #velocidade ao encostar
    if bola.y >= (janela.height - bola.height) or bola.y <= 0:
        vely = - vely
        if vely < 0:
            vely += -0.003
        else:
            vely += 0.003
    if bola.x >= (janela.width - bola.width) or bola.x <= 0:
        velx = - velx


    #movendo a barra no KeyBoard
    if teclado.key_pressed("up") and  (pad1.y >= 0):
        pad1.move_key_y(0.3)
    if teclado.key_pressed("down") and (pad1.y <= janela.height - pad1.height):
        pad1.move_key_y(0.3)

    #movendo a Barra Automaticamente
    if (bola.y <= janela.height/3 or bola.y <= 0.6*janela.height) and (pad2.y >= 0):
        pad2.y -= 0.25
    if (bola.y > janela.height*0.6 or pad2.y >= janela.height) and pad2.y <= janela.height - pad2.height:
        pad2.y += 0.25

    #colisao -------
    #colisao do lado esquerdo
    if Collision.collided(bola, pad1):
        colisao += 1
        velx = - velx
        vely = inveterY(vely)


    #colisao do lado direito
    if Collision.collided(bola,pad2):
        colisao += 1
        velx = - velx
        vely = inveterY(vely)

    #prova
    if colisao == 3:
        velx = - velx
        vely = inveterY(vely)
        pad1.hide()
        pad2.hide()
        pad11.unhide()
        pad12.unhide()
        pad21.unhide()
        pad22.unhide()
        padPos(pad11,pad12,pad21,pad22)

    elif colisao <3:
        pad1.unhide()
        pad2.unhide()
        pad11.hide()
        pad12.hide()
        pad21.hide()
        pad22.hide()
    if colisao >= 3:
        if teclado.key_pressed("up") and (pad11.y >= 0):
            pad11.move_key_y(0.3)
            pad12.move_key_y(0.3)
        if teclado.key_pressed("down") and (pad12.y <= janela.height - pad1.height):
            pad11.move_key_y(0.3)
            pad12.move_key_y(0.3)
        if (bola.y <= janela.height / 3 or bola.y <= 0.6 * janela.height) and (pad21.y >= 0) and (pad22.y >= 0): #padIA
            pad21.y -= 0.3
            pad22.y -= 0.3
        if (bola.y > janela.height * 0.6 or pad2.y >= janela.height) and pad2.y <= janela.height - pad2.height: # padIA
            pad21.y += 0.3
            pad22.y += 0.3
        if Collision.collided(bola, pad11):
            colisao += 1
            velx = - velx
            vely = inveterY(vely)

        if Collision.collided(bola, pad12):
            colisao += 1
            velx = - velx
            vely = inveterY(vely)

        if Collision.collided(bola, pad21):
            colisao += 1
            velx = - velx
            vely = inveterY(vely)

        if Collision.collided(bola, pad22):
            colisao += 1
            velx = - velx
            vely = inveterY(vely)

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
            colisao = 0
            bola.set_position(janela.width / 2, janela.height/2)
            vely = 0.3
            velx = 0.3

    #prova

    background.draw()
    bola.draw()
    pad1.draw()
    pad2.draw()
    pad11.draw()
    pad12.draw()
    pad21.draw()
    pad22.draw()
    janela.draw_text(str(lado1), janela.width/2 - bola.width/2, 50, 80, (255,255,0), font_name="Arial")
    janela.draw_text(str(lado2), janela.width/2 + bola.width/2, 50, 80, (255,255,0), font_name="Arial")

    janela.update()