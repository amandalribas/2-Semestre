from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *

def criaMatriz(matriz, lMonstro=3, cMonstro=5):
    yInicial = 100
    for i in range(lMonstro):
        distanciaX = 0
        xInicial = 200
        linha = []
        for j in range (cMonstro):
            enemy = Sprite("images/enemy1.png")
            enemy.x = xInicial + distanciaX
            enemy.y = yInicial + i*1.5*enemy.height
            distanciaX += enemy.width + enemy.width/2
            linha.append(enemy)
        matriz.append(linha)
    return matriz

def desenhaMatriz(matriz):
    for linha in matriz:
        for sprite in linha:
            sprite.draw()

def updateMonstro(matriz, spaceship, janela, speedX,speedY):
    inverte = False
    for linha in matriz:
        for sprite in linha:
            sprite.move_x(speedX * janela.delta_time()) 
            if (sprite.x < 0.1*sprite.width):
                sprite.x = 0.1*sprite.width
                inverte = True
            elif(sprite.x >= janela.width - sprite.width - (0.1*sprite.width)):
                sprite.x = janela.width - sprite.width - (0.1*sprite.width)
                inverte = True
    if inverte:
        speedX = -speedX
        for l in matriz:
                    for s in l:
                        if (s.y < spaceship.y - s.height):
                            s.move_y(speedY)
        
    return speedX