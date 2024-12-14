from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
from PPlay.collision import *
import menu
import enemy 
import config



def main(dif = config.dificuldade):
    
    janela = Window(1200, 744)
    teclado = Window.get_keyboard()
    player = Sprite("images/player.png")
    player.x = (janela.width)/2 - player.width/2
    player.y = 644
    vel = 500
    velTEnemy = 300
    shots = []

    #enemys = []
    contaTiros = 0
    #enemys = enemy.criaMatriz(enemys)
    config.matrizEnemy = enemy.criaMatriz(config.matrizEnemy)
    velXEnemy = 500
    velYEnemy = 15
    #fps = 0
    FPS = 60
    clock = pygame.time.Clock()

    shotsEnemys = []

    while True:
        
        janela.set_background_color([0,0,0])    
        
        

        #fps na tela
        '''deltatime = janela.delta_time()
        if (janela.time_elapsed() % 100 == 0) and (deltatime!=0):
            fps = int(1 /deltatime)'''
        clock.tick(FPS)
        janela.draw_text(str(FPS),20,20,size=35, color=(255,255,255))

        #pontos na tela
        janela.draw_text(str(config.pontos),janela.width-80,20,size=35, color=(255,255,255))
        
        #vidas na tela:
        janela.draw_text(f"VIDAS: {str(config.vidas)}",janela.width/2 - 70 ,20,size=35, color=(255,255,255))


        #movendo player
        if (teclado.key_pressed("right") and player.x <= (janela.width - player.width)) or (teclado.key_pressed("left") and player.x >= 0):
            player.move_key_x(vel * janela.delta_time())

        #tiros do player c/ delay
        if contaTiros >1: 
            if (teclado.key_pressed("space")) and shots[contaTiros-1  ].y < 400:
                shots = enemy.posInicialTiro(player,shots)
                contaTiros += 1
        else: #se eh o primeiro, nao precisa de delay
            if (teclado.key_pressed("space")):
                shots = enemy.posInicialTiro(player,shots)
                contaTiros += 1
    
        enemy.desenhaMatriz(config.matrizEnemy)

        if len(shots) > 0: #se atirou
            for bala in shots:
                bala.draw()
                if bala.y > 0:
                    bala.y -= vel * janela.delta_time()
                if bala.y < 10:
                    shots.remove(bala)
                    contaTiros -= 1

        #enemy
        velXEnemy = enemy.updateMonstro(config.matrizEnemy,player,janela,velXEnemy,velYEnemy)   

        #Tiro Colidindo com o Enemy
        for bala in shots:
            for linha in config.matrizEnemy:
                for inimigo in linha:
                    if (Collision.collided_perfect(bala,inimigo)): 
                        linha.remove(inimigo)
                        shots.remove(bala)
                        contaTiros -= 1
                        config.pontos += 10   
   
                        
        #Tiro Enemy
        if (len(shotsEnemys) ==0):
            shotsEnemys = enemy.tiroMonstro(config.matrizEnemy)
        else:
            for shot in shotsEnemys:
                shot.y += velTEnemy * janela.delta_time()
                if (Collision.collided_perfect(shot,player)):
                    config.vidas -= 1
                    shotsEnemys.remove(shot)
                elif shot.y > player.y:
                    shotsEnemys.remove(shot)
                shot.draw()



       #volta pro menu         
        if (teclado.key_pressed("esc")):
            menu.menu()

        player.draw()
        janela.update()

main()