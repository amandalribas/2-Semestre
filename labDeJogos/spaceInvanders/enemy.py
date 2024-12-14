from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import config
import random


def posInicialTiro(player,shots):
    shot = Sprite("images/shot.png")
    shot.x = player.x + player.width/2 - shot.width/2  
    shot.y = player.y - shot.height             
    shots.append(shot)
    return shots

def criaMatriz(matriz):
    yInicial = 100
    for i in range(config.linhaEnemy):
        distanciaX = 0
        xInicial = 200
        linha = []
        for j in range (config.colunaEnemy):
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
                            s.move_y(speedY)
                            if (s.y > spaceship.y - s.height):
                                gameover()
    return speedX

def tiroMonstro(matrizEnemy):
    x = random.randint(0,config.linhaEnemy-1)
    y = random.randint(0,config.colunaEnemy-1)
    while (matrizEnemy[x][y]):
        x = random.randint(0,config.linhaEnemy-1)
        y = random.randint(0,config.colunaEnemy-1)
    shots = []
    shot = Sprite("images/shotE.png")
    shot.x = matrizEnemy[x][y].x + matrizEnemy[x][y].width/2 - shot.width/2  
    shot.y = matrizEnemy[x][y].y + matrizEnemy[x][y].height   
    shots.append(shot)
    shot.draw()
    return shots
        
    


def gameover():
    janela = Window(1200, 744)
    teclado = Window.get_keyboard()

    while True:
        janela.draw_text("GAME-OVER", 415, janela.height/2, size=70, color=(255,0,0), font_name="Arial", bold=False, italic=False)
        if (teclado.key_pressed("esc")):
            janela.close()

        janela.update()
