from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import config
import random
import utilidades


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
            enemy.y = yInicial + i*(1.5) *enemy.height
            distanciaX += 30 + enemy.width + enemy.width/2
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
                                utilidades.gameover()
    return speedX

    
def tiroMonstro(matrizEnemy, shots):
    if not matrizEnemy:  # Verifica se ainda existe inimigo
        return shots
    
    # Sorteia uma linha que ainda tenha inimigos
    linhas_validas = [linha for linha in matrizEnemy if len(linha) > 0]
    if not linhas_validas:
        return shots

    linha = random.choice(linhas_validas)  # Escolhe uma linha aleatória com inimigos
    inimigo = random.choice(linha)  # Escolhe um inimigo da linha
    
    shot = Sprite("images/shotE.png")
    shot.x = inimigo.x + inimigo.width / 2 - shot.width / 2  
    shot.y = inimigo.y + inimigo.height   
    shots.append(shot)
    return shots
    


