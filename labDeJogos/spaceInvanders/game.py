from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import menu
import enemy 


def posInicialTiro(player,shots):
    shot = Sprite("images/shot.png")
    shot.x = player.x + player.width/2 - shot.width/2  
    shot.y = player.y - shot.height             
    shots.append(shot)
    return shots


def game(dif = 1):
    
    janela = Window(1200, 744)
    teclado = Window.get_keyboard()
    player = Sprite("images/player.png")
    player.x = (janela.width)/2 - player.width/2
    player.y = 644
    vel = 500
    shots = []
    lMonstro = 3
    cMonstro = 7
    enemys = []
    contaTiros = 0
    enemys = enemy.criaMatriz(enemys,lMonstro,cMonstro)
    velXEnemy = 500
    velYEnemy = 5
    fps = 0
    while True:
        
        janela.set_background_color([0,0,0])            
        
        deltatime = janela.delta_time()
        if (janela.time_elapsed() % 100 == 0) and (deltatime!=0):
            fps = int(1 /deltatime)
        janela.draw_text(str(fps),20,20,size=35, color=(255,255,255))

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
        
        #enemy
        enemy.desenhaMatriz(enemys)
        velXEnemy = enemy.updateMonstro(enemys,player,janela,velXEnemy,velYEnemy)   

       #volta pro menu         
        if (teclado.key_pressed("esc")):
            menu.menu()
        
        player.draw()
        janela.update()

game()