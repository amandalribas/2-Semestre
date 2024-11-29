from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import menu

lMonstro = 3
cMonstro = 7
velEnemy = 500
def posInicialTiro(player,shots):
    shot = Sprite("images/shot.png")
    shot.x = player.x + player.width/2 - shot.width/2  
    shot.y = player.y - shot.height             
    shots.append(shot)
    return shots

def criaMatriz(matriz):
    yInicial = 100
    for i in range(lMonstro):
        distanciaX = 0
        xInicial = 200
        linha = []
        for j in range (cMonstro):
            enemy = Sprite("images/enemy1.png")
            enemy.x = xInicial + distanciaX
            enemy.y = yInicial + i*150
            distanciaX += enemy.width + enemy.width/2
            linha.append(enemy)
        matriz.append(linha)
    return matriz

def desenhaMatriz(matriz):
    for linha in matriz:
        for sprite in linha:
            sprite.draw()

def updateMonstro(matriz, janela, velocidade):
    bateu = False
    vel = velocidade * janela.delta_time()

    # Verificar colisões e mover os sprites
    for linha in matriz:
        for sprite in linha:
            sprite.x -= (velocidade * janela.delta_time())  # Aplica o movimento
            if (sprite.x < 10):
                sprite.x = 10
                bateu = True
            elif (sprite.x >= janela.width - sprite.width - sprite.width/2):
                sprite.x = janela.width - sprite.width - sprite.width/2
                bateu = True

    # Inverter direção se necessário
    if bateu:
        velocidade *= -1
        for linha in matriz:
            for sprite in linha:
                sprite.x -= (velocidade * janela.delta_time())              

def game(dif = 1):
    janela = Window(1200, 744)
    teclado = Window.get_keyboard()
    player = Sprite("images/player.png")
    player.x = (janela.width)/2 - player.width/2
    player.y = 644
    vel = 500
    shots = []
    enemys = []
    contaTiros = 0
    enemys = criaMatriz(enemys)
    while True:
        janela.set_background_color([0,0,0])


        #movendo player
        if (teclado.key_pressed("right") and player.x <= (janela.width - player.width)) or (teclado.key_pressed("left") and player.x >= 0):
            player.move_key_x(vel * janela.delta_time())

        #tiros do player c/ delay
        if contaTiros >1: 
            if (teclado.key_pressed("space")) and shots[contaTiros-1].y < 500:
                shots = posInicialTiro(player,shots)
                contaTiros += 1
        else: #se eh o primeiro, nao precisa de delay
            if (teclado.key_pressed("space")):
                shots = posInicialTiro(player,shots)
                contaTiros += 1
    
        if len(shots) > 0: #se atirou
            for bala in shots:
                bala.draw()
                if bala.y > 0:
                    bala.y -= vel * janela.delta_time()
                if bala.y < 10:
                    shots.remove(bala)
                    contaTiros -= 1

       #volta pro menu         
        if (teclado.key_pressed("esc")):
            menu.menu()
        updateMonstro(enemys,janela,velEnemy)        
        desenhaMatriz(enemys)
        player.draw()
        janela.update()

game()
