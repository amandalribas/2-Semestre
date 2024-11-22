from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import menu

def posInicialTiro(player,shots):
    shot = Sprite("images/shot.png")
    shot.x = player.x + player.width/2 - shot.width/2  
    shot.y = player.y - shot.height             
    shots.append(shot)
    return shots

def game(dif = 1):
    janela = Window(1200, 844)
    teclado = Window.get_keyboard()
    player = Sprite("images/player.png")
    player.x = (janela.width)/2 - player.width/2
    player.y = 744
    vel = 500
    shots = []
    tiros = 0
    while True:
        janela.set_background_color([0,0,0])

        #movendo player
        if (teclado.key_pressed("right") and player.x <= (janela.width - player.width)) or (teclado.key_pressed("left") and player.x >= 0):
            player.move_key_x(vel * janela.delta_time())

        #tiros do player c/ delay
        if tiros >1: 
            if (teclado.key_pressed("space")) and shots[tiros-1].y < 500:
                shots = posInicialTiro(player,shots)
                tiros += 1
        else: #se eh o primeiro, nao precisa de delay
            if (teclado.key_pressed("space")):
                shots = posInicialTiro(player,shots)
                tiros += 1
    
        if len(shots) > 0:
            for balas in shots:
                balas.draw()
                if balas.y > 0:
                    balas.y -= vel * janela.delta_time()
                if balas.y == 0:
                    shots.remove(balas)
                    tiros -= 1
       #volta pro menu         
        if (teclado.key_pressed("esc")):
            menu.menu()
        player.draw()
        janela.update()

