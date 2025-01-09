from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
from PPlay.collision import *
import menu
import enemy 
import config
import utilidades



def limparMatriz(matriz):
    matriz = [linha for linha in matriz if len(linha) > 0]  
    return matriz

def main():
    
    janela = Window(1200, 744)
    teclado = Window.get_keyboard()
    player = Sprite("images/player.png")
    player.x = (janela.width)/2 - player.width/2
    player.y = 644
    vel = 1000
    velTEnemy = 300
    shots = []

    #enemys = []
    contaTiros = 0
    
    velXEnemy = 500
    velYEnemy = 15
    #fps = 0
    FPS = 60
    clock = pygame.time.Clock()
    shotsEnemys = []
    balasRemover = []
    player_invencivel = False  # Indica se o player está invencível
    tempo_invencibilidade = 2  # Duração da invencibilidade (2 segundos)

    
    if config.dificuldade == 2:
        config.colunaEnemy = 6
    elif config.dificuldade == 3:
        config.linhaEnemy = 4
        config.colunaEnemy = 6

    config.matrizEnemy.clear()
    config.matrizEnemy = limparMatriz(config.matrizEnemy)
    config.matrizEnemy = enemy.criaMatriz(config.matrizEnemy)
    #config.matrizEnemy = inicializar_jogo()

    colidiu = False
    inicio = False
    while True:
        if not(inicio):
            config.matrizEnemy.clear()
            config.matrizEnemy = limparMatriz(config.matrizEnemy)
            config.matrizEnemy = enemy.criaMatriz(config.matrizEnemy)
            inicio = True
        janela.set_background_color([0,0,0])    
        
        tempo_atual = pygame.time.get_ticks() / 1000

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

        #enemy
        velXEnemy = enemy.updateMonstro(config.matrizEnemy,player,janela,velXEnemy,velYEnemy)   

        #Tiro Colidindo com o Enemy
        if not(colidiu):
            for bala in shots:
                for linha in config.matrizEnemy:
                    for inimigo in linha:
                        if (Collision.collided(bala,inimigo)):
                            balasRemover.append(bala)
                            linha.remove(inimigo)
                            config.pontos += 10
                            player_invencivel = True   
                            tempo_inicio_invencibilidade = pygame.time.get_ticks() / 1000
            
            for bala in balasRemover:
                if bala in shots:
                    shots.remove(bala)
                    contaTiros -= 1
        
            if len(shots) > 0: #se atirou
                for bala in shots:
                    bala.draw()
                    if bala.y > 0:
                        bala.y -= vel * janela.delta_time()
                    if bala.y < 10:
                        shots.remove(bala)
                        contaTiros -= 1

         #Tiro Enemy
        if not(colidiu):
            if (len(shotsEnemys) == 0):
                shotsEnemys = enemy.tiroMonstro(config.matrizEnemy,shotsEnemys)
            else:
                for shot in shotsEnemys:
                    shot.y += velTEnemy * janela.delta_time()
                    if (Collision.collided_perfect(shot,player)):
                        config.vidas -= 1
                        shotsEnemys.remove(shot)
                        colidiu = True
                        tempoPisca = janela.time_elapsed()
                        fimTempoPisca = tempoPisca + 1500
                        posX = player.x
                        posY = player.y
                    elif shot.y > player.y:
                        shotsEnemys.remove(shot)
                    shot.draw()
            for shot in shotsEnemys:
                shot.draw()
        #PISCANDO
        
        tempoPisca = janela.time_elapsed()
        #(tempoPisca)
        if colidiu:
            if tempoPisca % 5 == 0:
                player.set_position(-500,-500)
            else:
                player.set_position(posX,posY)
            if tempoPisca >= fimTempoPisca:
                colidiu = False

        #invencibilidade do player apos colisao com o tiro
        if player_invencivel and (tempo_atual - tempo_inicio_invencibilidade > tempo_invencibilidade):
            player_invencivel = False

       #volta pro menu         
        if (teclado.key_pressed("esc")):
            menu.main()
        if config.vidas == 0:
            utilidades.gameover()
        
        config.matrizEnemy = limparMatriz(config.matrizEnemy)
        if len(config.matrizEnemy) == 0:
            config.matrizEnemy.clear()
            config.matrizEnemy = limparMatriz(config.matrizEnemy)
            config.matrizEnemy = enemy.criaMatriz(config.matrizEnemy)
            velYEnemy += 1
            velXEnemy += 5
        player.draw()
        janela.update()
        
        

main()